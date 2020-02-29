int pwm=ena; int forward=A_IN_1; int reverse=A_IN_B;


int encoderValue=0; void count(void); void setup()

{

Serial.begin(9600);

pinMode(21,INPUT);

attachInterrupt(2,count,FALLING);

encoderValue=0;

}

void loop()

{

digitalWrite(pwm,1);

digitalWrite(forward,0);

analogWrite(reverse,140);

Serial.print("Starting\n");

delay(3000); Serial.print("Encoder Value="); Serial.println(encoderValue); while(1)

{
 


// to print encoder value on the screen Serial.print("Encoder Value="); Serial.println(encoderValue); //Setting value of encoder

//defining the while statement condition if(encoderValue<5000)

break; // loop will break as soon as encoder value reaches 5000 or above digitalWrite(forward,1);

digitalWrite(reverse,0);

analogWrite(pwm,150);

}

digitalWrite(forward,1);

digitalWrite(reverse,1);

analogWrite(pwm,255);

}

void count()

{

encoderValue++;

}
