#include "MazeDrive.h"

//this is an array which stores all possibilites in an Coordinate system
//xpos ist nach Norden und süden, zpos nach westen und Osten und Ypos nach öben bzw nach unten 
//         [Xpos][Zpos][Ypos][porperty]      
boolean Map [20]  [20]  [3]      [9];
//use like this:
//the robot gets the information that on the current pos in the NORTH direction a will exist
// Map [xpos][zpos][ypos][WALL_NORTH] = true;
//see possible properties in "Vars.h"



//Current Posrition
int posX, posY, posZ;
//Current Direction
int dir;



void drive(){
 // setProperties();
  
  }





void setProperties(int xPos, int zPos, int yPos, int Direction){
  /*
    setze jede möglichkeit, die der Roboter an dem Feld, auf dem er ist, haben kann.
    um die Werte richtig im Koordinatensystem speichern zu können müssen Ausrichtung, und die Position übergeben werden    
  */
  
int valueNorthRight, valueNorthLeft, valueEastFront, valueEastBack, valueSouthRight, valueSouthLeft, valueWestFront, valueWestBack;



  //auslesen der Werte an der Position
  int valueFrontRight = analogRead(SensorFrontRight);
  int valueFrontLeft = analogRead(SensorFrontLeft);
  int valueRightFront = analogRead(SensorRightFront);
  int valueRightBack = analogRead(SensorRightBack);



//SwitchAbfrage, da die Sensoren je nach Ausrichtung in andere Richtungen zeigen. 
//ist die Ausrichtung NORTH, so zeigen die FrontSensoren nach NORTH, ist die Ausrichtung WEST, so zeigen die Rechten Sensoren nach NORTH
//setze die werte der Sensoren, abhänging von der Ausrichtung auf Werte die an der Ausrichtung angepasst sind
  switch(Direction){
    case NORTH:
      valueNorthRight = valueFrontRight;
      valueNorthLeft = valueFrontLeft;
      valueEastFront = valueRightFront;
      valueEastBack = valueRightBack;
      break;
    case WEST:
      valueNorthRight = valueRightBack;
      valueNorthLeft = valueRightFront;
      valueWestFront = valueNorthRight;
      valueWestBack = valueNorthLeft;
      break;
    case SOUTH:
      valueWestFront = valueRightBack;
      valueWestBack = valueRightFront;
      valueSouthLeft = valueFrontRight;
      valueSouthRight = valueFrontLeft;
      break;
    case EAST:
      valueEastFront = valueFrontLeft;
      valueEastBack = valueFrontRight;
      valueSouthRight = valueRightFront;
      valueSouthLeft = valueRightBack;
      break;
    }

    
    //überprüfe ob in einer Direction ein Hinderniss ist, fallse dem so ist wird in der jeweiligen Richtung die Wandeigenschafft auf true gesetzt
    if((valueNorthLeft > valueMAX) && (valueNorthRight > valueMAX)){
        Map[xPos][zPos][yPos][WALL_NORTH] = true;
      }else{Map[xPos][zPos][yPos][WALL_NORTH] = false;}
    if((valueSouthLeft > valueMAX) && (valueSouthRight > valueMAX)){
        Map[xPos][zPos][yPos][WALL_SOUTH] = true;
      }else{Map[xPos][zPos][yPos][WALL_SOUTH] = false;}
    if((valueEastFront > valueMAX) && (valueEastBack > valueMAX)){
        Map[xPos][zPos][yPos][WALL_EAST] = true;
      }else{Map[xPos][zPos][yPos][WALL_EAST] = false;}
    if((valueWestFront > valueMAX) && (valueWestBack > valueMAX)){
        Map[xPos][zPos][yPos][WALL_WEST] = true;
      }else{Map[xPos][zPos][yPos][WALL_WEST] = false;}
    
  }

  boolean getNorth(int X, int Y, int Z){
    return Map[X][Z][Y][WALL_NORTH];
    }

    boolean getSouth(int X, int Y, int Z){
    return Map[X][Z][Y][WALL_SOUTH];
    }

    boolean getWest(int X, int Y, int Z){
    return Map[X][Z][Y][WALL_WEST];
    }

    boolean getEast(int X, int Y, int Z){
    return Map[X][Z][Y][WALL_EAST];
    }
