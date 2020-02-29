#define WS A7
int wswert ;

void setup() {
 Serial.begin(9600);
 
 pinMode(WS, INPUT);
 
}

void loop() {
wswert = analogRead(WS);

Serial.println(wswert);
Serial.print("Grad!!! Puh ist mir heiß!!!");
delay(100);
}
