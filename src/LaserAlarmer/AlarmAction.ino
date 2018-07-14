const int alarmPin = 4; 
const int redLedPin=9;

void alarmAction_setup() {
  pinMode(alarmPin,OUTPUT);
  pinMode(redLedPin,OUTPUT);
  Serial.println("AlarmAction_setup");
}
void alarmAction(){
  
  for(int i=200;i<=800;i++)
  {
    if(i<450){
      analogWrite(redLedPin,map(i, 200, 500, 0, 230));
    }else{
      analogWrite(redLedPin,230);
    }
    tone(alarmPin,i);
    delay(5);
  }
  delay(3000);
  analogWrite(redLedPin,0);
  delay(100);
  for(int i=800;i>=200;i--)
  {
    if(i>450){
      analogWrite(redLedPin,map(800-i, 0, 350, 0, 230));
    }else{
      analogWrite(redLedPin,230);
    }
    tone(alarmPin,i);
    delay(10);
  }
  analogWrite(redLedPin,0);
  delay(100);
}
