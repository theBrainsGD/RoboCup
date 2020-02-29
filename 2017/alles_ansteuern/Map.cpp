#include "Map"

//boolean beispiel[X Breite][Z Tiefe][Y Höhe];

//die Variablen werden auf true gesetzt, solbald eine wand an der jeweiligen koordinate 
// erkannt wurde.

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

