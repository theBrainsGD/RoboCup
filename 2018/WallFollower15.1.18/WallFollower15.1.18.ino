// Main Code für den RoboCup

#include "Vars.h"
#include "Engine.h"

#include <LiquidCrystal_I2C.h>

volatile int encoderLeft = 0;
volatile int encoderRight = 0;

int grayScaleLeft = 0;
int grayScaleRight = 0;

boolean onBlack = false;

int currentDirection = NORTH;

LiquidCrystal_I2C lcd(LCDAddress, LCDCols, LCDRows);


void setup() {
  lcd.init();
  lcd.backlight();
  lcd.print("Starting up");

  pinMode(ena, OUTPUT);
  pinMode(enb, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(TACHO0), countL, CHANGE);
  attachInterrupt(digitalPinToInterrupt(TACHO1), countR, CHANGE);


  engineForward();
  delay(2500);
}

void loop() {
  moveTileForward();
delay(1000);
}



void resetEncoder() {
  encoderLeft = 0;
  encoderRight = 0;
}


void moveTileForward() {
  lcd.clear();
  lcd.print("reaching new Tile!");
  resetEncoder();
  while (encoderLeft < leftMoveGoal && encoderRight < rightMoveGoal && !onBlack) {
    checkBlack();
    if (onBlack) {
      lcd.clear();
      break;
    }
    if (encoderLeft < leftMoveGoal) {
      engineLeftForward();
      digitalWrite(ena, HIGHSPEED);
    } else {
      engineLeftStop();
    }
    if (encoderRight < rightMoveGoal) {
      engineRightForward();
      digitalWrite(enb, HIGHSPEED);
    } else {
      engineRightStop();
    }
  }

  if (onBlack) {
    int encLeftTmp = encoderLeft * 2;
    int encRightTmp = encoderRight * 2;
    while (encoderRight < encRightTmp && encoderLeft < encLeftTmp) {
      if (encoderRight < encRightTmp) {
        engineRightBackward();
        digitalWrite(enb, HIGHSPEED);
      } else {
        engineRightStop();
      }
      if (encoderLeft < encLeftTmp) {
        engineLeftBackward();
        digitalWrite(ena, HIGHSPEED);
      } else {
        engineLeftStop();
      }
    }
  }

  onBlack = false;
}


int getNextDirection() {

}

void turn(int dir) {
  lcd.clear();
  String s = "turn ";
  if (dir == RIGHT) {
    s += "right";
  } else {
    s += "left";
  }
  lcd.print(s);

  resetEncoder();
  if (dir == RIGHT) {
    while (encoderLeft < leftTurnGoal && encoderRight < rightTurnGoal) {

      if (encoderLeft < leftTurnGoal) {
        engineLeftForward();
        digitalWrite(enb, MIDDLESPEED);
      } else {
        engineLeftStop();
      }

      if (encoderRight < rightTurnGoal) {
        engineRightBackward();
        digitalWrite(ena, MIDDLESPEED);
      } else {
        engineRightStop();
      }
    }
  } else if (dir == LEFT) {
    while (encoderLeft < leftTurnGoal && encoderRight < rightTurnGoal) {

      if (encoderLeft < leftTurnGoal) {
        engineLeftBackward();
        digitalWrite(enb, MIDDLESPEED);
      } else {
        engineLeftStop();
      }

      if (encoderRight < rightTurnGoal) {
        engineRightForward();
        digitalWrite(ena, MIDDLESPEED);
      } else {
        engineRightStop();
      }
    }

    lcd.clear();
    lcd.print("DONE!");
    delay(1000);
  }
}

void countL() {
  encoderLeft++;
}

void countR() {
  encoderRight++;
}

void checkBlack() {
  readGrayScale();
  onBlack = (grayScaleLeft > blackL || grayScaleRight > blackR);
}

void readGrayScale() {
  grayScaleLeft = analogRead(graySclL);
  grayScaleRight = analogRead(graySclR);
}


