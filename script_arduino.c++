// C++ code
//
#include <Servo.h>

int botao_garra = 0; // define o pino do botão da garra

int botao_serra = 0; // define o pino do botão da serra

bool estado_garra = false; // define o estado da garra

bool estado_serra = false; // define o estado da serra

Servo servo_garra; // define o servo da garra
Servo servo_serra; // define o servo da serra

void setup()
{
  pinMode(11, INPUT); // define o pino do botão da garra como entrada
  pinMode(10, INPUT); // define o pino do botão da serra como entrada
  servo_garra.attach(13, 500, 2500); // define o servo da garra
  servo_serra.attach(12, 500, 2500); // define o servo da serra
  servo_garra.write(0); // coloca a garra na posição inicial
}

void loop()
{
  botao_garra = digitalRead(11); // lê o estado do botão da garra
  botao_serra = digitalRead(10); // lê o estado do botão da serra

  if (botao_garra == HIGH) { // se o botão da garra for pressionado
    estado_garra = !estado_garra; // inverte o estado da garra

    if (estado_garra == true) { // se a garra estiver aberta
      servo_garra.write(90); // abre a garra
    } else { // se a garra estiver fechada
      servo_garra.write(0); // fecha a garra
      servo_serra.write(90); // abre a serra
      estado_serra = false; // define o estado da serra como fechado
    }
  }
  if (botao_serra == HIGH && estado_garra == true) { // se o botão da serra for pressionado e a garra estiver aberta
    if (estado_serra == true) { // se a serra estiver aberta
      servo_serra.write(180); // gira a serra
      fecharSuave(90, 135); // fecha a garra suavemente para a serra pressionar o objeto
    } else { // se a serra estiver fechada
      servo_serra.write(90); // para a serra
      servo_garra.write(90); // volta a posição da garra fechada
    }
  }
}

void fecharSuave(int inicio, int fim) {
  for (int pos = inicio; pos <= fim; pos++) { // para cada posição entre a posição inicial e a posição final
    servo_garra.write(pos); // gira a garra para a posição desejada
    delay(50); // espera 50ms para a garra girar
  }
}