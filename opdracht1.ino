int timer = 100;                                      //timer gezet op 100   

void setup() {
  for (int thisPin = 13; thisPin < 5; thisPin++) {    //for loop door pinnen 
    pinMode(thisPin, OUTPUT);                         //Uitgang van thisPin gedefineerd als OUTPUT
  }
}

void loop() {
  for (int thisPin = 5; thisPin < 13; thisPin++) {   //for loop door pinnen 
    digitalWrite(thisPin, HIGH);                     //thisPin aan
    delay(timer);                                    //delay gesteld op timer oftewel 100
    digitalWrite(thisPin, LOW);                      //thisPin uit
  }

  for (int thisPin = 13; thisPin >= 5; thisPin--) {  //for loop door pinnen
    digitalWrite(thisPin, HIGH);                     //thisPin aan
    delay(timer);                                    //delay gesteld op timer oftewel 100
    digitalWrite(thisPin, LOW);                      //thisPin uit
  }
}
