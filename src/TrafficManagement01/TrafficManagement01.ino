
#include "pitches.h"
#include <Servo.h>
Servo myservo;
int Sensor= 2;

const int yellowPin=5;
const int redPin=4;
const int greenPin=6;

const int redPersonPin=12;
const int greenPersonPin=13;

void setup() {
  
  Serial.begin(9600);
  pinMode(Sensor, INPUT);
  pinMode(yellowPin,OUTPUT);
  pinMode(redPin,OUTPUT);
  pinMode(greenPin,OUTPUT);
  pinMode(redPersonPin,OUTPUT);
  pinMode(greenPersonPin,OUTPUT);
  myservo.attach(9);
}

void loop() {
  mode2();
//  delay(5000);  
//  int SensorState = digitalRead(Sensor);
//  Serial.println(SensorState);
  
  
}
void mode2(){
  digitalWrite(redPersonPin,HIGH);
  digitalWrite(greenPersonPin,LOW);
  int SensorState =0;
  for(int i=0;i<5;i++){
    lightLamp(yellowPin,1000);
    SensorState = digitalRead(Sensor);;
    if(SensorState==1){break;}
    delay(500);
  }
  if(SensorState==1){
    tone(8, NOTE_G7);
    delay(50);
    noTone(8);
    lightLamp(yellowPin,3000);
    myservo.write(-90);
    digitalWrite(redPin,HIGH);
    digitalWrite(redPersonPin,LOW);
    digitalWrite(greenPersonPin,HIGH);
    int time=0;
    for(int i=0;i<30;i++){
      tone(8, NOTE_G7);
      delay(300-10*i);
      noTone(8);
      time=600-30*i;
      if(time>0){
         delay(time);
      }
  }
  tone(8, NOTE_G7);
  delay(1000);
  noTone(8);
  digitalWrite(redPin,LOW);
  digitalWrite(redPersonPin,HIGH);
  digitalWrite(greenPersonPin,LOW);

  myservo.write(90);
  lightLamp(greenPin,5000);
  }
  
}
void lightLamp(int pin, int time){
  digitalWrite(pin,HIGH);
  delay(time);
  digitalWrite(pin,LOW);
}
int scanFunction(){
  int val=digitalRead(Sensor);
  Serial.print("val 1:");
  Serial.println(val);
  if(val==1){
    delay(1000);
    for(int j=0;j<3;j++){
      val=digitalRead(Sensor);
      Serial.print("val next:");
      Serial.println(val);
      if(val==1){
        if(j==2){
          return 1;
        }
        delay(1000);
      }else{
        break;
      }
    }
  }
  return val;
}
void mode1(){
  myservo.write(90);
  lightLamp(greenPin,5000);
  for(int i=0;i<3;i++){
    lightLamp(yellowPin,1000);
    if(i!=2){
      delay(500);
    }
  }
  myservo.write(-90);
  digitalWrite(redPin,HIGH);
  int time=0;
  for(int i=0;i<30;i++){
    tone(8, NOTE_G7);
    delay(300-10*i);
    noTone(8);
    time=600-30*i;
    if(time>0){
       delay(time);
    }
  }
  tone(8, NOTE_G7);
  delay(1000);
  noTone(8);
  digitalWrite(redPin,LOW);
}
