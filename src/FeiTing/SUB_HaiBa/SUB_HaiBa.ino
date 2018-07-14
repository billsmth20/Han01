
#include <HaiBa.h>

void setup(){
  Serial.begin(9600);
  
  initHaiBa();
}

void loop()
{
  Serial.println(getHaiBaStr());
}


