#include "Karte.h"

//boolean beispiel[X Breite][Z Tiefe][Y Höhe];

boolean oben[20][20][3];
boolean links[20][20][3];
boolean rechts[20][20][3];
boolean unten[20][20][3];
boolean schwarz[20][20][3];
boolean check[20][20][3];
boolean Rampe[20][20][3];
boolean Opfer[20][20][3];
 

int StartX = 10;
int StartZ = 10;
int StartY = 2;

 // setzte Anfangskoordinaten für Position und Checkpoint
int PosX = StartX;
int PosY = StartY;
int PosZ = StartZ;
 
int CheckX = StartX;
int CheckY = StartY;
int CheckZ = StartZ;



//Entfernungen
int FrontRight[2] = {200, 500};
int FrontLeft[2] = {200, 500};
int LeftSideFront[2] = {200, 500};
int LeftSideBack[2] = {200, 500};
int RightSideFront[2] = {200, 500};   //werte müssen kalibriert werden
int RightSideBack[2] = {200, 500};
int BackLeft[2] = {200, 500};
int BackRight[2] = {200, 500};

int Heat[2] = {29, 31};



//SensorVariablen
int Front_Right_Wert;
int Front_Left_Wert;
int LeftSide_Front_Wert;
int LeftSide_Back_Wert;
int RightSide_Front_Wert;
int RightSide_Back_Wert;
int Back_Right_Wert;
int Back_Left_Wert;




 

void Mapping(int Direction){
  
 Front_Right_Wert = analogRead(FRONT_RIGHT);
 Front_Left_Wert = analogRead(FRONT_LEFT);
 LeftSide_Front_Wert = analogRead(LEFTSIDE_FRONT);
 LeftSide_Back_Wert = analogRead(LEFTSIDE_BACK);
 RightSide_Front_Wert = analogRead(RIGHTSIDE_FRONT);
 RightSide_Back_Wert = analogRead(RIGHTSIDE_BACK);
 Back_Right_Wert = analogRead(BACK_RIGHT);
 Back_Left_Wert = analogRead(BACK_LEFT); 
 
 switch(Direction){
  case NORTH:
  
  
   if((Front_Right_Wert > FrontRight[1]) && (Front_Left_Wert > FrontLeft[1])){
   oben[PosX][PosY][PosZ] = true;
   }else
   oben[PosX][PosY][PosZ] = false;
   
   if((Back_Right_Wert > BackRight[1]) && (Back_Left_Wert > BackLeft[1])){
   unten[PosX][PosY][PosZ] = true;
   }else
   unten[PosX][PosY][PosZ] = false;
   
   if((RightSide_Front_Wert > RightSideFront[1]) && (RightSide_Back_Wert > RightSideBack[1])){
   rechts[PosX][PosY][PosZ] = true;
   }else
   rechts[PosX][PosY][PosZ] = false;
   
   if(( LeftSide_Front_Wert > LeftSideFront[1]) && ( LeftSide_Back_Wert > LeftSideBack[1])){
   links[PosX][PosY][PosZ] = true;
   }else
   links[PosX][PosY][PosZ] = false;
   
   /*
   if(analogRead(LineTracker) == true){
   schwarz[PosX][PosY][PosZ] = true;
   }else
   schwarz[PosX][PosY][PosZ] = false;
   */
   
   
   break;
   case SOUTH:
   if((Front_Right_Wert > FrontRight[1]) && (Front_Left_Wert > FrontLeft[1])){
   unten[PosX][PosY][PosZ] = true;
   }else
   unten[PosX][PosY][PosZ] = false;
   
   if((Back_Right_Wert > BackRight[1]) && (Back_Left_Wert > BackLeft[1])){
   oben[PosX][PosY][PosZ] = true;
   }else
   oben[PosX][PosY][PosZ] = false;
   
   if((RightSide_Front_Wert > RightSideFront[1]) && (RightSide_Back_Wert > RightSideBack[1])){
   links[PosX][PosY][PosZ] = true;
   }else
   links[PosX][PosY][PosZ] = false;
   
   if(( LeftSide_Front_Wert > LeftSideFront[1]) && ( LeftSide_Back_Wert > LeftSideBack[1])){
   rechts[PosX][PosY][PosZ] = true;
   }else
   rechts[PosX][PosY][PosZ] = false;
   
   /*
   if(analogRead(LineTracker) == true){
   schwarz[PosX][PosY][PosZ] = true;
   }else
   schwarz[PosX][PosY][PosZ] = false;
   */   
   
   break;
   case EAST:
   if((Front_Right_Wert > FrontRight[1]) && (Front_Left_Wert > FrontLeft[1])){
   rechts[PosX][PosY][PosZ] = true;
   }else
   rechts[PosX][PosY][PosZ] = false;
   
   if((Back_Right_Wert > BackRight[1]) && (Back_Left_Wert > BackLeft[1])){
   links[PosX][PosY][PosZ] = true;
   }else
   links[PosX][PosY][PosZ] = false;
   
   if((RightSide_Front_Wert > RightSideFront[1]) && (RightSide_Back_Wert > RightSideBack[1])){
   unten[PosX][PosY][PosZ] = true;
   }else
   unten[PosX][PosY][PosZ] = false;
   
   if(( LeftSide_Front_Wert > LeftSideFront[1]) && ( LeftSide_Back_Wert > LeftSideBack[1])){
   oben[PosX][PosY][PosZ] = true;
   }else
   oben[PosX][PosY][PosZ] = false; 
   
      /*
   if(analogRead(LineTracker) == true){
   schwarz[PosX][PosY][PosZ] = true;
   }else
   schwarz[PosX][PosY][PosZ] = false;
   */
 
   
   break;
   case WEST:
   if((Front_Right_Wert > FrontRight[1]) && (Front_Left_Wert > FrontLeft[1])){
   links[PosX][PosY][PosZ] = true;
   }else
   links[PosX][PosY][PosZ] = false;
   
   if((Back_Right_Wert > BackRight[1]) && (Back_Left_Wert > BackLeft[1])){
   rechts[PosX][PosY][PosZ] = true;
   }else
   rechts[PosX][PosY][PosZ] = false;
   
   if((RightSide_Front_Wert > RightSideFront[1]) && (RightSide_Back_Wert > RightSideBack[1])){
   oben[PosX][PosY][PosZ] = true;
   }else
   oben[PosX][PosY][PosZ] = false;
   
   if(( LeftSide_Front_Wert > LeftSideFront[1]) && ( LeftSide_Back_Wert > LeftSideBack[1])){
   unten[PosX][PosY][PosZ] = true;
   }else
   unten[PosX][PosY][PosZ] = false;    
   
   /*
   if(analogRead(LineTracker) == true){
   schwarz[PosX][PosY][PosZ] = true;
   }else
   schwarz[PosX][PosY][PosZ] = false;
   */   
   
   
   break;
 }
 
}

