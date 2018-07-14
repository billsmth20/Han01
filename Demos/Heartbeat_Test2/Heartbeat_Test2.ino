#include "pitches.h"

int ledPin=13;
int sensorPin=0;

double alpha=0.75;
int period =20;
double change=0.0;
unsigned long endtime=0;
boolean beepflg=true;

void setup(){
  pinMode(ledPin,OUTPUT);
  Serial.begin(115200);
}

void loop(){

  static double oldVal=0;
  static double oldChange =0;
  int rawValue= analogRead(sensorPin);
  double value=alpha*oldVal+(1-alpha)* rawValue;

  Serial.print(rawValue);
  Serial.print(",");
  Serial.println(value);
  
  if(oldVal>value&&beepflg){
    endtime=millis()+50;
    beepflg=false;
    tone(8, NOTE_G7);
  }else if(value>oldVal&&!beepflg){
    beepflg=true;
  }
  
  if(millis()>endtime&&!beepflg){
    noTone(8);
  }
  oldVal=value;
  
  delay(period);
}
