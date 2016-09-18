const byte PIN_ROSSO  = 9;
const byte PIN_VERDE  = 10;
const byte PIN_BLU    = 11;

void setup() {
    // Pin di controllo del LED: impostare in uscita
    pinMode(PIN_ROSSO, OUTPUT);
    pinMode(PIN_VERDE, OUTPUT);
    pinMode(PIN_BLU,   OUTPUT);
}

void loop() {
  // Accende e spegne il rosso
  digitalWrite(PIN_ROSSO, HIGH);
  delay(500);
  digitalWrite(PIN_ROSSO, LOW);
  delay(500);

  // Accende e spegne il verde
  digitalWrite(PIN_VERDE, HIGH);
  delay(500);
  digitalWrite(PIN_VERDE, LOW);
  delay(500);

  // Accende e spegne il blu
  digitalWrite(PIN_BLU, HIGH);
  delay(500);
  digitalWrite(PIN_BLU, LOW);
  delay(500);
    
}
