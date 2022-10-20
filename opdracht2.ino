const int buttonPin = 7;                         //Buttonpin op pin 7 gezet
const int ledPin = 11;                           //ledPin op pin 11 gezet
int buttonState = 0;                             //Buttonstate 0 waarde gegeven
int counter = 1;                                 //counter 1 waarde gegeven
int lastButtonState = 0;                         //lastButtonState 0 waarde gegeven

void setup() {
  pinMode(buttonPin, INPUT);                     //Uitgang van buttonPin gedefineerd als INPUT
  pinMode(ledPin, OUTPUT);                       //Uitgang van ledPin gedefineerd als OUTPUT
}

void loop() { 
  buttonState = digitalRead(buttonPin);             //Leest de waarde van buttonPin bij buttonState
  //Buttonstate verandert als je erop drukt.
  if (buttonState != lastButtonState) {
    if (buttonState == HIGH) {
      counter++;                                    //telt op wanneer er gedrukt is (Voor state)
    }
    delay(100);                                     //delay van 1/10 seconden
  }
  lastButtonState = buttonState;
  if (counter >= 2) {                               //Als counter hoger of gelijk is dan is de ledpin aan                       
    digitalWrite(ledPin, HIGH);                     //Ledpin aan
    counter = 0;
  }
  else if (counter == 1){                           //Als counter gelijk is aan 1 dan gaat de led uit.
    digitalWrite(ledPin, LOW);                      //Ledpin uit
  }
}
