#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

#include "Vars.h"
#include "Stuff.h"
#include "MazeDrive.h"


LiquidCrystal_I2C lcd(0x20, 20, 4);

//speichert alle Checkpoints
//             [der wievielte Checkpoint][0 = posX, 1 = posZ, 2 = posY]
//int Checkpoint           [1]                     [3];

 int posX = StartPosX;
 int posY = StartPosY;
 int posZ = StartPosZ;
 //int dir  = NORTH;

 

void setup() {
  lcd.init();

  lcd.backlight();
  lcd.setCursor(5,1);
  lcd.print("The Brains");
  
  Serial.begin(9600);
  pinMode(SensorRightBack,  INPUT);
  pinMode(SensorRightFront,  INPUT);
  pinMode(SensorFrontRight, INPUT);
  pinMode(SensorFrontLeft, INPUT);

  pinMode(LED, OUTPUT);

  pinMode(A_IN_1,OUTPUT);
  pinMode(A_IN_2,OUTPUT);
  pinMode(B_IN_1, OUTPUT);
  pinMode(B_IN_2, OUTPUT);

  digitalWrite(A_IN_1, HIGH);     // Setzen der Drehrichtung
  digitalWrite(A_IN_2, LOW);
  digitalWrite(B_IN_1, HIGH);
  digitalWrite(B_IN_2, LOW);


  delay(1000);


  //setze die Ausrichtung und die Position am Anfang


  lcd.setCursor(0,0);
  lcd.print("Wall_N       Wall_S");
  lcd.setCursor(0,2);
  lcd.print("Wall_W       Wall_E");

}

void loop() {

ClearLCDLine(1, lcd);
lcd.print((String)getNorth(posX, posY, posZ));
ClearLCDLine(3, lcd);
lcd.print((String)getWest(posX, posY, posZ));



  
  /*switch(Direction){
    case(NORTH):
      lcd.clear();
      lcd.print("|");
      lcd.setCursor(0,1);
      lcd.print("V");
      break;
    case(WEST):
      lcd.clear();
      lcd.print("<--");
      break;
    case(SOUTH):
      lcd.clear();
      lcd.print("^");
      lcd.setCursor(0,1);
      lcd.print("|");
      break;
    case(EAST):
      lcd.clear();
      lcd.print("-->");
      break;
  }*/
}
