#define inputPin 4
int val=0;
int count=0;
void setup() {
  Serial.begin(9600);
  pinMode(inputPin,INPUT);
}

void loop() {
  val=digitalRead(inputPin);
  if(val==1){
    count++;
    delay(500);
    Serial.print("No:");
    Serial.println(count);
  }
}
