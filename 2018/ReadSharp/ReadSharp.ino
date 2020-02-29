void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
}

void loop() {
  Serial.println(getValue(10));
  delay(500);
}



float getValue(int n) {
  int* nums = new int[n];
  for (int i = 0; i < n; i++) {
    nums[i] = analogRead(A0);
  }
  int minimum = 10000;
  int minIndex = 0;
  int maximum = 0;
  int maxIndex = 0;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    if (nums[i] < minimum) {
      minimum = nums[i];
      minIndex = i;
    } else if (nums[i] > maximum) {
      maximum = nums[i];
      maxIndex = i;
    }
  }

  for (int i = 0; i < n; i++) {
    if (i != minIndex && i != maxIndex) {
      sum += nums[i];
    }
  }
  float result = sum / n;//(n * 1.0);
  return result;
}
