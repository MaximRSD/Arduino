#include <SoftwareSerial.h>

// Bluetooth op pinnen 0 en 1
SoftwareSerial bluetooth(0, 1);

// LED-pinnen en variabelen
const int LED[] = {4, 3, 2};
unsigned long lastTime = 0;
unsigned long lastCheck = 0;
bool huidigeStaat = false;
int ledStatus = LOW;

void setup() {
  Serial.begin(9600); 
  bluetooth.begin(9600); 

  for (int i = 0; i < 3; i++) {
    pinMode(LED[i], OUTPUT);
  }
}

void loop() { 
  if (millis() - lastCheck > 100) {
    lastCheck = millis();
    if (bluetooth.available()) {
      int startsign = bluetooth.read();
      Serial.println(startsign);
      if (startsign == 75) {
        huidigeStaat = true;
        lastTime = millis();
      }
    }
  }
  if (huidigeStaat) {
    stopLicht();
  } else {
    storing();
  }
}

void storing() {
  if (millis() - lastTime >= 1000) {
    ledStatus = !ledStatus; // Toggle de LED status
    digitalWrite(LED[1], ledStatus);
    lastTime = millis();
  }
}

void stopLicht() {
  unsigned long elapsedTime = millis() - lastTime;
n
  if (elapsedTime <= 12000) {
    setLeds(LOW, LOW, HIGH); // Groen
  } else if (elapsedTime <= 18000) {
    setLeds(LOW, HIGH, LOW); // Oranje
  } else if (elapsedTime <= 30000) {
    setLeds(HIGH, LOW, LOW); // Rood
  } else {
    setLeds(LOW, LOW, LOW); // Reset
    huidigeStaat = false;
  }
}

void setLeds(int rood, int oranje, int groen) {
  digitalWrite(LED[0], rood);
  digitalWrite(LED[1], oranje);
  digitalWrite(LED[2], groen);
}

