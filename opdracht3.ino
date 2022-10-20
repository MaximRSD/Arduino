int potMeter = A5;                              //Potmeter op pin A5 gezet
int ledPin7 = 7;                                //Ledpin 7 op pin 7 gezet
int ledPin8 = 8;                                //Ledpin 8 op pin 8 gezet
int ledPin9 = 9;                                //Ledpin 9 op pin 9 gezet
int ledPin10 =10;                               //Ledpin 10 op pin 10 gezet
int ledPin11 = 11;                              //Ledpin 11 op pin 11 gezet
int ledPin12 = 12;                              //Ledpin 12 op pin 12 gezet
int ledPin13 = 13;                              //Ledpin 13 op pin 13 gezet

void setup(){
  pinMode(potMeter, INPUT);                     //Uitgang van potMeter gedefinieerd als INPUT
  pinMode(ledPin7, OUTPUT);                     //Uitgang van ledpin7 gedefinieerd als OUTPUT
  pinMode(ledPin8, OUTPUT);                     //Uitgang van ledpin8 gedefinieerd als OUTPUT
  pinMode(ledPin9, OUTPUT);                     //Uitgang van ledpin9 gedefinieerd als OUTPUT
  pinMode(ledPin10, OUTPUT);                    //Uitgang van ledpin10 gedefinieerd als OUTPUT
  pinMode(ledPin11, OUTPUT);                    //Uitgang van ledpin11 gedefinieerd als OUTPUT
  pinMode(ledPin12, OUTPUT);                    //Uitgang van ledpin12 gedefinieerd als OUTPUT
  pinMode(ledPin13, OUTPUT);                    //Uitgang van ledpin13 gedefinieerd als OUTPUT
  Serial.begin(9600);                           //Bijhouden Potentiemeter in terminal
}

void loop(){
int potMeting = analogRead(A5);                 //potMeting is de waarde die gegeven wordt bij analogRead(A5)
  Serial.println(potMeting);                    //Print de metingen uit in de seriele monitor
  //loop door de metingen heen 
  if(potMeting < 50){                           //Als potmeting kleiner is dan 50 voert hij de statement uit
    digitalWrite(ledPin7, LOW);                 //Pin7 uit
    digitalWrite(ledPin8, LOW);                 //Pin8 uit
    digitalWrite(ledPin9, LOW);                 //Pin9 uit
    digitalWrite(ledPin10, LOW);                //Pin10 uit
    digitalWrite(ledPin11, LOW);                //Pin11 uit
    digitalWrite(ledPin12, LOW);                //Pin12 uit
    digitalWrite(ledPin13, LOW);                //Pin13 uit
  }else  if(potMeting < 250){                   //Als potmeting kleiner is dan 250 voert hij de statement uit
    digitalWrite(ledPin7, HIGH);                //Pin7 aan
    digitalWrite(ledPin8, LOW);                 //Pin8 uit
    digitalWrite(ledPin9, LOW);                 //Pin9 uit
    digitalWrite(ledPin10, LOW);                //Pin10 uit
    digitalWrite(ledPin11, LOW);                //Pin11 uit
    digitalWrite(ledPin12, LOW);                //Pin12 uit
    digitalWrite(ledPin13, LOW);                //Pin13 uit
  }else  if(potMeting < 300){                   //Als potmeting kleiner is dan 250 voert hij de statement uit
    digitalWrite(ledPin7, HIGH);                //Pin7 aan
    digitalWrite(ledPin8, HIGH);                //Pin8 aan
    digitalWrite(ledPin9, LOW);                 //Pin9 uit
    digitalWrite(ledPin10, LOW);                //Pin10 uit
    digitalWrite(ledPin11, LOW);                //Pin11 uit
    digitalWrite(ledPin12, LOW);                //Pin12 uit
    digitalWrite(ledPin13, LOW);                //Pin13 uit
  }else  if(potMeting < 450){                   //Als potmeting kleiner is dan 450 voert hij de statement uit
    digitalWrite(ledPin7, HIGH);                //Pin7 aan
    digitalWrite(ledPin8, HIGH);                //Pin8 aan
    digitalWrite(ledPin9, HIGH);                //Pin9 aan
    digitalWrite(ledPin10, LOW);                //Pin10 uit
    digitalWrite(ledPin11, LOW);                //Pin11 uit
    digitalWrite(ledPin12, LOW);                //Pin12 uit
    digitalWrite(ledPin13, LOW);                //Pin13 uit
  }else if(potMeting < 600){                    //Als potmeting kleiner is dan 600 voert hij de statement uit
    digitalWrite(ledPin7, HIGH);                //Pin7 aan
    digitalWrite(ledPin8, HIGH);                //Pin8 aan
    digitalWrite(ledPin9, HIGH);                //Pin9 aan
    digitalWrite(ledPin10, HIGH);               //Pin10 aan
    digitalWrite(ledPin11, LOW);                //Pin11 uit
    digitalWrite(ledPin12, LOW);                //Pin12 uit
    digitalWrite(ledPin13, LOW);                //Pin13 uit  
  }else if(potMeting < 750){                    //Als potmeting kleiner is dan 750 voert hij de statement uit
    digitalWrite(ledPin7, HIGH);                //Pin7 aan
    digitalWrite(ledPin8, HIGH);                //Pin8 aan
    digitalWrite(ledPin9, HIGH);                //Pin9 aan
    digitalWrite(ledPin10, HIGH);               //Pin10 aan
    digitalWrite(ledPin11, HIGH);               //Pin11 aan
    digitalWrite(ledPin12, LOW);                //Pin12 uit
    digitalWrite(ledPin13, LOW);                //Pin13 uit
  }else if(potMeting < 900){                    //Als potmeting kleiner is dan 900 voert hij de statement uit
    digitalWrite(ledPin7, HIGH);                //Pin7 aan
    digitalWrite(ledPin8, HIGH);                //Pin8 aan
    digitalWrite(ledPin9, HIGH);                //Pin9 aan
    digitalWrite(ledPin10, HIGH);               //Pin10 aan
    digitalWrite(ledPin11, HIGH);               //Pin11 aan
    digitalWrite(ledPin12, HIGH);               //Pin12 aan
    digitalWrite(ledPin13, LOW);                //Pin13 uit
  }else if(potMeting < 1024){                   //Als potmeting kleiner is dan 1024 voert hij de statement uit
    digitalWrite(ledPin7, HIGH);                //Pin7 aan
    digitalWrite(ledPin8, HIGH);                //Pin8 aan
    digitalWrite(ledPin9, HIGH);                //Pin9 aan
    digitalWrite(ledPin10, HIGH);               //Pin10 aan
    digitalWrite(ledPin11, HIGH);               //Pin11 aan
    digitalWrite(ledPin12, HIGH);               //Pin12 aan
    digitalWrite(ledPin13, HIGH);               //Pin13 aan
    
  }
}
