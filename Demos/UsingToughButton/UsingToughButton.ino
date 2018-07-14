int inputVal=A4;
int val=0;
int oldVal=0;
void setup() {

  Serial.begin(9600);
  pinMode(inputVal,INPUT);
}

void loop() {
  oldVal=val;
  val=analogRead(inputVal);
  if(val!=oldVal){
    Serial.print("VAL:");
    Serial.println(val);
    oldVal=val;
    delay(10);
  }
}
