const byte PIN_LM35  = A0;

const byte PIN_MOTORE = 5;

const float TEMPERATURA_FONDOSCALA = 35;
const float TEMPERATURA_MINIMA     = 10;

void setup() {
  pinMode(PIN_LM35,   INPUT);
  pinMode(PIN_MOTORE, OUTPUT);
}

void loop() {
  int   lettura     = analogRead(PIN_LM35);
  float tensione    = lettura * 5.0 / 1023.0;
  float temperatura = tensione / 0.01;  // 10mV = 1°C

  // Si imposta un range finito di temperature
  if (temperatura > TEMPERATURA_FONDOSCALA) {
    temperatura = TEMPERATURA_FONDOSCALA;
  }
  else if (temperatura < TEMPERATURA_MINIMA) {
    temperatura = TEMPERATURA_MINIMA;
  }

  // temperatura = 10 --> PWM = 0
  // temperatura = 35 --> PWM = 255
  // Valori intermedi proporzionali
  byte velocita = (temperatura - TEMPERATURA_MINIMA) * 255.0 / (TEMPERATURA_FONDOSCALA - TEMPERATURA_MINIMA);
  analogWrite(PIN_MOTORE, velocita);
  delay(10);
}
