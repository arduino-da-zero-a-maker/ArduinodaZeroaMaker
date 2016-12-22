const byte PIN_TERMORESISTENZA = A0;
const byte PIN_POTENZIOMETRO   = A1;
const byte PIN_LED             = 13;

void setup() {
  pinMode(PIN_TERMORESISTENZA, INPUT);
  pinMode(PIN_POTENZIOMETRO,   INPUT);
  pinMode(PIN_LED,             OUTPUT);

  // In questo sketch si usa la trasmissione seriale
  Serial.begin(9600);
}

void loop() {
  int valorePotenziometro = analogRead(PIN_POTENZIOMETRO);

  // Un controllo sulla lettura: invia il dato al PC
  Serial.println(valorePotenziometro);

  int temperatura = analogRead(PIN_TERMORESISTENZA);
  
  if (temperatura > valorePotenziometro)
    // è caldo: accendo il "ventilatore"
    digitalWrite(PIN_LED, HIGH);
  else
    // è freddo: lo spengo
    digitalWrite(PIN_LED, LOW);
}
