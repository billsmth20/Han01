  // Written by Nick Gammon
// April 2011


#include <SPI.h>
byte buf[40];
int pos=0;
void setup (void)
{
  Serial.begin (115200);
  Serial.println ();
  
  digitalWrite(SS, HIGH);  // ensure SS stays high for now

  // Put SCK, MOSI, SS pins into output mode
  // also put SCK, MOSI into LOW state, and SS into HIGH state.
  // Then put SPI hardware into Master mode and turn SPI on
  SPI.begin ();

  // Slow down the master a bit
    SPI.setClockDivider(SPI_CLOCK_DIV8);
  
}  // end of setup

byte transferAndWait (const byte what)
{
  byte a = SPI.transfer (what);
  delayMicroseconds (20);
  return a;
} // end of transferAndWait

void loop (void)
{
  pos=0;
  byte c='r';
  
  // enable Slave Select
  Serial.println ("Start:");
  digitalWrite(SS, HIGH);
  delayMicroseconds (20);
  digitalWrite(SS, LOW);    
  transferAndWait ('a');  // add command
  for(;pos<40;){
    buf[pos++]=transferAndWait (0);
  }
//  do{
//    buf[pos]=transferAndWait (0);
//     Serial.write (buf[pos]);
//  }while(pos<40&buf[pos++]);
  Serial.println ("Exit while");
  
  // disable Slave Select
  digitalWrite(SS, HIGH);

  Serial.print ("Buf:");
  for(int i=0;i<pos;i++){
    Serial.write (buf[i]);
  }
  pos=0;
  Serial.println();
  
//  Serial.println ("Adding results:");
//  Serial.write(a);
//  Serial.println (a, DEC);
//  Serial.write(b);
//  Serial.println (b, DEC);
//  Serial.write(c);
//  Serial.println (c, DEC);
//  Serial.write(d);
//  Serial.println (d, DEC);

  delay (4000);  // 1 second delay 
}  // end of loop
