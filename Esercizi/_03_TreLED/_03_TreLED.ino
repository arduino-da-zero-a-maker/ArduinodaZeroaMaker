const byte PRIMO_PULSANTE  = 2;
const byte ULTIMO_PULSANTE = 4;
const byte PRIMO_LED       = 11;

byte led_attuale           = PRIMO_PULSANTE;
byte pulsante_attuale      = PRIMO_LED;

void setup() {
    
}

void loop() {
  // L'ultimo pulsante è collegato al pin 4!
  if (pulsante_attuale > ULTIMO_PULSANTE) {
    // Ricomincia dal primo pulsante
    pulsante_attuale = PRIMO_PULSANTE;
    led_attuale = PRIMO_LED;
  }
  
  // Copia lo stato del bottone sul LED
  digitalWrite(led_attuale, digitalRead(pulsante_attuale));

  // Passa a pulsante e LED successivi
  pulsante_attuale++;
  led_attuale++;
  delay(10);
}
