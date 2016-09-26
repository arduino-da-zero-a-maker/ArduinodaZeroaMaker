#include <SevSeg.h>
const byte clockPIN = 9;
const byte latchPIN = 10;
const byte dataPIN  = 11;
SevSeg display(clockPIN, latchPIN, dataPIN, COMMON_CATHODE);

const byte PIN_PULSANTE_UP    = 2;
const byte PIN_PULSANTE_DOWN  = 3;
const byte PIN_PULSANTE_RESET = 4;

byte lettura_prec_up;
byte lettura_prec_down;
byte lettura_prec_reset;

byte punteggio;

void setup() {
  pinMode(PIN_PULSANTE_UP,    INPUT);
  pinMode(PIN_PULSANTE_DOWN,  INPUT);
  pinMode(PIN_PULSANTE_RESET, INPUT);

  // letture fittizie per riempire le variabili "lettura precedente"
  lettura_prec_up    = digitalRead(PIN_PULSANTE_UP);
  lettura_prec_down  = digitalRead(PIN_PULSANTE_DOWN);
  lettura_prec_reset = digitalRead(PIN_PULSANTE_RESET);
}

void loop() {
  byte lettura = digitalRead(PIN_PULSANTE_UP);

  if (lettura == HIGH && lettura_prec_up == LOW) {
    if (punteggio < 9) {
      punteggio++;
      display.print(punteggio);
    }
  }
  else if (lettura == LOW && lettura_prec_up == HIGH)
    lettura_prec_up = lettura;

  lettura = digitalRead(PIN_PULSANTE_DOWN);

  if (lettura == HIGH && lettura_prec_down == LOW) {
    if (punteggio > 0) {
      punteggio--;
      display.print(punteggio);
    }
    lettura_prec_down = lettura;
  }
  else if (lettura == LOW && lettura_prec_down == HIGH)
    lettura_prec_down = lettura;

  lettura = digitalRead(PIN_PULSANTE_RESET);

  if (lettura == HIGH && lettura_prec_reset == LOW) {
    punteggio = 0;
    display.print(punteggio);
    lettura_prec_reset = lettura;
  }
  else if (lettura == LOW && lettura_prec_reset == HIGH)
    lettura_prec_reset = lettura;
}
