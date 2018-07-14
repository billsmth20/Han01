volatile byte command = 0;
byte buf[40]={"asdfghjkl12345678"};
int pos=0;
void setup (void)
{
  Serial.begin (115200);
  // have to send on master in, *slave out*
  pinMode(MISO, OUTPUT);

  // turn on SPI in slave mode
  SPCR |= _BV(SPE);

  // turn on interrupts
  SPCR |= _BV(SPIE);
  attachInterrupt (0, ss_falling, FALLING);
}  // end of setup

void ss_falling ()
{
  command = 0;
  pos=0;
}

// SPI interrupt routine
ISR (SPI_STC_vect)
{
  byte c = SPDR;
  switch (command)
  {
  case 0:
    command = c;
    SPDR = 0;
    break;
  case 'a':
    SPDR=buf[pos++];
    break;
  case 's':
    SPDR = c - 8;  // subtract 8
    break;
  } // end of switch

}  // end of interrupt service routine (ISR) SPI_STC_vect

void loop (void)
{
  
  // if SPI not active, clear current command
//  if (digitalRead (SS) == HIGH)
//    command = 0;
}
