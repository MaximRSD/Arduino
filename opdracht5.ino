const int ledR = 11;        //LED rood op pin 11 gezet
const int ledG = 10;        //LED groen op pin 10 gezet
const int ledB = 9;         //LED blue op pin 9 gezet
const int boost = 10;       //boost de waarde 10 gegeven

void setup() {
    pinMode(ledR, OUTPUT);    //Uitgang van ledR gedefinieerd als OUTPUT
    pinMode(ledG, OUTPUT);    //Uitgang van ledG gedefinieerd als OUTPUT
    pinMode(ledB, OUTPUT);    //Uitgang van ledB gedefinieerd als OUTPUT
}

void loop() {
    for (int redValue = 0; redValue < 255; redValue++) {                  //Loop om door de kleuren heen te gaan
      //De loop telt het aantal bij R in rgb    
        analogWrite(ledR, redValue);
        redValue += boost;                                                //Kleur plus boost, zodat het sneller van kleuren verandert.
        delay(100);                                                       //delay gesteld van 1/10 seconden
        for (int greenValue = 0; greenValue < 255; greenValue++) {        //Loop om door de kleuren heen te gaan
            analogWrite(ledG, greenValue);
            greenValue += boost;                                          //Kleur plus boost, zodat het sneller van kleuren verandert.
            delay(100);                                                   //delay gesteld van 1/10 seconden
            for (int blueValue = 0; blueValue < 255; blueValue++) {       //Loop om door de kleuren heen te gaan
                analogWrite(ledB, blueValue);                     
                blueValue += boost;                                       //Kleur plus boost, zodat het sneller van kleuren verandert.
                delay(100);                                               //delay gesteld van 1/10 seconden
            }
        }
    }
}
  
