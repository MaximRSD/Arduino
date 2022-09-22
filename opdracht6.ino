#include <Servo.h>

// constants won't change
const int BUTTON_PIN = 8; // Arduino pin connected to button's pin
const int SERVO_PIN  = 12; // Arduino pin connected to servo motor's pin
const int BUTTON_PIN1 = 4;
int pos = 0; 
Servo myservo;  // create servo object to control a servo

// variables will change:
int angle = 0;          // the current angle of servo motor
int lastButtonState;    // the previous state of button
int currentButtonState; // the current state of button
int currentButtonState1;
int lastButtonState1;

void setup() {
  Serial.begin(9600);               
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode (BUTTON_PIN1, INPUT_PULLUP);
  myservo.attach(SERVO_PIN); 
 
  myservo.write(angle);
  currentButtonState = digitalRead(BUTTON_PIN);
  currentButtonState1 = digitalRead(BUTTON_PIN1);
}

void loop() {
  delay(100);
  boolean button1 = false;
  boolean button2 = false;
  
  
  lastButtonState    = currentButtonState; 
  lastButtonState1 = currentButtonState1;
  currentButtonState = digitalRead(BUTTON_PIN); 
  currentButtonState1 = digitalRead(BUTTON_PIN1);
  if(lastButtonState == HIGH && currentButtonState == LOW){
  button1 = true;}
  
  if(lastButtonState1 == HIGH && currentButtonState1 == LOW){
    button2 = true;}
  
  if(button1 == true && button2 == false) {
    Serial.println("The button 1 is pressed");

   for (pos = 0; pos <= 120; pos += 1) { 
     myservo.write(pos); 
    delay(1000/ 120);
   }
   for (pos = 120; pos >= 0; pos -= 1) { 
    myservo.write(pos); 
    delay(1000/ 120);
   }

  }
  if(button2 == true && button1 == false) {
    Serial.println("The button 2 is pressed");
     for (pos = 0; pos <= 120; pos += 1) { 
       delay(500 / 120);
    myservo.write(pos); 
   }
     for (pos = 120; pos >= 0; pos -= 1) {
       delay(500 / 120);
        myservo.write(pos);         
    }
  }
  
  if(button1 == true && button2 == true) { 
    Serial.println("Both button is pressed");
     for (pos = 0; pos <= 120; pos += 1) { 
    myservo.write(pos);
    delay(1000/ 120);
     }
delay(2000);
    for (pos = 120; pos >= 0; pos -= 1) { 
      myservo.write(pos);
      delay(1000/ 120);
    }
  }
  
  
}
