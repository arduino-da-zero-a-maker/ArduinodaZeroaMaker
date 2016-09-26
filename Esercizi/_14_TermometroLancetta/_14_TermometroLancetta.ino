#include <Servo.h>

const byte PIN_LM35 = A0;
const byte FONDOSCALA  = 40;
Servo myservo;

void setup() {
  myservo.attach(9);
}

void loop() {
  // Lettura della temperatura dal sensore LM35
  // 10mV = 1°C
  float tensione;
  tensione = analogRead(PIN_LM35) * 5.0 / 1023.0;
  float temperatura;
  temperatura = tensione / 0.01;

  // Se la temperatura è troppo alta la lancetta si blocca
  // sul fondo basso o alto
  if (temperatura > FONDOSCALA)
    temperatura = FONDOSCALA;
  else if (temperatura < 0)
    temperatura = 0;

  // Converte la temperatura in un angolo per il motore
  byte posizione = temperatura * 180 / FONDOSCALA;

  myservo.write(posizione);

  delay(10);
}
