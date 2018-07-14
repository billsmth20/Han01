
int val;
int ledpin=2;  
boolean flg=false;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(ledpin,OUTPUT );
}

void loop() {
  // put your main code here, to run repeatedly:
  val=Serial.read();
if(val=='R'||flg){
  flg=true;
  digitalWrite(ledpin,HIGH);
  delay(500);
  digitalWrite(ledpin,LOW);
  delay(500);
  Serial.println("First arduino!");
  }
}
