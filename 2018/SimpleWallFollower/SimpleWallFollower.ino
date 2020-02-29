#include "SharpIR.h"
#include "LiquidCrystal_I2C.h"


#define ena 9 //Rechter Motor
#define enb 8
#define IN1 45
#define IN2 44
#define IN3 43
#define IN4 42

#define LCDAddress 0x20
#define LCDCols 20
#define LCDRows 4

#define IRFrontLeft A0  // 1080
#define IRFrontRight A4 // 430
#define IRLeftBack A6   // 430
#define IRLeftFront A1  // 430


#define grSclL A8
#define grSclR A9

LiquidCrystal_I2C lcd(LCDAddress, LCDCols, LCDRows);


SharpIR sharpLeftBack(IRLeftBack, 430);
SharpIR sharpFrontRight(IRFrontRight, 430);
SharpIR sharpFrontLeft(IRFrontLeft, 1080);
SharpIR sharpLeftFront(IRLeftFront, 430);

int valueLB = 0;
int valueFR = 0;
int valueFL = 0;
int valueLF = 0;

int graySclL = 0;
int graySclR = 0;
volatile int encoderLeft = 0;
volatile int encoderRight = 0;

#define LEDRed 13
#define LEDGreen 11
#define Piezo 7

#define LightSensor A3


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

  pinMode(LEDRed, OUTPUT);
  pinMode(LEDGreen, OUTPUT);
  pinMode(LightSensor, INPUT);
  pinMode(Piezo, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(18), countEncoderRight, CHANGE);
  attachInterrupt(digitalPinToInterrupt(2), countEncoderLeft, CHANGE);

  engineForward();
}

void loop() {
  readSensors();


  //überprüfe immer zuerst, ob vorne ein Wand ist!
  if (valueFL < 9 && valueFR < 9) {
    Serial.print("FrontLeft: ");
    Serial.print(valueFL);
    Serial.print(" FrontRight: ");
    Serial.println(valueFR);
    lcd.clear();
    lcd.print("Wand");
    // wir müssen uns nach rechts drehen
    engineLeftForward();
    analogWrite(enb, 255);
    engineRightBackward();
    analogWrite(ena, 255);
    delay(1300);
    lcd.clear();
  }


  // Wenn die linken Sensoren kleiner als 9 sind müssen wir
  // von der linken Wand wegfahren
  // Wenn der linke Sensor kleiner ist als 13 und größer ist
  // als 10, dann soll wieder dichter zur Wand gefahren werden
  lcd.clear();
  if (valueLF < 9) {
    lcd.print("nach rechts");
    engineForward();
    analogWrite(ena, 140);
    analogWrite(enb, 255);
  } else if (valueLF < 13 && valueLF > 10) {
    lcd.print("weiter");
    engineForward();
    analogWrite(ena, 255);
    analogWrite(enb, 255);
  } else {
    lcd.print("links");
    engineForward();
    analogWrite(ena, 255);
    analogWrite(enb, 140);
  }

  // Wenn der linke vordere Sensor keine Wand mehr hat,
  // dann muss nach links abgebogen werden!
  if (valueLF > 17) {
    lcd.clear();
    lcd.print("leer");
    //    while (valueLB < 17) {
    //      readSensors();
    //      engineForward();
    //      analogWrite(ena, 255);
    //      analogWrite(enb, 255);
    //    }
    engineForward();
    analogWrite(ena, 255);
    analogWrite(enb, 255);

    delay(700);



    //wir sind in das Feld eingefahren
    // Drehen!
    lcd.clear();
    lcd.print("drehen");
    // wir müssen uns nach links drehen

    while (encoderLeft < 500 && encoderRight < 500) {

      if (encoderLeft < 500) {
        engineRightForward();
        analogWrite(ena, 255);
      } else engineRightStop();
      if (encoderLeft < 500) {
        engineLeftBackward();
        analogWrite(enb, 255);
      } else engineLeftStop();

    }
    lcd.clear();

    // solange der Hinter Sensor keine Wand sieht vorwärts
    while (valueLB > 17) {
      readSensors();
      if (valueFL < 7) {
        break;
      }
      lcd.clear();
      lcd.print("Ich suche");
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

  if (testForVictim()) {
    analogWrite(Piezo,  15);
  } else {
    analogWrite(Piezo,  0);
  }
}


boolean testForVictim() {
  int sensorValue;
  int tempSensorValueRed;
  int tempSensorValueGreen;

  sensorValue = analogRead(LightSensor);
  Serial.println(sensorValue);

  digitalWrite(LEDRed, LOW);
  digitalWrite(LEDGreen, HIGH);
  sensorValue = 0;
  int i = 10;
  int i2 = i;
  for (; i > 0; i--) {
    sensorValue += analogRead(LightSensor);
  }
  tempSensorValueRed = sensorValue / i2;
  Serial.print("Red: ");
  Serial.println(tempSensorValueRed);
  delay(200);

  digitalWrite(LEDRed, HIGH);
  digitalWrite(LEDGreen, LOW);
  sensorValue = 0;
  int j = 10;
  int j2 = j;
  for (; j > 0; j--) {
    sensorValue += analogRead(LightSensor);
  }
  tempSensorValueGreen = sensorValue / j2;
  Serial.print("Green: ");
  Serial.println(tempSensorValueGreen);
  delay(200);

  digitalWrite(LEDRed, HIGH);
  digitalWrite(LEDGreen, HIGH);

  delay(0);

  if (diff(tempSensorValueRed, tempSensorValueGreen) >= 0) return true;
  else return false;
}


int diff(int compared, int comparing) {
  return compared - comparing;
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



void engineForward() {
  engineLeftForward();
  engineRightForward();
}

void engineBackward() {
  engineLeftBackward();
  engineRightBackward();
}

void engineRightForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
}

void engineLeftForward() {
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void engineRightBackward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
}

void engineLeftBackward() {
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void engineLeftStop() {
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(enb, 0);
}

void engineRightStop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ena, 0);
}


void engineStop() {
  engineLeftStop();
  engineRightStop();
}



int readLeftFront(SharpIR sensor) {
  int sum = 0;
  int n = 10;
  for (int i = 0; i < n; i++) {
    sum += sensor.distance();
  }

  sum /= n;
  //sum /= 2;

  return sum;
}
