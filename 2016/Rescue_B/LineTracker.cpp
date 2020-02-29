#include "LineTracker.h"

void LineTracker(int Sensor) {
 switch(Sensor){
  case Schwarz:
     digitalWrite(IN_1, LOW);
     digitalWrite(IN_2, HIGH);
     analogWrite(ML, SPEED_NORMAL);
    
     digitalWrite(IN_3, LOW);
     digitalWrite(IN_4, HIGH);
     analogWrite(MR, SPEED_NORMAL);
     delay(300);

     digitalWrite(IN_1, HIGH);
     digitalWrite(IN_2, LOW);
     analogWrite(ML, SPEED_HIGH);
    
     digitalWrite(IN_3, LOW);
     digitalWrite(IN_4, HIGH);
     analogWrite(MR, SPEED_HIGH);   
     delay(2000);

     while(analogRead(SENSOR_SEITE) < Seite_Fern) {
        digitalWrite(IN_1, HIGH);
        digitalWrite(IN_2, LOW);
        analogWrite(ML, SPEED_NORMAL);
        
        digitalWrite(IN_3, HIGH);
        digitalWrite(IN_4, LOW);
        analogWrite(MR, SPEED_NORMAL);
     }
   break;
  case Weiss:
  
   break;
 }
}
