#include <Servo.h>

const byte  PIN_TERMORESISTENZA = A0;
const float RESISTENZAFISSA    = 10.0; 
const float Bcoeff             = 3435;
const float RESISTENZA25       = 10.0;

const byte FONDOSCALA          = 40;
Servo myservo;

void setup() {
  myservo.attach(9);
}

void loop() {
  int   lettura     = analogRead(PIN_TERMORESISTENZA);
  float resistenzaSensore = RESISTENZAFISSA / ( 1024.0 / lettura - 1 );
  float temperatura;
  
  temperatura = log(resistenzaSensore / RESISTENZA25);
  temperatura = temperatura / Bcoeff + 1/298.15;
  temperatura = 1/temperatura + 273.15;

  // Se la temperatura è troppo alta la lancetta si blocca
  // sul fondo basso o alto
  if (temperatura > FONDOSCALA)
    temperatura = FONDOSCALA;
  else if (temperatura < 0)
    temperatura = 0;

  // Converte la temperatura in un angolo per il motore
  // Attenzione alla divisione!
  byte posizione = temperatura * 180.0 / FONDOSCALA;

  myservo.write(posizione);

  delay(10);
}
