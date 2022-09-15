const int buttonPin = 7;
const int ledPin = 11;
int buttonState = 0;
int counter = 1;
int lastButtonState = 0;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  //Buttonstate verandert als je erop drukt.
  if (buttonState != lastButtonState) {
    if (buttonState == HIGH) {
      //telt op wanneer er gedrukt is (Voor state)
      counter++;
    }
    delay(100);
  }
  lastButtonState = buttonState;
  //Als counter hoger of gelijk is dan is de ledpin aan
  if (counter >= 2) {
    digitalWrite(ledPin, HIGH);
    counter = 0;
  }
  //Als counter gelijk is aan 1 dan gaat de led uit.
  else if (counter == 1){
    digitalWrite(ledPin, LOW);
  }
}
