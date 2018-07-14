char ss;
int led1Pin=8;
void setup()
{
Serial.begin(9600);
pinMode(led1Pin,OUTPUT);
}
void loop()
{
  if (Serial.available()) {
    ss=Serial.read();
    
    Serial.print(ss);

    if(ss=='a') {
      digitalWrite(led1Pin, HIGH);
      ss=0;
      delay(2000);
      digitalWrite(led1Pin, LOW);
    }
    Serial.print('b');//收到‘a'后向主机发一个’b'
    delay(3000);
    Serial.print('c');
    delay(3000);
  }
}
