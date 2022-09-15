float temperatuur;
int tempPin = 0;


void setup() {
   //Serial Monitor setup
   Serial.begin(9600);
}

void loop() {
   temperatuur = analogRead(tempPin);
   // Leest analog volt van sensor en slaat de variabele op
   temperatuur = temperatuur * 0.48828125;
   // Zorgt ervoor dat de temperatuur gelijkwaardig wordt.
   Serial.print("Temperatuur:  ");
   // Laat temperatuur zien.
   Serial.print(temperatuur); 
   Serial.print(" Celcius ");
   Serial.println();
   // Laat om de seconde zien wat de temperatuur is.
   delay(1000); 
}
