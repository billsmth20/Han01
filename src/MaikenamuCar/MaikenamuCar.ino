#include <PS2X_lib.h>  //for v1.6


int CNT_SPEED=230;
boolean modelFlg=false;
float distance;

void setup(){
  Serial.begin(57600);
  Vireless_init();
  initUltrasonic();
  movePart_init();
}
void loop(){
  WirelessFunction();
  if(modelFlg){
    checkDistance();
    if(distance<40){
      turnRight();
    }else{
      forward();
    }
  }
   
}
