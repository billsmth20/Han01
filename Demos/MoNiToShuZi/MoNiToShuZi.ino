int degital_1=3;
int valueAnalog=0;
int valueDegital=0;
void setup() {
  Serial.begin(9600);
  pinMode(degital_1,OUTPUT);
  digitalWrite(degital_1,LOW);
}

void loop() {
  
  valueAnalog = analogRead(A0);
  valueDegital = digitalRead(A0);
  Serial.print("Analog Val:");
  Serial.println(valueAnalog);
  Serial.print("Degital Val:");
  Serial.println(valueDegital);
  delay(1000);
}
