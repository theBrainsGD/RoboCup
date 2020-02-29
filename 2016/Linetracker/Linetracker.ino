int wert = 0;
int imax = 600;
void setup() {
Serial.begin(9600);

pinMode(3, INPUT);
pinMode(A3, INPUT);
pinMode(A4, INPUT);
}

void loop() {
  wert = analogRead(A3);
   Serial.println(wert);
   delay(50);
   
   if(wert > imax){
     imax = wert;
     Serial.println("max: ");
     Serial.print(imax);
     delay(300);
   }

  
 /*if(3 == true){
 Serial.println("true");
 }else
 Serial.println("false");
 */
 
 
}
