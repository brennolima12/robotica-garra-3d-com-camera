#include <Servo.h>

int botao_garra = 0;

int botao_serra = 0; 

bool estado_garra = false; 
bool estado_serra = false; 

Servo servo_garra; 
Servo servo_serra;

void setup()
{
  pinMode(11, INPUT);
  pinMode(10, INPUT);
  servo_garra.attach(13, 500, 2500);
  servo_serra.attach(12, 500, 2500); 
  servo_garra.write(0); 
}

void loop()
{
  botao_garra = digitalRead(11); 
  botao_serra = digitalRead(10);
  if (botao_garra == HIGH) { 
    estado_garra = !estado_garra; 

    if (estado_garra == true) {
      servo_garra.write(90); 
    } else { 
      servo_garra.write(0); 
      servo_serra.write(90); 
      estado_serra = false; 
    }
  }
  if (botao_serra == HIGH && estado_garra == true) { 
    if (estado_serra == true) {
      servo_serra.write(180); 
      fecharSuave(90, 135); 
    } else { 
      servo_serra.write(90); 
      servo_garra.write(90); 
    }
  }
}

void fecharSuave(int inicio, int fim) {
  for (int pos = inicio; pos <= fim; pos++) { 
    servo_garra.write(pos); 
    delay(50); 
  }
}