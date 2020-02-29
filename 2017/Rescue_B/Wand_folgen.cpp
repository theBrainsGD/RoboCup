#include "Wand_folgen.h"



void WandSeite(int Entfernung){
 switch(Entfernung){
  case SEITE_NAH:
   analogWrite(MR, SPEED);
   analogWrite(ML, SPEED_LOW);
   break;
  case SEITE_FERN:
   analogWrite(MR, SPEED_LOW);
   analogWrite(ML, SPEED);
   break;
  case SEITE_GUT:
   analogWrite(MR, SPEED);
   analogWrite(ML, SPEED);
   break; 
 }
}

void WandVorne(int Entfernung){
  switch(Entfernung){
    case VORNE_NAH:
     digitalWrite(IN_1 , HIGH);
     digitalWrite(IN_2 , LOW);
     analogWrite(MR, SPEED_HIGH);
    
     digitalWrite(IN_3 , LOW);
     digitalWrite(IN_4 , HIGH);
     analogWrite(ML, SPEED_HIGH);
     
     delay(1000);
   /* digitalWrite(IN_1, HIGH);
    digitalWrite(IN_3, HIGH);
    digitalWrite(IN_2, LOW);
    digitalWrite(IN_4, LOW);*/
     break;
    case VORNE_FERN:
     digitalWrite(IN_1, HIGH);
     digitalWrite(IN_3, HIGH);
     digitalWrite(IN_2, LOW);
     digitalWrite(IN_4, LOW);
    
     break;
  }
}
