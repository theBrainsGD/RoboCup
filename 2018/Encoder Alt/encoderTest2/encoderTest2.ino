int ENA = 9;      //pwm Port um Geschwindigkeit zu regeln
int IN1 = 30;     //digitaler Port für die Drehrichtung
int IN2 = 31;     //digitaler Port für die Drehrichtung
int encoder1 = 2; //interrupt port um einen Interrupt zu erkennen
int encoder2 = 3; //interrupt port um einen Interrupt zu erkennen

volatile int encoder_val_1;   //volatile int, um den Interrupt zu vermerken
volatile int encoder_val_2;   //volatile int, um den Interrupt zu vermerken

void setup() {
  Serial.begin(9600);

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(encoder1), count1, CHANGE);
  attachInterrupt(digitalPinToInterrupt(encoder2), count2, CHANGE);

  encoder_val_1 = 0;
  encoder_val_2 = 0;

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
}

/*
  void loop() {
  if (encoder_val_1 > 720) {
    encoder_val_1 = 0;
  }

  if (encoder_val_1 < 360) {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
  }
  else
  {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
  }
  analogWrite(ENA, 120);
  }
*/


void loop() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  int encoder_now = encoder_val_1;
  while (encoder_val_1 < encoder_now + 355) {
    analogWrite(ENA, 255);
    //Serial.print("Der Encoderwert ist: ");
    //Serial.println(encoder_val_1);
  }
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, 255);
  delay(50);
  analogWrite(ENA, 0);

  if (encoder_val_1 > 1000) {
    encoder_val_1 = 0;
  }
  delay(1000);


}

void count1() {
  encoder_val_1++;
}

void count2() {
  encoder_val_2++;
}
