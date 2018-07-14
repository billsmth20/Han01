#define xInput A3
#define yInput A5
int xOutput = 7;
int yOutput = 8;
int x;
int y;

void setup() {
  // put your setup code here, to run once:
  pinMode(xInput,INPUT);
  pinMode(yInput,INPUT);
  //pinMode(xOutput,OUTPUT);
  //pinMode(yOutput,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  x=analogRead(xInput);
  y=analogRead(yInput);
  //analogWrite(x,xInput);
  //analogWrite(y,yInput);
  Serial.print(x,DEC);
  Serial.print("    ");
  Serial.print(y,DEC);
  Serial.println("");
  delay(10);
}
