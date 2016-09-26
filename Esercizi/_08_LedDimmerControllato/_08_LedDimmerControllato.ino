const byte PIN_POTENZIOMETRO = A0;
const byte PIN_LED           = 9;

void setup() {
  pinMode(PIN_POTENZIOMETRO, INPUT);
  pinMode(PIN_LED,           OUTPUT);
}

void loop() {
  int valorePotenziometro = analogRead(PIN_POTENZIOMETRO);
  byte valoreLED = valorePotenziometro / 1023.0 * 255;

  // Imposta la luminosità del LED
  analogWrite(PIN_LED, valoreLED);
}
