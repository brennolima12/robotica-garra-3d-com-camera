#include "esp_camera.h"
#include <WiFi.h>

// ===================
// Select camera model
// ===================
#define CAMERA_MODEL_XIAO_ESP32S3 // Has PSRAM
#include "camera_pins.h"

// ===========================
// Configuração do ponto de acesso (AP)
// ===========================
const char *ssid = "XIAO_ESP32S3";   // Nome da rede Wi-Fi criada pela câmera
const char *password = "password";  // Senha da rede

void startCameraServer();
void setupLedFlash(int pin);

void setup() {
  Serial.begin(115200);
  Serial.setDebugOutput(true);
  Serial.println();

  // -------------------------
  // Configuração da câmera
  // -------------------------
  camera_config_t config;
  config.ledc_channel = LEDC_CHANNEL_0;
  config.ledc_timer = LEDC_TIMER_0;
  config.pin_d0 = Y2_GPIO_NUM;
  config.pin_d1 = Y3_GPIO_NUM;
  config.pin_d2 = Y4_GPIO_NUM;
  config.pin_d3 = Y5_GPIO_NUM;
  config.pin_d4 = Y6_GPIO_NUM;
  config.pin_d5 = Y7_GPIO_NUM;
  config.pin_d6 = Y8_GPIO_NUM;
  config.pin_d7 = Y9_GPIO_NUM;
  config.pin_xclk = XCLK_GPIO_NUM;
  config.pin_pclk = PCLK_GPIO_NUM;
  config.pin_vsync = VSYNC_GPIO_NUM;
  config.pin_href = HREF_GPIO_NUM;
  config.pin_sccb_sda = SIOD_GPIO_NUM;
  config.pin_sccb_scl = SIOC_GPIO_NUM;
  config.pin_pwdn = PWDN_GPIO_NUM;
  config.pin_reset = RESET_GPIO_NUM;
  config.xclk_freq_hz = 20000000;
  config.frame_size = FRAMESIZE_UXGA;
  config.pixel_format = PIXFORMAT_JPEG;  // para streaming
  //config.pixel_format = PIXFORMAT_RGB565; // para face detection/recognition
  config.grab_mode = CAMERA_GRAB_WHEN_EMPTY;
  config.fb_location = CAMERA_FB_IN_PSRAM;
  config.jpeg_quality = 12;
  config.fb_count = 1;

  // Se tiver PSRAM, melhora qualidade do JPEG e buffer
  if (config.pixel_format == PIXFORMAT_JPEG) {
    if (psramFound()) {
      config.jpeg_quality = 10;
      config.fb_count = 2;
      config.grab_mode = CAMERA_GRAB_LATEST;
    } else {
      // Sem PSRAM, reduz o frame
      config.frame_size = FRAMESIZE_SVGA;
      config.fb_location = CAMERA_FB_IN_DRAM;
    }
  } else {
    // Melhor opção para face detection/recognition
    config.frame_size = FRAMESIZE_240X240;
#if CONFIG_IDF_TARGET_ESP32S3
    config.fb_count = 2;
#endif
  }

#if defined(CAMERA_MODEL_ESP_EYE)
  pinMode(13, INPUT_PULLUP);
  pinMode(14, INPUT_PULLUP);
#endif

  // Inicializa câmera
  esp_err_t err = esp_camera_init(&config);
  if (err != ESP_OK) {
    Serial.printf("Camera init failed with error 0x%x", err);
    return;
  }

  sensor_t *s = esp_camera_sensor_get();
  // Ajustes de imagem se for OV3660
  if (s->id.PID == OV3660_PID) {
    s->set_vflip(s, 1);        // desvira
    s->set_brightness(s, 1);   // mais brilho
    s->set_saturation(s, -2);  // menos saturação
  }

  // Para streaming, usa QVGA inicialmente (mais FPS)
  if (config.pixel_format == PIXFORMAT_JPEG) {
    s->set_framesize(s, FRAMESIZE_QVGA);
  }

#if defined(CAMERA_MODEL_M5STACK_WIDE) || defined(CAMERA_MODEL_M5STACK_ESP32CAM)
  s->set_vflip(s, 1);
  s->set_hmirror(s, 1);
#endif

#if defined(CAMERA_MODEL_ESP32S3_EYE)
  s->set_vflip(s, 1);
#endif

  // LED flash, se existir
#if defined(LED_GPIO_NUM)
  setupLedFlash(LED_GPIO_NUM);
#endif

  // -------------------------
  // Wi-Fi em modo AP
  // -------------------------
  Serial.println("Configurando Access Point...");
  WiFi.mode(WIFI_AP);                        // força modo AP
  WiFi.softAP(ssid, password);              // cria o ponto de acesso
  WiFi.setSleep(false);                     // opcional: evita sleep de WiFi

  IPAddress myIP = WiFi.softAPIP();         // normalmente 192.168.4.1
  Serial.print("AP IP address: ");
  Serial.println(myIP);

  // Inicia servidor de câmera
  startCameraServer();

  Serial.println("Camera Server iniciado!");
  Serial.print("Conecte-se à rede Wi-Fi: ");
  Serial.println(ssid);
  Serial.print("Depois acesse: http://");
  Serial.print(myIP);
  Serial.println("/");
}

void loop() {
  // Nada aqui, o servidor de câmera roda em outra task
  delay(10000);
}
