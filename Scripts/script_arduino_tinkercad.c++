#include <Servo.h>

int botaoGarra = 0;
int botaoSerra = 0;

int pinBotaoGarra = 9;
int pinBotaoSerra = 8;
int pinGarra = 7;
int pinSerra = 6;

int posInicial = 120;
int posFechada = 95;

bool estadoGarra = false;
bool estadoSerra = false;

Servo servoGarra;
Servo servoSerra;

void setup()
{
  Serial.begin(9600);
  Serial.println("COMECOU");

  pinMode(pinBotaoGarra, INPUT);
  pinMode(pinBotaoSerra, INPUT);

  pinMode(pinGarra, OUTPUT);
  pinMode(pinSerra, OUTPUT);

  servoGarra.attach(pinGarra, -2500, -1500);
  // servoSerra.attach(pinSerra);

  girarServo(posInicial, servoGarra);
}

void loop()
{
  pinMode(13, OUTPUT);

  botaoGarra = digitalRead(pinBotaoGarra);
  botaoSerra = digitalRead(pinBotaoSerra);

  if (botaoGarra == HIGH) {
    delay(1000);

    Serial.println("LED GARRA");
    digitalWrite(13, HIGH);

    if (estadoGarra == false) {
      Serial.println("FECHANDO A GARRA");

      girarServo(posFechada, servoGarra);

      estadoGarra = true;
    } else {
      Serial.println("ABRINDO A GARRA");
      // Serial.println("PARANDO A SERRA");
      girarServo(posInicial, servoGarra);

      delay(100);
    //   servoSerra.write(90);
      estadoSerra = false;
      estadoGarra = false;
    }
  }


    delay(1000);

    Serial.println("LED SERRA");

    digitalWrite(13, LOW);

    estadoSerra = !estadoSerra;

    if (estadoSerra == true) {
      Serial.println("GIRANDO A SERRA");
      // servoSerra.write(180);
      fecharSuave(posFechada, posFechada - 5);
    } else {
      Serial.println("PARANDO A SERRA");
      // servoSerra.write(90);
      girarServo(posFechada, servoGarra);
    }
  }
}

void fecharSuave(int inicio, int fim) {
  Serial.println("FECHANDO A GARRA SUAVEMENTE");
  for (int pos = inicio; pos >= fim; pos--) {
    servoGarra.write(pos);
    delay(50);
  }
}

void girarServo(int pos, Servo &servo) {
  delay(100);

  servo.write(pos);
}
