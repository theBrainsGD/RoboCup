#include "Opfer_finden.h"

void Opfer(int Opfer){
 switch(Opfer){
  case JA:
  digitalWrite(LED, HIGH);
 break;
  case NEIN:
   digitalWrite(LED, LOW);
 break;
 }
}
