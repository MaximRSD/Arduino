//elementen aangeven
const int ledGreen = 4;
const int ledYellow = 3;
const int ledRed = 2;
const int btnPin = 11;

int buttonState = 0;
//ints waarin random nummer wordt opgeslagen
int timeGreen;
int timeRed;

int ledStatus = 0;

unsigned long timer;
//bool of de knop is ingedrukt
bool isPressed = false;

void setup()
{
  //pinmodes instellen
  pinMode(btnPin, INPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(ledRed, OUTPUT);
  //serial aanzetten om println te lezen
  Serial.begin(9600);
}

void loop()
{
  // Controleer Bluetooth seriële data
  if (Serial.available() > 0) {
    char incomingChar = Serial.read();
    if (incomingChar == '0') {
      isPressed = !isPressed;
      timer = millis();
      Serial.print("Bluetooth toggled isPressed: ");
      Serial.println(isPressed);
    }
  }

  // Rest van je bestaande code hieronder...

  unsigned long timeNow = millis();
  buttonState = digitalRead(btnPin);

  // Houd fysieke knop toggle ook intact
  if(buttonState == HIGH)
  {
    if(isPressed == false)
    {
      isPressed = true;
      timer = millis();
    }
    else
    {
      isPressed = false;
      timer = millis();
    }
    Serial.println(isPressed);
  }

  if (isPressed == true)
  {
    Serial.println("in ispressed");
    timeGreen = random(8000,15000);
    timeRed = random(8000,15000);

    if(timeNow - timer <= timeGreen){
      Groen();
    } else if(timeNow - timer <= (timeGreen + 3000)){
      Geel();
    } else if(timer != 0 && timeNow - timer <= (timeGreen + 3000 + timeRed)){
      Rood();
    } else {
      Niks();
    }
  }
  else
  {
    if(timeNow - timer >= 1000){
      Serial.println("in else");
      timer = timeNow;
      ledStatus = (ledStatus == LOW) ? HIGH : LOW;
      digitalWrite(ledYellow, ledStatus);
    }
  }

  delay(300);
}

//lightjes aan en uit zetten
void Groen()
{
  digitalWrite(ledGreen, HIGH);
  digitalWrite(ledYellow, LOW);
  digitalWrite(ledRed, LOW);
}

void Geel()
{
  digitalWrite(ledGreen, LOW);
  digitalWrite(ledYellow, HIGH);
  digitalWrite(ledRed, LOW);
}

void Rood()
{
  digitalWrite(ledGreen, LOW);
  digitalWrite(ledYellow, LOW);
  digitalWrite(ledRed, HIGH);
}
void Niks()
{
  digitalWrite(ledGreen, LOW);
  digitalWrite(ledYellow, LOW);
  digitalWrite(ledRed, LOW);
}
  
