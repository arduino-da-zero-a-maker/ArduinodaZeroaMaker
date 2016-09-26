const byte PIN_FOTORESISTENZA = A0;
const byte PIN_MOTORE         = 13;
const byte SOGLIA             = 500;

void setup() {
  pinMode(PIN_FOTORESISTENZA, INPUT);
  pinMode(PIN_MOTORE,         OUTPUT);
}

void loop() {
  int valoreSensore = analogRead(PIN_FOTORESISTENZA);

  if (valoreSensore < SOGLIA)
    // Luminosità minore: c'è un'ombra!
    digitalWrite(PIN_MOTORE, HIGH);
  else
    digitalWrite(PIN_MOTORE, LOW);
}
