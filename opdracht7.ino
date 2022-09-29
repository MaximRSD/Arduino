#include <Servo.h>

const int trigPin = 12; // Trigger pin
const int echoPin = 11; // Echo Pin
const int servoPin  = 9; // Servo Pin

Servo servo;

float time; // Variable tijdsduur
float distance; // Variable voor de afstand

int angle = 0;

void setup(){
  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  servo.attach(servoPin);
 
}

void loop(){
  digitalWrite(trigPin, LOW); // Trigpin op LOW
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH); // TrigPin op HIGH
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  time = pulseIn(echoPin, HIGH); // Echopin op HIGH

  distance = time / 58; // Bereking afstand en de snelheid van geluit
  Serial.print("Afstand: ");
  Serial.print(distance); // Toont de afstand op de seriele monitor
  Serial.println("cm");

  if(distance < 10 && distance >4) {
    Serial.println("Kleiner dan 10");
  servo.write(0);
  }if(distance < 4) {
    Serial.println("Kleiner dan 4");
  servo.write(180);
  }
  delay(100);
}
