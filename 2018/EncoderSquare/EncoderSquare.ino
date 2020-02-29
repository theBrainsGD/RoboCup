// Dieser Code soll den Roboter immer ein Feld forwärts
// fahren lassen und dann um 90° nach rechts drehen
// Dies soll dazu dienen, die Encoder Werte besser fest-
// stellen zu können!

// geschrieben am 13.1.18

#include "Vars.h"
#include "Engine.h"

#include <LiquidCrystal_I2C.h>

volatile int encoderLeft = 0;
volatile int encoderRight = 0;

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
  turn(RIGHT);
  engineStop();
  lcd.clear();
  lcd.print("DONE!");
  delay(1000);
  moveTileForward();
  engineStop();
  lcd.clear();
  lcd.print("DONE!");
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
  while (encoderLeft < leftMoveGoal || encoderRight < rightMoveGoal) {
    if (encoderLeft < leftMoveGoal) {
      engineLeftForward();
      digitalWrite(ena, HIGHSPEED);
    } else {
      engineLeftStop();
    }
    if (encoderRight < rightMoveGoal) {
      engineRightForward();
      digitalWrite(enb, HIGHSPEED);
    }
    else {
      engineRightStop();
    }
  }
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
    while (encoderLeft < leftTurnGoal || encoderRight < rightTurnGoal) {

      if (encoderLeft < leftTurnGoal) {
        engineLeftForward();
        digitalWrite(enb, HIGHSPEED);
      } else {
        engineLeftStop();
      }

      if (encoderRight < rightTurnGoal) {
        engineRightBackward();
        digitalWrite(ena, HIGHSPEED);
      } else {
        engineRightStop();
      }
    }
  } else if (dir == LEFT) {
    while (encoderLeft < leftTurnGoal || encoderRight < rightTurnGoal) {

      if (encoderLeft < leftTurnGoal) {
        engineLeftBackward();
        digitalWrite(enb, HIGHSPEED);
      } else {
        engineLeftStop();
      }

      if (encoderRight < rightTurnGoal) {
        engineRightForward();
        digitalWrite(ena, HIGHSPEED);
      } else {
        engineRightStop();
      }
    }
engineStop();
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


