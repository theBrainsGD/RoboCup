int ENA = 9;
int in1 = 5;
int in2 = 8;
volatile int encoder_val_1 = 0;
volatile int encoder_val_2 = 0;
int encoders1 = 3;
int encoders2 = 2;



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(encoders1), count, CHANGE);
  attachInterrupt(digitalPinToInterrupt(encoders2), count2, CHANGE);
  encoder_val_1 = 0;
  encoder_val_2 = 0;
  Serial.print("Starting \n");
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Encoder Value 1: "); Serial.println(encoder_val_1);
  Serial.print("Encoder Value 2: "); Serial.println(encoder_val_2);
}

void count() {
  encoder_val_1++;
}

void count2() {
  encoder_val_2++;
}
