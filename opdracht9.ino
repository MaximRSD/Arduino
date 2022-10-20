const int buttonPin = 0;          //Knop op pin 0 gezet
int GREEN = 5;                    //LED groen op pin 5 gezet
int YELLOW = 6;                   //LED geel op pin 6 gezet
int RED = 7;                      //LED rood op pin 7 gezet
int buttonState = 0;              //Status van de knop op 0 gezet
bool isPressed = false;           //isPressed false gezet


// basic functions
void setup()
{
  Serial.begin(9600);             //Stel de seriele monitor in
  pinMode(GREEN, OUTPUT);         //Uitgang van Pin gedefinieerd als OUTPUT
  pinMode(YELLOW, OUTPUT);        //Uitgang van Pin gedefinieerd als OUTPUT
  pinMode(RED, OUTPUT);           //Uitgang van Pin gedefinieerd als OUTPUT
  pinMode(buttonPin, INPUT);      //Uitgang van Pin gedefinieerd als OUTPUT
}

void loop()
{
  buttonState = digitalRead(buttonPin);       //Leest de value van de buttonPin als buttonstate
  if(buttonState == LOW){isPressed = true;}   //Als buttonState LOW is dan wordt isPressed True
  if (isPressed == true){                     //Vergelijkt of isPressed true is
  lights();                                   //Start de functie lights();
  }else {
    digitalWrite(YELLOW, HIGH);               //Zet LED geel aan
    delay(500);                               //delay van een halve seconde
    digitalWrite(YELLOW, LOW);                //Zet LED geel uit
    delay(500);                               //delay van een halve seconde
  }
}

void lights()                                 //functie lights aangemaakt
{
  Serial.println(buttonState);                //Print de value van buttonState
  green_lights();                             //Start functie geen_lights()
  delay(random(8000, 15000));                 //Start een random delay tussne 8 en 15 seconden
  yellow_lights();                            //Start functie yellow_ligths()
  delay(3000);                                //Start een delay van 3 seconden
  red_lights();                               //Start functie red_lights()
  delay(random(8000, 15000));                 //Start een random delay tussen 8 en 15 seconden
}

void green_lights()                     //functie green_lihts aangemaakt
{
  digitalWrite(GREEN, HIGH);            //Zet LED groen aan
  digitalWrite(YELLOW, LOW);            //Zet LED geel uit
  digitalWrite(RED, LOW);               //Zet LED rood uit
}

void yellow_lights()                    //functie yellow_lights aangemaakt
{ 
  digitalWrite(GREEN, LOW);             //Zet LED groen uit
  digitalWrite(YELLOW, HIGH);           //Zet LED geel aan
  digitalWrite(RED, LOW);               //Zet LED rood uit
}

void red_lights()                       //functie red_lights aangemaakt
{
  digitalWrite(GREEN, LOW);             //Zet LED groen uit
  digitalWrite(YELLOW, LOW);            //zet LED geel uit
  digitalWrite(RED, HIGH);              //Zet LED rood aan
}
