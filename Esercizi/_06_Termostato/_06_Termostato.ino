const byte PIN_TERMORESISTENZA = A0;
const byte PIN_LED             = 13;
const int  SOGLIA              = 500;

void setup() {
  pinMode(PIN_TERMORESISTENZA, INPUT);
  pinMode(PIN_LED,             OUTPUT);
}

void loop() {
  int temperatura = analogRead(PIN_TERMORESISTENZA);

  if (temperatura > SOGLIA)
    // è caldo: accendo il "ventilatore"
    digitalWrite(PIN_LED, HIGH);
  else
    // è freddo: lo spengo
    digitalWrite(PIN_LED, LOW);
}
