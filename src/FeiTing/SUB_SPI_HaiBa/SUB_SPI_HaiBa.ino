#include <HaiBa.h>

volatile byte command = 0;

const int dataLen=100;
char data[dataLen] ={"abcdesfe123"};
byte pos=0;

void setup (void)
{
  Serial.begin (115200);
  pinMode(MISO, OUTPUT);
  initHaiBa();
  SPCR |= _BV(SPE);
  SPCR |= _BV(SPIE);
  attachInterrupt (0, ss_falling, FALLING);  
}

void ss_falling (){
  command = 0;
}
ISR (SPI_STC_vect)  
{
  byte c = SPDR;
  switch (command)
  {
  case 0:
    command = c;
    SPDR = 0;
    pos=0;
    break;
  case 'a':
    SPDR = data[pos++];
    break;
  case 's':
    SPDR = c - 8;
    break;
  }
}

void loop (void)
{
  String a=getHaiBaStr();
//  Serial.print("HaiBa:");
//  Serial.println(a);
  a.toCharArray(data,a.length()+1);
  data[a.length()]=0;
  // ------Debug------
//  for(int n=a.length();n<dataLen;n++){
//    data[n]=0;
//  }
//  for(int m=0;m<dataLen;m++){
//    Serial.print("[");
//    Serial.print((int)data[m]);
//    Serial.print(":");
//    Serial.write(data[m]);
//    Serial.print("]");
//  }
//  Serial.println();
  // ------Debug------
  delay(3000);
}

