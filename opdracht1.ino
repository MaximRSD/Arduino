int timer = 100;           

void setup() {


  for (int thisPin = 13; thisPin < 5; thisPin++) {

    pinMode(thisPin, OUTPUT);

  }
}

void loop() {


  for (int thisPin = 5; thisPin < 13; thisPin++) {


    digitalWrite(thisPin, HIGH);

    delay(timer);
 

    digitalWrite(thisPin, LOW);

  }



  for (int thisPin = 13; thisPin >= 5; thisPin--) {

    digitalWrite(thisPin, HIGH);

    delay(timer);

    digitalWrite(thisPin, LOW);

  }
}
