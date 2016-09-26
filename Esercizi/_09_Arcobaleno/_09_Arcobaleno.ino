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
  for (byte c = 0; c < 255; c++) {
    digitalWrite(PIN_ROSSO, 255 - c);
    delay(10);
  }
}

void loop() {

  // accendo Verde
  for (byte c = 0; c < 255; c++) {
    digitalWrite(PIN_VERDE, 255 - c);
    delay(10);
  }
  
  // spengo Rosso
  for (byte c = 0; c < 255; c++) {
    digitalWrite(PIN_ROSSO, c);
    delay(10);
  }
  
  // accendo Blu
  for (byte c = 0; c < 255; c++) {
    digitalWrite(PIN_BLU, 255 - c);
    delay(10);
  }
  
  // spengo Verde
  for (byte c = 0; c < 255; c++) {
    digitalWrite(PIN_VERDE, c);
    delay(10);
  }
  
  // accendo Rosso
  for (byte c = 0; c < 255; c++) {
    digitalWrite(PIN_ROSSO, 255 - c);
    delay(10);
  }
  
  // spengo Blu
  for (byte c = 0; c < 255; c++) {
    digitalWrite(PIN_BLU, c);
    delay(10);
  }  
}
