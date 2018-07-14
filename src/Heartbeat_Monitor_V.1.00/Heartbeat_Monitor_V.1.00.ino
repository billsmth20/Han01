#include "pitches.h"
#include <NOKIA5110LIB.h>

float distance;
int cnt=0; 
String length;
char buffer[32];

#define inputPin 6
#define timeDelay 500
int heartVal=0;
int count=0;
int stateFlg=0;
unsigned long endTime=0;
 
void setup() 
{   
  Serial.begin(9600);
  pinMode(inputPin,INPUT);
  lcd_init();
} 
void loop() 
{ 
  checkHeartbeat();
  dtostrf(count,1,0,buffer); 
  strcat(buffer," times");
  doDisplay(buffer);
}
void doDisplay(char *buffer){
  
  
  lcd_clear(); 
  lcd_write_english_string(0,0," -Heartbeat- ");
  lcd_write_english_string(25,2,buffer); 
}
