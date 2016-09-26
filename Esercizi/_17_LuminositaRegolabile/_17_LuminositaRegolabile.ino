#include <LiquidCrystal.h>
// Pin display:   EN RS D4 D5 D6 D7
LiquidCrystal lcd(12,11, 5, 4, 3, 2);

const byte PIN_POTENZIOMETRO      = A0;
const byte PIN_RETROILLUMINAZIONE = 11;

void setup() {
  pinMode(PIN_POTENZIOMETRO,      INPUT);
  pinMode(PIN_RETROILLUMINAZIONE, OUTPUT);
}

void loop() {
  // legge il valore del sensore, e lo stampa
  int valoreSensore = analogRead(PIN_POTENZIOMETRO);
  byte valoreLuminosita = map(valoreSensore, 0, 1023, 0, 255);
  byte percentuale = map(valoreSensore, 0, 1023, 0, 100);

  analogWrite(PIN_RETROILLUMINAZIONE, valoreLuminosita);

  lcd.setCursor(0, 1);
  lcd.print("                ");
  lcd.setCursor(0, 1);
  lcd.print(percentuale);
  lcd.print("%");
}
