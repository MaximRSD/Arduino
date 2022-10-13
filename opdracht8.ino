#include <IRremote.h>

const int irPin = 8;                      //IR pin gezet op 8
int selectedLed = 0;                      //selectedLed staat op 0

const int ledPins[] = {7, 6, 5, 4};       //De LED pins
int ledStatus[] = {LOW, LOW, LOW, LOW};   //Status LED pins
int lastTimes[] = {0, 0, 0, 0};           //Check voor laatste knipper
int delays[] = {-1, 500, 500, -1};        //Delays zetten op LEDs



IRrecv irrecv(irPin);                     //Maak een nieuwe instantie van irrecv en sla deze op in de var IRrecv
decode_results results; ;                 //Definieer de var results om de ontvangen knop in op te slaan

void setup(){
  pinMode(ledPins[0], OUTPUT);            //Uitgang van Pin gedefinieerd als OUTPUT
  pinMode(ledPins[1], OUTPUT);            //Uitgang van Pin gedefinieerd als OUTPUT
  pinMode(ledPins[2], OUTPUT);            //Uitgang van Pin gedefinieerd als OUTPUT
  pinMode(ledPins[3], OUTPUT);            //Uitgang van Pin gedefinieerd als OUTPUT
  Serial.begin(9600);                     //Stel de seriele monitor in
  irrecv.enableIRIn();                    //Start de IR-ontvanger
}

void loop(){
  unsigned long currentTime = millis();             //variable met de huidige tijd in millis
  for(int x = 0; x <= 3; x++){                      //
    if(delays[x] != -1){                            //
      if(currentTime - lastTimes[x] >= delays[x]){  //Check of de huidige tijd - de laatste keer opgeslagen >= aan de voorgestelde knippertijd
        lastTimes[x] = currentTime;                 //Laatste keer vervangen door de huidge tijd
        if(ledStatus[x] = ledStatus[x] == LOW){     //Status van de LED veranderen, aan of uit
            ledStatus[x] == HIGH;                   // ^
         }else {
            ledStatus[x] == HIGH;                   // ^
         }
        digitalWrite(ledPins[x], ledStatus[x]);     //Digitale waarde naar de LED schrijven
      }
    }
  }

  
  if (irrecv.decode(&results)){                     //Als de IR-ontvanger een signaal heeft ontvangen
    if(selectedLed == 0){
      selectLed(results.value);                     //Welke knop er is gedrukt (voor welke led gedrukt wordt)
      Serial.println(results.value, HEX);           //Print de ontvangen waarde als hexadecimaal
      Serial.println("led selected");               //Print de feedback van het klikken van een knop
    } else {
      chooseSpeed(results.value);                   //Welke knop er is gedrukt (voor snelheid van de knippertijd)
      Serial.println("speed selected");             //Print de feedback van het klikken van een knop (snelheid)
    }
    delay(50);                                      //Delay van 50
    irrecv.resume();                                //Laat de IR-ontvanger luisteren naar nieuwe signalen
  }
}

void selectLed(int value){                          //selectLed functie 
  switch(results.value){                            //Bepaal welke knop is ingedrukt
    case 0xFF30CF:                                  //Knop 1 als Hex code
    selectedLed = 1;                                //Zet 1 als selectedLed 
    break;
    case 0xFF18E7:                                  //Knop 2 als Hex code
    selectedLed = 2;                                //Zet 2 als selectedLed
    break;
    case 0xFF7A85:                                  //Knop 3 als Hex code
    selectedLed = 3;                                //Zet 3 als selectedLed
    break;
    case 0xFF10EF:                                  //Knop 4 als Hex code
    selectedLed = 4;                                //Zet 4 als selectedLed
    break;
  }
}

void chooseSpeed(int value){
  switch(value){                                    
    case 0xFF30CF:                                  //Knop 1 als Hex code en case
    changeDelay(100);                               //Verandert de delay naar 100
    break;
    case 0xFF18E7:                                  //Knop 2 als Hex code en case
    changeDelay(200);                               //Verandert de delay naar 200
    break;
    case 0xFF7A85:                                  //Knop 3 als Hex code en case
    changeDelay(300);                               //Verandert de delay naar 300
    break;
    case 0xFF10EF:                                  //Knop 4 als Hex code en case
    changeDelay(400);                               //Verandert de delay naar 400
    break;
    case 0xFF38C7:                                  //Knop 5 als Hex code en case
    changeDelay(500);                               //Verandert de delay naar 500
    break;
    case 0xFF5AA5:                                  //Knop 6 als Hex code en case
    changeDelay(600);                               //Verandert de delay naar 600
    break;
    case 0xFF42BD:                                  //Knop 7 als Hex code en case
    changeDelay(700);                               //Verandert de delay naar 700
    break;
    case 0xFF4AB5:                                  //Knop 8 als Hex code en case
    changeDelay(800);                               //Verandert de delay naar 800
    break;
    case 0xFF52AD:                                  //Knop 9 als Hex code en case
    changeDelay(900);                               //Verandert de delay naar 900
    break;
  }
  selectedLed = 0;                                  //Zet selectedLed op 0
}

void changeDelay(int value){
  if(selectedLed == 1){                             //Als Led 1 wordt geselecteerd
    delays[0] = value;                              //Delay die op de LED zitten veranderen naar de geselecteerde Delay
    }else if (selectedLed == 2){                    //Als Led 2 wordt geselecteerd
      delays[1] = value;                            //Delay die op de LED zitten veranderen naar de geselecteerde Delay
      }else if (selectedLed == 3){                  //Als Led 3 wordt geselecteerd
        delays[2] = value;                          //Delay die op de LED zitten veranderen naar de geselecteerde Delay
        }else if (selectedLed == 4){                //Als Led 4 wordt geselecteerd
          delays[3] = value;                        //Delay die op de LED zitten veranderen naar de geselecteerde Delay
          }
}
