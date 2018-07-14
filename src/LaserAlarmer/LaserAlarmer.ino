const int alarmSignPin=7;
int laserVal=1;
boolean alarmFlg=false;
void setup() {
  Serial.begin(9600);
  pinMode(alarmSignPin,INPUT);
  Serial.println("setup");
  alarmAction_setup();
}

void loop() {
  laserVal=digitalRead(alarmSignPin);
  if(laserVal==0){
    alarmFlg=true;
  }
  if(alarmFlg){
    Serial.println(alarmFlg);
    alarmAction();
  }
}
