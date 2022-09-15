const int ledR = 11;
const int ledG = 10;
const int ledB = 9;
const int boost = 10;

void setup() {
    pinMode(ledR, OUTPUT);
    pinMode(ledG, OUTPUT);
    pinMode(ledB, OUTPUT);
}

void loop() {
  //Loop om door de kleuren heen te gaan
    for (int redValue = 0; redValue < 255; redValue++) {
      //De loop telt het aantal bij R in rgb
        analogWrite(ledR, redValue);
        //Kleur plus boost, zodat het sneller van kleuren verandert.
        redValue += boost;
        delay(100);
        for (int greenValue = 0; greenValue < 255; greenValue++) {
            analogWrite(ledG, greenValue);
            greenValue += boost;
            delay(100);
            for (int blueValue = 0; blueValue < 255; blueValue++) {
                analogWrite(ledB, blueValue);
                blueValue += boost;
                delay(100);
            }
        }
    }
}
  
