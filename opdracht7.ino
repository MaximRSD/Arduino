#include <Servo.h>

const int trigPin = 12;          // Trigger pin
const int echoPin = 11;          // Echo Pin
const int servoPin  = 9;         // Servo Pin

Servo servo;                     

float time;                      // Variable tijdsduur
float distance;                  // Variable voor de afstand

int angle = 0;                   // Angle op 0 gezet

void setup(){
  Serial.begin(9600);            //Stel de seriele monitor in

  pinMode(trigPin, OUTPUT);      //Uitgang van trigPin gedefinieerd als OUTPUT
  pinMode(echoPin, INPUT);       //Uitgang van echoPin gedeinieerd als INPUT

  servo.attach(servoPin);        // Verbind de servo.attach aan de servoPin
 
}

void loop(){
  digitalWrite(trigPin, LOW);    // Trigpin op LOW
  delayMicroseconds(2);          // DelayMicro gezet op 2

  digitalWrite(trigPin, HIGH);   // TrigPin op HIGH
  delayMicroseconds(10);         // DelayMicro gezet op 10
  digitalWrite(trigPin, LOW);    // TrigPin op LOW gezet

  time = pulseIn(echoPin, HIGH); // Echopin op HIGH

  distance = time / 58;          // Bereking afstand en de snelheid van geluit
  Serial.print("Afstand: ");     // Print het woord afstand in de serial monitor
  Serial.print(distance);        // Toont de afstand op de seriele monitor
  Serial.println("cm");          // Print het woord cm in de serial monitor

  if(distance < 10 && distance >4) {        // Kijkt of distance lager is dan 10 en hoger is dan 4
    Serial.println("Kleiner dan 10");       // Print Kleiner dan 10 in de seriele monitor
  servo.write(0);                           // Servo draait naar 0 graden
  }if(distance < 4) {                       // Kijkt of distance lager is dan 4
    Serial.println("Kleiner dan 4");        // Print kleiner dan 4 in de seriele monitor
  servo.write(180);                         // Servo draait naar 180 graden
  }
  delay(100);                               // Geeft een kleine delay aan van 1/10 van een seconde
}
