#define wingAnglePin A0
#define wingAngleDiffPin A1
#define powerPin A2
#define btnPowerPin 4
int powerVal; 
int wingAngle=0;
int diffAngle=0;
byte staBuf[4];

void setup() {
  pinMode(wingAnglePin,INPUT);
  pinMode(wingAngleDiffPin,INPUT);
  pinMode(powerPin,INPUT);
  pinMode(btnPowerPin,INPUT);
  Serial.begin(9600);
}

void loop() {
  
  staBuf[0] = digitalRead(btnPowerPin);
  wingAngle = analogRead(wingAnglePin);
  diffAngle = analogRead(wingAngleDiffPin);
  powerVal = analogRead(powerPin);

//  staBuf[1]=map(wingAngle,20,1000,0,180);
//  staBuf[2]=map(diffAngle,20,1000,0,100);
//  staBuf[3]=map(powerVal, 0, 1023, 0, 179);
    staBuf[0]='a';
    staBuf[1]='b';
    staBuf[2]='c';
    staBuf[3]='d';
  for(int i=0;i<4;i++){
    Serial.write(staBuf[i]);
    }
  Serial.println();
  delay(2000);
}
