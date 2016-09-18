
const byte BUTTON_NUMBER            = 4;
const byte LEDPIN[BUTTON_NUMBER]    = {10, 11, 12, 13};
const byte BUTTONPIN[BUTTON_NUMBER] = {2, 3, 4, 5};

const byte MAXLEVEL                 = 100;
byte livello                        = 1;
byte numeriCasuali[MAXLEVEL];

const byte pausaON  = 500;
const byte pausaOFF = 100;

void setup() {
  // Si impostano i pin in output/input
  for (byte c = 0; c < BUTTON_NUMBER; c++) {
    pinMode(LEDPIN[c], OUTPUT);
    pinMode(BUTTONPIN[c], INPUT_PULLUP);
  }
  // Si avvia la generazione di numeri casuali
  randomSeed(analogRead(A0));
  // Numero casuale fra 0 e 3: si inserisce il primo numero
  numeriCasuali[0] = random(0, 4);
}

void loop() {
  // Accende la sequenza casuale di LED
  for (byte c = 0; c < livello; c++) {
    digitalWrite(LEDPIN[numeriCasuali[c]], HIGH);
    delay(pausaON);
    digitalWrite(LEDPIN[numeriCasuali[c]], LOW);
    delay(pausaOFF);
  }

  // Inserimento dei codici con i bottoni
  byte numeriInseriti = 0;

  // Ad ogni livello devo inserire un pari numero di codici (livello 1 --> 1, livello 2 --> 2...)
  while (numeriInseriti < livello) {
    // Bisogna scansionare tutti e quattro i bottoni: ciclo for
    for (byte bottone = 0; bottone < BUTTON_NUMBER; bottone++) {
      byte lettura = digitalRead(BUTTONPIN[bottone]);

      // Se il bottone Ã¨ premuto...
      if (lettura == LOW) {
        // intanto aspetto che venga rilasciato
        while (digitalRead(BUTTONPIN[bottone]) == LOW);
        delay (10); // piccola pausa anti-bouncing

        // Se il numero casuale che devo inserire è proprio corrispondente al bottone premuto...
        if (numeriCasuali[numeriInseriti] == bottone) {
          // ... allora passo a inserire il successivo codice
          numeriInseriti++;
          break;  // esce dal ciclo for e ricomincia il while
        }
        // altrimenti, se il codice è sbagliato...
        else {
          // riparto dal livello 1
          livello = 1;
          numeriCasuali[0] = random(0, 4);
          return; // interrompe la loop corrente e la ricomincia daccapo
        }
      }
    }
  }
  // se sono uscito vivo dal while, passo al livello successivo
  numeriCasuali[livello] = random(0, 4);
  livello++;  
}
