#include <SoftwareSerial.h>
    
    SoftwareSerial dbgSerial(10, 11); // RX, TX
  // put your setup code here, to run once:

void setup()  
{
  dbgSerial.begin(9600);  //can't be faster than 19200 for softserial
  //dbgSerial.println("ESP8266 Demo");

  
}

void loop() {
  dbgSerial.println("test message");
}
