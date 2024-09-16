#include <Servo.h>

const int BUTTON_PIN = 8;         // Button op pin 8 gezet
const int SERVO_PIN  = 12;        // Servo motor on pin 12 gezet
const int BUTTON_PIN1 = 4;        // Button 1 on pin 4 gezet
int pos = 0;                      // Position is gelijk aan 0
Servo myservo;                    // Servo object aangemaakt

int angle = 0;                    // Huidige angle servo motor
int lastButtonState;              // De vorige staat button
int currentButtonState;           // De huidige staat button
int currentButtonState1;          // De huidige staat button1
int lastButtonState1;             // De vorige staat button1

void setup() {
  Serial.begin(9600);                               // Stel de seriele monitor in
  pinMode(BUTTON_PIN, INPUT_PULLUP);                // Uitgang van Button Pin gedefinieerd als INPUT_PULLUP
  pinMode(BUTTON_PIN1, INPUT_PULLUP);               // Uitgang van Button Pin1 gedefinieerd als INPUT_PULLUP
  myservo.attach(SERVO_PIN);                        // Verbind de sero.attach aan de SERVO_PIN
  myservo.write(angle);                             // Draait de servo naar de angle
}

void loop() {
  delay(100);                                         // Delay van een 1/10 seconden
  boolean button = digitalRead(BUTTON_PIN) == LOW;    // Button op uit gezet
  boolean button1 = digitalRead(BUTTON_PIN1) == LOW;  // button1 op uit gezet
  
  if(button && !button1) {                            // Button is gedrukt en button1 niet
    Serial.println("The button is pressed");          // Print button is pressed
    
    while(digitalRead(BUTTON_PIN) == LOW && pos < 120) {  // while loop voor position. position start op 0 en kan maximaal tot een met 120 opgeteld worden
      pos += 1;                                           // angle gaat naar gewenste positie (120)
      myservo.write(pos);                                 // Servo Motor gaat naar positie
      delay(1000/120);                                    // Snelheid van servomotor 1s
    }
    
    while(digitalRead(BUTTON_PIN) == LOW && pos > 0) {    // while loop voor position. position staat op 120 en kan maximaal tot een met 0 afgeteld worden
      pos -= 1;                                           // angle gaat terug naar positie (0)
      myservo.write(pos);                                 // Servo Motor gaat naar positie
      delay(1000/120);                                    // Snelheid van servomotor 1s
    }
  }
  
  if(button1 && !button) {                                 // Button1 is gedrukt en button niet
    Serial.println("The button 2 is pressed");             // Print button1 is pressed
   
    while(digitalRead(BUTTON_PIN1) == LOW && pos < 120) {  // while loop voor position. position staat op 0 en kan maximaal tot en met 120 opgeteld worden
      pos += 1;                                            // angle gaat naar gewenste positie (120)
      myservo.write(pos);                                  // Servo Motor gaat naar positie
      delay(500/120);                                      // Snelheid van servomotor 0.5s
    }

    while(digitalRead(BUTTON_PIN1) == LOW && pos > 0) {    // while loop voor position. position staat op 120 en kan maximaal tot een met 0 afgeteld worden
      pos -= 1;                                            // angle gaat naar gewenste positie (0)
      myservo.write(pos);                                  // Servo Motor gaat naar positie
      delay(500/120);                                      // Snelheid van servomotor 0.5s
    }
  }

  if(button1 && button2) {                                                                    // Als beide buttons ingedrukt zijn
    Serial.println("Both buttons are pressed");                                               // Print als beide buttons ingedrukt zijn

    while(digitalRead(BUTTON_PIN) == LOW && digitalRead(BUTTON_PIN1) == LOW && pos < 120) {   // While loop voor als beide buttons ingedrukt zijn. position staat op 0 en kan maximaal tot en met 120 opgeteld worden
      pos += 1;                                                                               // angle gaat naar gewenste positie (120)
      myservo.write(pos);                                                                     // Servo Motor gaat naar positie
      delay(1000/120);                                                                        // Snelheid van servomotor 1s
    }
    delay(2000);                                                                              // Wacht 2 seconden
    while(digitalRead(BUTTON_PIN) == LOW && digitalRead(BUTTON_PIN1) == LOW && pos > 0) {     // Beweegt terug in while loop. position staat op 120 en kan maximaal tot en met 0 afgeteld worden
      pos -= 1;                                                                               // angle gaat naar gewenste positie (0)
      myservo.write(pos);                                                                     // Servo Motor gaat naar positie
      delay(1000/120);                                                                        // Snelheid van servomotor 1s
    }
  }
}
