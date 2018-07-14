#include <Adafruit_NeoPixel.h>
#include <avr/pgmspace.h>

// 音频采集针
#define soundPin A4
// 背景杂音阈值输入针
#define potentialPin A5
// 抵消背景杂音阈值led输出针，当抵消背景音后，检测值大于0时，输出高电平，否则为低电平
#define minValLedPin A1
// 音频采集的原始值 0-1023
int val;
int val_G;
int val_B;

// 背景杂音阈值参数 0-1023
int potentialVal=0;
//上一次采集到的音频值（已中和背景杂音）
int oldVal=0;
// 变化率，数值越大灯光的衰败速度越快，建议不要超过15
const int changeRate=10;
const int flashMinVal=10;
Adafruit_NeoPixel strips[8]={
                              
                              Adafruit_NeoPixel(16, 3, NEO_GRB + NEO_KHZ800),
                              Adafruit_NeoPixel(16, 4, NEO_GRB + NEO_KHZ800),
                              Adafruit_NeoPixel(16, 5, NEO_GRB + NEO_KHZ800),
                              Adafruit_NeoPixel(16, 6, NEO_GRB + NEO_KHZ800),
                              Adafruit_NeoPixel(16, 7, NEO_GRB + NEO_KHZ800),
                              Adafruit_NeoPixel(16, 8, NEO_GRB + NEO_KHZ800),
                              Adafruit_NeoPixel(16, 9, NEO_GRB + NEO_KHZ800),
                              Adafruit_NeoPixel(16, 10, NEO_GRB + NEO_KHZ800)
                              };
Adafruit_NeoPixel strip=Adafruit_NeoPixel(16, 3, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(9600);
  pinMode(minValLedPin,OUTPUT);
  digitalWrite(minValLedPin,LOW);
  potentialVal=analogRead(potentialPin);
  Serial.println(potentialVal);
  delay(1000);
  oldVal=200;
}


void loop() {

  val =analogRead(soundPin);
  potentialVal= analogRead(potentialPin);
  Serial.println(val);
  val_B=map(val-potentialVal,0,1023-potentialVal,0,153);
  val_G=map(val-potentialVal,0,1023-potentialVal,204,255);
  val=map(val-potentialVal,0,1023-potentialVal,0,200);
  if(val<=(flashMinVal-15)){
    digitalWrite(minValLedPin,HIGH);
  }else{
    digitalWrite(minValLedPin,LOW);
  }
  if(oldVal<val){
    oldVal=val;
  }
  Serial.print("val:");
  Serial.print(val);
  Serial.print("  oldVal:");
  Serial.println(oldVal);
  //238，199，16 为金黄色
//  action1(238-oldVal,199,oldVal+16);
  action1(255,val_G,val_B);
  if(oldVal>0){
    oldVal-=changeRate;
  }
}
