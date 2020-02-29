int Helligkeit[5] = {50, 100, 150, 200, 250};
int Entfernung[5] = {200,300,400,500,600};
int SharpSensorWert;
void setup() {
 Serial.begin(9600);
 pinMode(A3,INPUT);
 pinMode(13,OUTPUT);
}

void loop() {
  SharpSensorWert = analogRead(A3);
  
  if((SharpSensorWert > Entfernung[0]) &&(SharpSensorWert < Entfernung[1])){
  analogWrite(13,Helligkeit[0]);
  }else if((SharpSensorWert > Entfernung[1]) &&(SharpSensorWert < Entfernung[2])){
  analogWrite(13,Helligkeit[1]);
  }else if((SharpSensorWert > Entfernung[2]) &&(SharpSensorWert < Entfernung[3])){
  analogWrite(13,Helligkeit[2]);
  }else if((SharpSensorWert > Entfernung[3]) &&(SharpSensorWert < Entfernung[4])){
  analogWrite(13,Helligkeit[3]);
  }else if((SharpSensorWert > Entfernung[4])){
  analogWrite(13,Helligkeit[4]);
  }

}
