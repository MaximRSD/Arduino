#include <Servo.h>

const int BUTTON_PIN = 8;         // Button op pin 8 gezet
const int SERVO_PIN  = 12;        // servo motor op pin 12 gezet
const int BUTTON_PIN1 = 4;        // Button 1 op pin 4 gezet
int pos = 0;                      // Position is gelijk aan 0
Servo myservo;                    // servo object aangemaakt

int angle = 0;                    // Huidige angle servo motor
int lastButtonState;              // De vorige staat button
int currentButtonState;           // De huidige staat button
int currentButtonState1;          // De huidige staat button1
int lastButtonState1;             // De vorige staat button1

void setup() {
  Serial.begin(9600);                               //Stel de seriele monitor in
  pinMode(BUTTON_PIN, INPUT_PULLUP);                //Uitgang van Button Pin gedefinieerd als INPUT_PULLUP
  pinMode (BUTTON_PIN1, INPUT_PULLUP);              //Uitgang van Buttin Pin1 gedefinieerd als INPUT_PULLUP
  myservo.attach(SERVO_PIN);                        //Verbind de sero.attach aan de servo_pin
 
  myservo.write(angle);                             //draait de servo naar de angle
  currentButtonState = digitalRead(BUTTON_PIN);     //Leest de waarde van Button_pin
  currentButtonState1 = digitalRead(BUTTON_PIN1);   //Leest de waarde van Button_pin1
}

void loop() {
  delay(100);                                       //delay van een 1/10 seconden
  boolean button1 = false;                          //boolean gesteld op false bij button1
  boolean button2 = false;                          //boolean gesteld op false bij button2
  
  
  lastButtonState  = currentButtonState;                          //Lastbuttonstate is gelijk aan currentButtonstate  
  lastButtonState1 = currentButtonState1;                         //Lastbuttonstate1 is gelijk aan currentButtonstate1
  currentButtonState = digitalRead(BUTTON_PIN);                   //Leest de current state van button     
  currentButtonState1 = digitalRead(BUTTON_PIN1);                 //Leest de current state ban button1
  if(lastButtonState == HIGH && currentButtonState == LOW){       //Checkt of lastbuttonstate aan is en currentButtonstate uit is
  button1 = true;}                                                //button1 is op true gezet
  
  if(lastButtonState1 == HIGH && currentButtonState1 == LOW){     //Checkt of lastbuttonstate1 aan is en currentButtonstate1 uit is
    button2 = true;}                                              //button2 is op true gezet
  
  if(button1 == true && button2 == false) {                       //Als button1 true is een button2 false is dan start de functie binnen de statement
    Serial.println("The button 1 is pressed");                    //Print button 1 is pressed in de seriele monitor

   for (pos = 0; pos <= 120; pos += 1) {                          //for loop door positions. position start op 0 en kan maximaal tot 120 oplopen.
     myservo.write(pos);                                          //Servo draait naar de gewenste position
    delay(1000/ 120);                                             //delay 1 seconden gedeeld door 120
   }
   for (pos = 120; pos >= 0; pos -= 1) {                          //for loop voor position. position start op 120 en wordt maximaal tot 0 afgeteld
    myservo.write(pos);                                           //Servo draait naar de gewenste position
    delay(1000/ 120);                                             //delay 1 seconden gedeeld door 120
   }

  }
  if(button2 == true && button1 == false) {                       //Als button2 true is en button1 false is start de functie binnen de statement
    Serial.println("The button 2 is pressed");                    //Print the button2 is pressed in de seriele monitor
     for (pos = 0; pos <= 120; pos += 1) {                        //For loop voor position. position start op 0 en kan maximaal tot en met 120 opgeteld worden
       delay(500 / 120);                                          //Delay gesteld op halve seconde gedeeld door 120
    myservo.write(pos);                                           //Servo draait naar de gewenste positie
   }
     for (pos = 120; pos >= 0; pos -= 1) {                        //For loop voor position. position start op 120 en maximaal tot en met 0 afgeteld worden
       delay(500 / 120);                                          //Delay van halve seconden gedeeld door 120(pos)
        myservo.write(pos);                                       //Servo draait naar de gewenste positie
    }
  }
  
  if(button1 == true && button2 == true) {                        //Als button1 true is en button2 ook dan voert hij de functie
    Serial.println("Both button is pressed");                     //Print both button is pressed in de seriele monitor
     for (pos = 0; pos <= 120; pos += 1) {                        //For loop voor position. position start op 0 en kan maximaal 120 opgeteld worden
    myservo.write(pos);                                           //Servo draait naar gewenste positie
    delay(1000/ 120);                                             //Delay geteld op seconde gedeeld door 120
     }
delay(2000);                                                      //Delay gesteld van 2 seconden
    for (pos = 120; pos >= 0; pos -= 1) {                         //For loop voor position. position start op 120 en kan maximaal tot 0 worden afgeteld
      myservo.write(pos);                                         //Servo draait naar gewenste positie
      delay(1000/ 120);                                           //Delay gesteld op een 1 seconden gedeeld door 120
    }
  }
  
  
}
