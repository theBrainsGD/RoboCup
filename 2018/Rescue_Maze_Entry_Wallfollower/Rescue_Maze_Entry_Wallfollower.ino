#include "SharpIR.h"
#include "LiquidCrystal_I2C.h"

#include "Engine.h"
#include "Util.h"
#include "Vars.h"



// Objektinitialisierung
LiquidCrystal_I2C lcd(LCDAddress, LCDCols, LCDRows);

SharpIR sharpLeftBack(IRLeftBack, 430);
SharpIR sharpFrontRight(IRFrontRight, 430);
SharpIR sharpFrontLeft(IRFrontLeft, 1080);
SharpIR sharpLeftFront(IRLeftFront, 430);


// Variablen

int valueLB = 0;
int valueFR = 0;
int valueFL = 0;
int valueLF = 0;

int graySclL = 0;
int graySclR = 0;

volatile int encoderLeft = 0;
volatile int encoderRight = 0;


void setup() {
  Serial.begin(9600);

  lcd.init();
  lcd.backlight();
  lcd.clear();

  pinMode(ena, OUTPUT);
  pinMode(enb, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(3), countEncoderRight, CHANGE);
  attachInterrupt(digitalPinToInterrupt(18), countEncoderLeft, CHANGE);

  pinMode(LEDRed, OUTPUT);
  pinMode(LEDGreen, OUTPUT);
  pinMode(LightSensor, INPUT);
  pinMode(Piezo, OUTPUT);

  engineForward();
}

void loop() {

  readSensors();

  // die oberste Priorität hat die Schwarzerkennung!!
  if (graySclR > 310 && graySclL > 285) {
    lcd.clear();
    lcd.print("Schwarz");
    while (graySclR > 310 || graySclL > 285) {
      readSensors();
      if (graySclR > 310) {
        engineRightBackward();
        analogWrite(ena, 255);
      } else {
        engineRightStop();
      }
      if (graySclL > 285) {
        engineLeftBackward();
        analogWrite(enb, 255);
      } else {
        engineLeftStop();
      }
    }

    // Beide sehen kein schwarz mehr!
    turn(RIGHT);

    // jetzt muss ein Feld vorwärts gefahren werden
    readSensors();
    if (valueFL > 15) {
      engineForward();
      analogWrite(ena, 255);
      analogWrite(enb, 255);
      delay(1400);
      lcd.clear();
      engineStop();
    } else {
      turn(RIGHT);
    }

    return;
  }



  //überprüfe immer zuerst, ob vorne ein Wand ist!
  if (valueFL < 10 || valueFR < 10) {
    Serial.print("FrontLeft: ");
    Serial.print(valueFL);
    Serial.print(" FrontRight: ");
    Serial.println(valueFR);
    lcd.clear();
    lcd.print("Wand");
    // wir müssen uns nach rechts drehen
    turn(RIGHT);
    lcd.clear();
    return;
  }


  // Wenn die linken Sensoren kleiner als 9 sind müssen wir
  // von der linken Wand wegfahren
  // Wenn der linke Sensor kleiner ist als 13 und größer ist
  // als 10, dann soll wieder dichter zur Wand gefahren werden
  lcd.clear();
  if (valueLF < 11) {
    lcd.print("nach rechts");
    engineForward();
    analogWrite(ena, 180);
    analogWrite(enb, 255);
  } else if (valueLF < 13 && valueLF > 10) {
    lcd.print("weiter");
    engineForward();
    analogWrite(ena, 255);
    analogWrite(enb, 255);
  } else if (valueLF < 20) {
    lcd.print("links");
    engineForward();
    analogWrite(ena, 255);
    analogWrite(enb, 155);
  }

  // Wenn der linke vordere Sensor keine Wand mehr hat,
  // dann muss nach links abgebogen werden!
  if (valueLF > 20) {
    lcd.clear();
    lcd.print("leer");
    while (valueLB < 20) {
      readSensors();
      engineForward();
      analogWrite(ena, 255);
      analogWrite(enb, 255);
    }




    //wir sind in das Feld eingefahren
    // Drehen!
    lcd.clear();
    lcd.print("drehen");
    // wir müssen uns nach links drehen
    turn(LEFT);
    lcd.clear();

    // solange der hintere Sensor keine Wand sieht: vorwärts
    resetEncoder(); // resetten der Encoder um sie besser auslesen zu können
    while (valueLB > 20 && (encoderLeft < 720) ) {
      readSensors();
      

      if (valueFL < 10 || valueFR < 10) {
        return;
      }

      if(graySclR > 400 && graySclL > 320){
        return;
        }
      lcd.clear();
      lcd.print("Ich suche");
      lcd.setCursor(0, 1);
      lcd.print(encoderLeft);
      Serial.println(valueLB);
      readSensors();
      engineForward();
      analogWrite(ena, 255);
      analogWrite(enb, 255);
    }
  }
}


void readSensors() {
  valueLB = sharpLeftBack.distance();
  valueFR = sharpFrontRight.distance();
  valueFL = sharpFrontLeft.distance();
  valueLF = readLeftFront(sharpLeftFront);

  graySclL = analogRead(grSclL);
  graySclR = analogRead(grSclR);

   if (testForVictim(graySclR, graySclL) && !(graySclR > 400 && graySclL > 320)) {
     analogWrite(Piezo,  85);
     lcd.clear();
     lcd.print("ein Opfer mgl.");
    } else {
     analogWrite(Piezo, 0);
     lcd.clear();
     lcd.print("ne doch keins!");
    }

}



void countEncoderLeft() {
  encoderLeft++;
}

void countEncoderRight() {
  encoderRight++;
}

void resetEncoder() {
  encoderLeft = 0;
  encoderRight = 0;
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
      readSensors();
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
readSensors();
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
