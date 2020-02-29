#define TACHO0 2
#define TACHO1 3
#define TACHO2 18
#define TACHO3 19

void setup() {
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(TACHO0), countTACHO0, CHANGE);
  attachInterrupt(digitalPinToInterrupt(TACHO1), countTACHO1, RISING);
  attachInterrupt(digitalPinToInterrupt(TACHO2), countTACHO2, CHANGE);
  attachInterrupt(digitalPinToInterrupt(TACHO3), countTACHO3, FALLING);
}

void countTACHO0() {
  Serial.println("LEFT");
}


void countTACHO1() {
  Serial.println("TACHO1");
}

void countTACHO2() {
  Serial.println("RIGHT");
}

void countTACHO3() {
  Serial.println("TACHO3");
}

void loop() {
  // put your main code here, to run repeatedly:

}
