const byte PIN_TERMORESISTENZA = A0;
const byte PIN_POTENZIOMETRO   = A1;
const byte PIN_LED             = 13;
const byte SOGLIA              = 500;

void setup() {
  pinMode(PIN_TERMORESISTENZA, INPUT);
  pinMode(PIN_POTENZIOMETRO,   INPUT);
  pinMode(PIN_LED,             OUTPUT);

  // In questo sketch si usa la trasmissione seriale
  Serial.begin(9600);
}

void loop() {
  // legge la soglia dal potenziometro e con una
  // proporzione riporta il valore su una scala di temperatura
  // da 18° a 30°
  int valorePotenziometro = analogRead(PIN_POTENZIOMETRO);
  int soglia = valorePotenziometro / 1024.0 * (30 - 18) + 18;
  
  // Un controllo sulla soglia: invia il dato al PC
  Serial.println(soglia);

  int temperatura = analogRead(PIN_TERMORESISTENZA);
  
  if (temperatura > soglia)
    // è caldo: accendo il "ventilatore"
    digitalWrite(PIN_LED, HIGH);
  else
    // è freddo: lo spengo
    digitalWrite(PIN_LED, LOW);
}
