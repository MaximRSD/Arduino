int potMeter = A5;
int ledPin7 = 7;
int ledPin8 = 8;
int ledPin9 = 9;
int ledPin10 =10;
int ledPin11 = 11;
int ledPin12 = 12;
int ledPin13 = 13;

void setup(){
  pinMode(potMeter, INPUT);
  pinMode(ledPin7, OUTPUT);
  pinMode(ledPin8, OUTPUT);
  pinMode(ledPin9, OUTPUT);
  pinMode(ledPin10, OUTPUT);
  pinMode(ledPin11, OUTPUT);
  pinMode(ledPin12, OUTPUT);
  pinMode(ledPin13, OUTPUT);
  //Bijhouden Potentiemeter in terminal
  Serial.begin(9600);
}

void loop(){
int potMeting = analogRead(A5);
  Serial.println(potMeting);
  //loop door de metingen heen 
  if(potMeting < 50){
    digitalWrite(ledPin7, LOW);
    digitalWrite(ledPin8, LOW);
    digitalWrite(ledPin9, LOW);
    digitalWrite(ledPin10, LOW);
    digitalWrite(ledPin11, LOW);
    digitalWrite(ledPin12, LOW);
    digitalWrite(ledPin13, LOW);
  }else  if(potMeting < 250){
    digitalWrite(ledPin7, HIGH);
    digitalWrite(ledPin8, LOW);
    digitalWrite(ledPin9, LOW);
    digitalWrite(ledPin10, LOW);
    digitalWrite(ledPin11, LOW);
    digitalWrite(ledPin12, LOW);
    digitalWrite(ledPin13, LOW);
  
  }else  if(potMeting < 300){
    digitalWrite(ledPin7, HIGH);
    digitalWrite(ledPin8, HIGH);
    digitalWrite(ledPin9, LOW);
    digitalWrite(ledPin10, LOW);
    digitalWrite(ledPin11, LOW);
    digitalWrite(ledPin12, LOW);
    digitalWrite(ledPin13, LOW);
  
  }else  if(potMeting < 450){
    digitalWrite(ledPin7, HIGH);
    digitalWrite(ledPin8, HIGH);
    digitalWrite(ledPin9, HIGH);
    digitalWrite(ledPin10, LOW);
    digitalWrite(ledPin11, LOW);
    digitalWrite(ledPin12, LOW);
    digitalWrite(ledPin13, LOW);
  
  }else if(potMeting < 600){
    digitalWrite(ledPin7, HIGH);
    digitalWrite(ledPin8, HIGH);
    digitalWrite(ledPin9, HIGH);
    digitalWrite(ledPin10, HIGH);
    digitalWrite(ledPin11, LOW);
    digitalWrite(ledPin12, LOW);
    digitalWrite(ledPin13, LOW);
    
  }else if(potMeting < 750){
    digitalWrite(ledPin7, HIGH);
    digitalWrite(ledPin8, HIGH);
    digitalWrite(ledPin9, HIGH);
    digitalWrite(ledPin10, HIGH);
    digitalWrite(ledPin11, HIGH);
    digitalWrite(ledPin12, LOW);
    digitalWrite(ledPin13, LOW);
    
  }else if(potMeting < 900){
    digitalWrite(ledPin7, HIGH);
    digitalWrite(ledPin8, HIGH);
    digitalWrite(ledPin9, HIGH);
    digitalWrite(ledPin10, HIGH);
    digitalWrite(ledPin11, HIGH);
    digitalWrite(ledPin12, HIGH);
    digitalWrite(ledPin13, LOW);
    
  }else if(potMeting < 1024){
    digitalWrite(ledPin7, HIGH);
    digitalWrite(ledPin8, HIGH);
    digitalWrite(ledPin9, HIGH);
    digitalWrite(ledPin10, HIGH);
    digitalWrite(ledPin11, HIGH);
    digitalWrite(ledPin12, HIGH);
    digitalWrite(ledPin13, HIGH);
    
  }
}
