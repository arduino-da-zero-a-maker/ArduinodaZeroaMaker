const byte PIN_ROSSO = 9;
const byte PIN_VERDE = 10;
const byte PIN_BLU = 11;

void setup() {
  pinMode(PIN_ROSSO, OUTPUT);
  pinMode(PIN_VERDE, OUTPUT);
  pinMode(PIN_BLU, OUTPUT);
  
  // Impostazioni di avvio: tutto spento
  digitalWrite(PIN_VERDE, 255);
  digitalWrite(PIN_BLU, 255);
  
  // accendo Rosso
  for (int c = 0; c <= 255; c++) {
    digitalWrite(PIN_ROSSO, 255 - c);
    delay(10);
  }
}

void loop() {

  // accendo Verde
  for (int c = 0; c <= 255; c++) {
    digitalWrite(PIN_VERDE, 255 - c);
    delay(10);
  }
  
  // spengo Rosso
  for (int c = 255; c >= 0; c--) {
    // Va da 1 a 255
    digitalWrite(PIN_ROSSO, 255 - c);
    delay(10);
  }
  
  // accendo Blu
  for (int c = 0; c <= 255; c++) {
    digitalWrite(PIN_BLU, 255 - c);
    delay(10);
  }
  
  // spengo Verde
  for (int c = 255; c >= 0; c--) {
    digitalWrite(PIN_VERDE, 255 - c);
    delay(10);
  }
  
  // accendo Rosso
  for (int c = 0; c <= 255; c++) {
    digitalWrite(PIN_ROSSO, 255 - c);
    delay(10);
  }
  
  // spengo Blu
  for (int c = 255; c >= 0; c--) {
    digitalWrite(PIN_BLU, 255 - c);
    delay(10);
  }  
}
