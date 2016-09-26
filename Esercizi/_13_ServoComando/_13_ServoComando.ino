#include <Servo.h>

const byte PIN_SENSORE = A0;
Servo myservo;

void setup() {
  myservo.attach(9);
}

void loop() {
  int lettura = analogRead(PIN_SENSORE) * 180.0 / 1023.0;
  myservo.write(lettura);
  delay(10);
}
