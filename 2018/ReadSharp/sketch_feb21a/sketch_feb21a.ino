#include <LiquidCrystal_I2C.h>

#include <SharpIR.h>

#include "Util.h"


LiquidCrystal_I2C lcd(0x20, 20, 4);

SharpIR FL(A0, 1080);
SharpIR LF(A1, 430);
SharpIR FR(A4, 430);
SharpIR RB(A5, 430);
SharpIR LB(A6, 430);

void setup() {
  Serial.begin(9600);
}

void loop() {
  int dis = FL.distance();
  Serial.print("FrontLeft: ");
  Serial.print(dis);

  dis = readLeftFront(LF);
  Serial.print("  LeftFront: ");
  Serial.print(dis);

  dis = FR.distance();
  Serial.print("  FrontRight: ");
  Serial.print(dis);

  dis = RB.distance();
  Serial.print("  RightBack: ");
  Serial.print(dis);

  dis = LB.distance();
  Serial.print("  LeftBack: ");
  Serial.println(dis);
  delay(100);

}
