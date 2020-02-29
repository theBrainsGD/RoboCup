#include "LineTracker.h"

void LineTracker(int Sensor){
 switch(Sensor){
  case Schwarz:
   while(41 == true){
     digitalWrite(4, HIGH);
     digitalWrite(45, LOW);
     analogWrite(6, 200);
    
     digitalWrite(5, HIGH);
     digitalWrite(46, LOW);
     analogWrite(7, 200);
   }
     digitalWrite(4, HIGH);
     digitalWrite(45, LOW);
     analogWrite(6, 200);
    
     digitalWrite(5, LOW);
     digitalWrite(46, HIGH);
     analogWrite(7, 200);
     delay(3500);
     
     digitalWrite(4, LOW);
     digitalWrite(45, HIGH);
     analogWrite(6, 200);
    
     digitalWrite(5, LOW);
     digitalWrite(46, HIGH);
     analogWrite(7, 200);
     
     delay(1000);
     
   break;
  case Weis:
  
   break;
 }
}
