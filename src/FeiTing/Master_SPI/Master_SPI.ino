#include <SPI.h>

const int dataLen=100;
byte data[dataLen];
const int SS1=7 ;

void setup (void)
{
  Serial.begin (115200);
  pinMode (SS1, OUTPUT);
  digitalWrite(SS1, HIGH);
  SPI.begin ();
  SPI.setClockDivider(SPI_CLOCK_DIV128);
  
}

byte transferAndWait (const byte what)
{
  byte a = SPI.transfer (what);
  delayMicroseconds (20);
  return a;
}

void loop (void)
{ 
  digitalWrite(SS1, LOW);
  transferAndWait ('a');
  transferAndWait (10);
  for(int n=0;n<dataLen;n++){
    data[n] = transferAndWait (10);
    if(data[n]==0){
      break;
    }
  }
  transferAndWait (0);
  digitalWrite(SS1, HIGH);
  Serial.print("Results:");
  for(int n=0;n<dataLen&&data[n]!=0;n++){
    Serial.write(data[n]);
  }
  Serial.println();
  delay (3000);
}
