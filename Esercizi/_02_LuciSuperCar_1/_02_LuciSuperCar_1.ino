const byte PRIMO_LED     = 9;
const byte ULTIMO_LED    = 13;

byte direzione_crescente = true;
byte pin_led_attuale     = PRIMO_LED;

void setup() {
    pinMode(PRIMO_LED,   OUTPUT); //9
    pinMode(PRIMO_LED+1, OUTPUT); //10
    pinMode(PRIMO_LED+2, OUTPUT); //11
    pinMode(PRIMO_LED+3, OUTPUT); //12
    pinMode(PRIMO_LED+4, OUTPUT); //13
}

void loop() {
    delay(200);
    
    // Spengo il led attualmente acceso (led_attuale)
    digitalWrite(pin_led_attuale, LOW);
    
    // In base alla direzione, passo al LED precedente o successivo
    if (direzione_crescente == true)
        pin_led_attuale++;    
    if (direzione_crescente == false)
        pin_led_attuale--;
    
    // Se si è sforati in LED "più grandi"...
    if ( pin_led_attuale > ULTIMO_LED ) {
        // si ritorna al penultimo LED e si imposta una direzione decrescente
        pin_led_attuale = ULTIMO_LED-1;
        direzione_crescente = false;
    }
    
    // Se si è sforati in LED "più piccoli"...
    if ( pin_led_attuale < PRIMO_LED ) {
        // si ritorna al secondo LED e si imposta una direzione crescente
        pin_led_attuale = PRIMO_LED+1;
        direzione_crescente = true;
    }
    
    // Accendo definitivamente quello successivo
    digitalWrite(pin_led_attuale, HIGH);
}
