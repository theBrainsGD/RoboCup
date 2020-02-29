#include "Wand_folgen.h"

void WandVorne(int Entfernung){
  switch(Entfernung){
    case VORNE_NAH:
     digitalWrite(IN_1 , HIGH);
     digitalWrite(IN_2 , LOW);
     analogWrite(MR, SPEED_HIGH);
    
     digitalWrite(IN_3 , LOW);
     digitalWrite(IN_4 , HIGH);
     analogWrite(ML, SPEED_HIGH);
     delay(150);
     break;
    case VORNE_FERN:
     digitalWrite(IN_1, HIGH);
     digitalWrite(IN_3, HIGH);
     digitalWrite(IN_2, LOW);
     digitalWrite(IN_4, LOW);
     break;
  }
}


void WandSeite(int Entfernung){
 switch(Entfernung){
  case SEITE_NAH:
   analogWrite(MR, SPEED_HIGH);
   analogWrite(ML, SPEED_OFF);
   break;
  case SEITE_FERN:
   analogWrite(ML, SPEED_HIGH);
   analogWrite(MR, SPEED_NORMAL);
   break;
   case SEITE_SEHR_FERN:
     digitalWrite(IN_1 , LOW);
     digitalWrite(IN_2 , HIGH);
     analogWrite(MR, SPEED_LOW);
    
     digitalWrite(IN_3 , HIGH);
     digitalWrite(IN_4 , LOW);
     analogWrite(ML, SPEED_HIGH);
   break;
  case SEITE_GUT:
   analogWrite(MR, SPEED_NORMAL);
   analogWrite(ML, SPEED_NORMAL);
   break; 
 }
}
