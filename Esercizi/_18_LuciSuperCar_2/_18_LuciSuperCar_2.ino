const byte NUMERODiLed = 5;
// Creo un array, ovvero un gruppo di variabili indicizzate
const byte LED[NUMERODiLed] = {13, 12, 11, 10, 9};

void setup() {
  // Ripete il blocco successivo NUMERODiLed volte
  for (byte count = 0; count < NUMERODiLed; count++) {
    // Tutti i LED in output, ogni volta richiamo
    // l'elemento count all'interno dell'array
    pinMode(LED[count], OUTPUT);
    // Tutti i LED spenti
    digitalWrite(LED[count], LOW);
  }
}

void loop() {
  // Accende i LED fino al penultimo: LED[3]
  for (byte count = 0; count < NUMERODiLed - 1; count++) {
    // Accendo il led numero count...
    digitalWrite(LED[count], HIGH);
    delay(500);
    // ... e lo spengo dopo mezzo secondo
    digitalWrite(LED[count], LOW);
  }

  // Accende i LED dall'ultimo al secondo: LED[1]
  for (byte count = NUMERODiLed - 1; count > 0; count--) {
    // Accendo il led numero count
    digitalWrite(LED[count], HIGH);
    delay(500);
    // ... e lo spengo dopo mezzo secondo
    digitalWrite(LED[count], LOW);
  }
}
