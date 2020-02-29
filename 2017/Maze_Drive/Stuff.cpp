#include  "Stuff.h"

int getDigits(int value){                                                               //returns the digits of a givin Integer
  int counter = 1;
  for(int i = 10; value >= i;  i = i*10){
    counter++;
  }return counter;
}

void ClearLCDLine(int Line, LiquidCrystal_I2C lcd){
  lcd.setCursor(0, Line);
  lcd.print("                    ");
  lcd.setCursor(0,Line);
}




/*int VFR, VFL, VRF, VRB; //store the distancevalues of the Sensors
int dir;*/

/*int drive(int Direction, int dFR, int dFL, int dRF, int dRB){
  VFR = dFR;
  VFL = dFL;
  VRF = dRF;
  VRB = dRB;
  
  dir = Direction;
  
  while(VFR > valueMAX || VFL > valueMAX){  //dreht den Roboter solange um 90° bis vorne kein Hindernis zu erkennen ist.

    //drehe den Roboter wirklich um 90°
    analogWrite(ena, 255);
    analogWrite(enb, 255);
    delay(1000); //dreht den Roboter 1s lang (mit encodern überarbeiten)
    
    switch(dir){    //wechselt die direction zu der neuen direction nach der Drehung
      case(NORTH):
        dir = WEST;
        break;
      case(WEST):
        dir = SOUTH;
        break;
      case(SOUTH):
        dir = EAST;
        break;
      case(EAST):
        dir = NORTH;;
        break;
    }
    VFR = analogRead(SensorFrontRight); //überprüft, ob vor ihm eine Wand ist
    VFL = analogRead(SensorFrontLeft);
  }
  
  
  return dir; //gibt die neue Richtung aus, die der Roboter nach der Drehung hat
}*/
