
#include <LiquidCrystal.h>
LiquidCrystal lcd(2,3,4,5,6,7);

// Connessioni
const byte PIN_SENSORE     = A0;
const byte PIN_BOTTONEUP   = 11;
const byte PIN_BOTTONEDOWN = 10;
const byte PIN_ATTUATORE   = 9;

// Costanti utili
const float FONDOSCALA_POSITIVO = 35.0;
const float FONDOSCALA_NEGATIVO = 0;
const float SOGLIA_ISTERESI     = 0.5;

// Variabili di stato dei due bottoni
byte statoPrecedenteUp;
byte statoPrecedenteDown;

float temperaturaImpostata = 25.0;

// Contatore per valutare quanto
// tempo si preme uno dei pulsanti
unsigned long int timer = 0;

void setup() {
  pinMode(PIN_BOTTONEUP, INPUT_PULLUP);
  pinMode(PIN_BOTTONEDOWN, INPUT_PULLUP);
  pinMode(PIN_SENSORE, INPUT);
  pinMode(PIN_ATTUATORE, OUTPUT);
  
  statoPrecedenteUp   = digitalRead(PIN_BOTTONEUP);
  statoPrecedenteDown = digitalRead(PIN_BOTTONEDOWN);

  lcd.begin(16,2);
}

void loop() {
  // Lettura valore temperatura attuale
  float temperaturaLetta = analogRead(PIN_SENSORE) * 5.0/1024.0;
  
  // Lettura pulsanti e modifica temperatura
  // Pulsante up
  byte statoAttuale = digitalRead(PIN_BOTTONEUP);
  if ( statoPrecedenteUp == HIGH && statoAttuale == LOW ) {
    // Memorizzo quando è stato premuto
    timer = millis();
    statoPrecedenteUp = LOW;
  }
  else if ( statoAttuale == LOW && ( ( millis() - timer ) > 1000 ) ) {
    // Pulsante premuto a lungo! si incrementa
    if ( temperaturaImpostata < FONDOSCALA_POSITIVO )
      temperaturaImpostata = temperaturaImpostata + 0.1;
  }
  else if ( statoPrecedenteUp == LOW && statoAttuale == HIGH ) {
    // Pulsante rilasciato! un solo incremento
    if ( temperaturaImpostata < FONDOSCALA_POSITIVO )
      temperaturaImpostata = temperaturaImpostata + 0.1;
          
    statoPrecedenteUp = HIGH;
  }
  // Nota: gli incrementi vengono fatti solo se
  // la temperatura è inferiore al fondo scala

  // Pulsante down
  statoAttuale = digitalRead(PIN_BOTTONEDOWN);
  if ( statoPrecedenteDown == HIGH && statoAttuale == LOW ) {
    timer = millis();
    statoPrecedenteDown = LOW;
  }
  else if ( statoAttuale == LOW && ( ( millis() - timer ) > 1000 ) ) {
    // Nota: temperaturaImpostata = temperaturaImpostata - 0.1;
    if ( temperaturaImpostata > FONDOSCALA_NEGATIVO )
      temperaturaImpostata = temperaturaImpostata - 0.1;
  }
  else if ( statoPrecedenteDown == LOW && statoAttuale == HIGH ) {
    if ( temperaturaImpostata > FONDOSCALA_NEGATIVO )
      temperaturaImpostata = temperaturaImpostata - 0.1;
    
    statoPrecedenteDown = HIGH;
  }
  
  // Accensione/spegnimento ventilatore in funzione della temperatura
  
  // switch sul pin dell'attuatore, che può essere acceso (HIGH) o spento (LOW)
  byte statoVentilatore = digitalRead(PIN_ATTUATORE);
  
  if (statoVentilatore == LOW) {
    if ( temperaturaImpostata < temperaturaLetta ) {
      // Accensione del ventilatore
      digitalWrite(PIN_ATTUATORE, HIGH);
    }
  }
  else {
    if ( ( temperaturaImpostata - SOGLIA_ISTERESI) > temperaturaLetta ) {
      // Spegnimento del ventilatore
      digitalWrite(PIN_ATTUATORE, LOW);
    }
  }
  
  // Stampa interfaccia
  /* * * * * * * * *  * 
   * TEMP 28.72°      *
   * SET 21.2°  OFF *
   * * * * * * * * *  */ 
  
  lcd.clear();
  lcd.print("TEMP ");
  lcd.print(temperaturaLetta);
  lcd.print((char)223);    // simbolo °
  
  lcd.setCursor(0,1);
  lcd.print("SET ");
  lcd.print(temperaturaImpostata);
  lcd.print((char)223);    // simbolo °
  
  lcd.setCursor(11,1);
  if (digitalRead(PIN_ATTUATORE) == HIGH) {
      lcd.print("ON ");
      lcd.print((char)232);  // Simbolino OK 
  }
  else {
      lcd.print("OFF ");
      lcd.print("X");  // Simbolino NO
  }
  
  // Pausa lunga: quando si tiene premuto viene
  // incrementato di 0.1° ogni 100 millisecondi
  delay(100);
}
