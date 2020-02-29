#define ena 8 //Rechter Motor
#define enb 9
#define IN1 45
#define IN2 44
#define IN3 43
#define IN4 42

void setup() {
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
    digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
}

void loop() {
  analogWrite(enb, 255);
  analogWrite(ena, 255);
  delay(1000);

}
