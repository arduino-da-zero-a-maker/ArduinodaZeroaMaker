const byte PIN_TERMORESISTENZA = A0;
const byte PIN_MOTORE          = 5;

void setup() {
  pinMode(PIN_TERMORESISTENZA, INPUT);
  pinMode(PIN_MOTORE, OUTPUT);
}

void loop() {
  int temperatura = 0;

  if (temperatura > 35) {
    temperatura = 35;
  }
  else if (temperatura < 10) {
    temperatura = 10;
  }

  byte velocita = (temperatura - 10) * 255.0 / (35.0 - 10.0);
  analogWrite(PIN_MOTORE, velocita);
  delay(10);
}
