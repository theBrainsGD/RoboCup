void setup() {
  // put your setup code here, to run once:

}

void loop() {
  lcd.clear();
  if(analogRead(SensorVVR) > 260) {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    analogWrite(ML, 255);
    
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(MR, 255);
    
    lcd.setCursor(0,3);
  lcd.print("drehen");
  
  } else {//"ander wand dranher langeln" - Malte 2015
    digitalWrite(in1, HIGH);
    digitalWrite(in2, HIGH);
    analogWrite(ML, 255);
    
    digitalWrite(in3, HIGH);
    digitalWrite(in4, HIGH);
    analogWrite(MR, 255);
    lcd.setCursor(0,3);
  lcd.print("fahren");
  }

}
