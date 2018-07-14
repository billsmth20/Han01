int Sensor= 2;
boolean flg=true;
int cnt=0;
void setup() {
   Serial.begin(9600);
   pinMode(Sensor, INPUT);
}
void loop() {
   int SensorState = digitalRead(Sensor);
//   if(SensorState!=1){
//    flg=false;
//    }
//    if(flg){
      Serial.println(SensorState);
//    }else{
//      cnt++;
//      Serial.println(cnt);
//      delay(1000);
//    }
   
   delay(100);      
}
