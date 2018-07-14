#include <MsTimer2.h>
#include <NOKIA5110LIB.h>
#include <SPI.h>

String comdata = "";
String oldStr="";
char k[50];
String demo="LeFT";

const int dataLen=100;
char data[dataLen];
const int SS1=7 ;
int cnt=0;
int dianyaVal=50;

const int pwm1=6;
const int pin11=14;
//const int pin12=15;

const int pwm2=10;
const int pin21=16;
//const int pin22=17;
const int CON_SPEED=100;


const int downPin=18;
const int risePin=19;

void setup(){
  lcd_init();//初始化液晶 
  Serial.begin(9600);

  pinMode(downPin, OUTPUT);
  pinMode(risePin, OUTPUT);
  
  pinMode(pwm1,OUTPUT);
  pinMode(pin11,OUTPUT);
//  pinMode(pin12,OUTPUT);
  pinMode(pwm2,OUTPUT);
  pinMode(pin21,OUTPUT);
//  pinMode(pin22,OUTPUT);
  
  pinMode (SS1, OUTPUT);
  digitalWrite(SS1, HIGH);
  digitalWrite(downPin, HIGH);
  digitalWrite(risePin, HIGH);
  SPI.begin ();
  SPI.setClockDivider(SPI_CLOCK_DIV128);
  MsTimer2::set(3000,getHeightData);
  MsTimer2::start();
  // 启动动画
  lcd_write_english_string(0,0," --Started-- ");
  delay(3000);
  lcd_clear();
}

void loop(){
  doAction();
//  demo.toCharArray(k,50);
  doDisplay();
  delay (30);
}
byte transferAndWait (const byte what)
{
  byte a = SPI.transfer (what);
  delayMicroseconds (20);
  return a;
}
void doAction(){
  while (Serial.available() > 0)  {
    comdata += char(Serial.read());
    delay(2);
  }
  if (comdata.length() > 0){
    oldStr=comdata;
    oldStr.toCharArray(k,50);
    comdata = "";
  }
  if(oldStr=="BNT-A"){
    digitalWrite(downPin,LOW);
  }else{
    digitalWrite(downPin, HIGH);
  }
  if(oldStr=="BNT-B"){
    digitalWrite(risePin,LOW);
  }else{
    digitalWrite(risePin,HIGH);
  }
  if(oldStr=="FRONT"){
      analogWrite(pwm1,CON_SPEED);
      digitalWrite(pin11,LOW);
//      digitalWrite(pin12,HIGH);

      analogWrite(pwm2,CON_SPEED);
      digitalWrite(pin21,LOW);
//      digitalWrite(pin22,HIGH);
    }else if(oldStr=="BACK"){
      analogWrite(pwm1,CON_SPEED);
      digitalWrite(pin11,HIGH);
//      digitalWrite(pin12,LOW);

      analogWrite(pwm2,CON_SPEED);
      digitalWrite(pin21,HIGH);
//      digitalWrite(pin22,LOW);
    }else if(oldStr=="LEFT"){
      analogWrite(pwm1,CON_SPEED);
      digitalWrite(pin11,HIGH);
//      digitalWrite(pin12,LOW);

      analogWrite(pwm2,CON_SPEED);
      digitalWrite(pin21,LOW);
    }else if(oldStr=="RIGHT"){
      analogWrite(pwm1,CON_SPEED);
      digitalWrite(pin11,LOW);

      analogWrite(pwm2,CON_SPEED);
      digitalWrite(pin21,HIGH);
    }else if(oldStr=="STOP"){
      digitalWrite(pwm1, LOW);
      digitalWrite(pin11, LOW);
      digitalWrite(pwm2, LOW);
      digitalWrite(pin21, LOW);
    }
}
void getHeightData(){
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
//  Serial.print("Results:");
  for(int n=0;n<dataLen&&data[n]!=0;n++){
    Serial.print(data[n]);
  }
//  lcd_write_english_string(0,2,"Height:");
//  lcd_write_english_string(50,2,data);
//  lcd_write_english_string(66,2,"m.");
//  Serial.println();
}
void doDisplay(){
  cnt++;
  if(cnt>30){
    cnt=0;
    lcd_clear();
    lcd_write_english_string(0,0," --Received-- ");
    lcd_write_english_string(1,2,k); 
    lcd_write_english_string(0,4,"Height:");
    lcd_write_english_string(50,4,data);
    lcd_write_english_string(66,4,"m.");
  }
}
