const byte LED_ROSSO         = 9;
const byte LED_VERDE         = 10;
const byte LED_BLU           = 11;
                             
const byte PULSANTE_ROSSO    = 2;
const byte PULSANTE_VERDE    = 3;
const byte PULSANTE_BLU      = 4;

const byte PIN_POTENZIOMETRO = A0;

byte coloreSelezionato       = 0;

void setup() {
  pinMode(LED_ROSSO, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_BLU, OUTPUT);

  // Impostazioni di avvio: tutto spento
  digitalWrite(LED_ROSSO, 0);
  digitalWrite(LED_VERDE, 0);
  digitalWrite(LED_BLU,   0);
}

void loop() {
  if (digitalRead(PULSANTE_ROSSO) == HIGH)
    coloreSelezionato = 0;
  if (digitalRead(PULSANTE_VERDE) == HIGH)
    coloreSelezionato = 1;
  if (digitalRead(PULSANTE_BLU) == HIGH)
    coloreSelezionato = 2;

  int lettura = analogRead(PIN_POTENZIOMETRO);
  byte colore = lettura / 1023.0 * 255;
  
  if (coloreSelezionato == 0)
    analogWrite(LED_ROSSO, colore);
  else if (coloreSelezionato == 1)
    analogWrite(LED_VERDE, colore);
  else
    analogWrite(LED_BLU, colore);

  delay(10);
}
