#include <SevSeg.h>
const byte clockPIN = 9;
const byte latchPIN = 10;
const byte dataPIN  = 11;
SevSeg display(clockPIN, latchPIN, dataPIN, COMMON_CATHODE);

const byte PIN_PULSANTE = 2;
void setup() {
  pinMode(PIN_PULSANTE, INPUT);
}

void loop() {
  byte lettura = digitalRead(PIN_PULSANTE);

  if (lettura == HIGH && lettura_prec == LOW) {
    // Numero casuale fra 1 e 6
    byte casuale = random(1, 7);
    // Aggiorna display
    display.print(casuale);

    lettura_prec = lettura;
  }
  else if (lettura == LOW && lettura_prec == HIGH)
    lettura_prec = lettura;
}
