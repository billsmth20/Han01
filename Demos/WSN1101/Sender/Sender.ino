char buf[5];
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  buf[0]='a';
  buf[1]='b';
  buf[2]='c';
  buf[3]='d';
  buf[4]=0;
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("abcd");
  delay(2000);  
}
