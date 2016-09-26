const byte PIN_FOTORESISTENZA = A0;
const byte PIN_LED            = 13;
const byte SOGLIA_BASSA       = 350;
const byte SOGLIA_ALTA        = 750;

void setup() {
  pinMode(PIN_FOTORESISTENZA, INPUT);
  pinMode(PIN_LED,            OUTPUT);
}

void loop() {
  int valoreSensore = analogRead(PIN_FOTORESISTENZA);

  if (valoreSensore < SOGLIA_BASSA)
    digitalWrite(PIN_LED, HIGH);
  else if (valoreSensore > SOGLIA_ALTA)
    digitalWrite(PIN_LED, LOW);
}
