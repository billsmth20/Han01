#include <NOKIA5110LIB.h>
#include <SoftwareSerial.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#define SSID        "Vip_Net"
#define PASS        "wang943425"
#define DST_IP      "192.168.1.101"//"www.microams.com"

#define redPin 11
#define greenPin 6
#define bluePin 8
#define RED_COLOR 1
#define YELLOW_COLOR 2
#define GREEN_COLOR 3
#define BLUE_COLOR 5

int INTERVAL_TIME = 60; //单位 秒
#define ONE_WIRE_BUS 10 // 定义DS18B20数据口连接arduino的10号IO上

OneWire oneWire(ONE_WIRE_BUS); // 初始连接在单总线上的单总线设备
DallasTemperature sensors(&oneWire);

//SoftwareSerial dbgSerial(10, 11); // RX, TX
char buffer[64];
char lengthBuf[10];
String temperature;
String tmpStr;
void setup(){
  
  Serial.begin(115200);
  Serial.setTimeout(10000);
  
  pinMode(redPin,OUTPUT);
  pinMode(greenPin,OUTPUT);
  pinMode(bluePin,OUTPUT);
  
  initFunction();
}

void loop(){
  mainFunction();
}

void initFunction(){
  
  //初始化液晶
  lcd_init(); 
  // 初始库
  sensors.begin();
  flashColor(RED_COLOR);
  printInfor("Function Init!",100);
  //test if the module is ready
  Serial.println("AT+RST");
  delay(3000);
  
  if(Serial.find("ready")){
    
    printInfor("Module is ready",1000);
  }else{
    
    printInfor("Module no response.",1000);
  //    while(1);
  }
  
  //connect to the wifi
  boolean connected=false;
  
  for(int i=0;i<5;i++){
    
    if(connectWiFi()){
      
      connected = true;
      break;
    }
  }
  if (!connected){
    
    //while(1);
    setup();
  }
  
  delay(5000);
  //print the ip addr
  Serial.println("AT+CIFSR");
  printInfor("ip address:",1000);
  
  //set the single connection mode
  Serial.println("AT+CIPMUX=0");
  printInfor("Init complete!",1000);
  flashColor(GREEN_COLOR);
}
void mainFunction(){
  flashColor(BLUE_COLOR);
  printInfor("Loop next cycle!",1000);
  String cmd = "AT+CIPSTART=\"TCP\",\"";
  cmd += DST_IP;
  cmd += "\",8080";
  Serial.println(cmd);
  printInfor(cmd,1000);
  if(Serial.find("Error")){ return;}
  sensors.requestTemperatures();
  temperature=String(sensors.getTempCByIndex(0));
  printInfor("Temperature:"+temperature,2000);
  cmd = "GET http://192.168.1.101:8080/ams/objectnet/collect.action?deviceId=e857c9f2-dc3e-447d-9add-baffda4bfcec&data1="+temperature+"&data2=40 HTTP/1.0\r\n\r\n";
  Serial.print("AT+CIPSEND=");
  Serial.println(cmd.length());
  dtostrf(cmd.length(),1,0,lengthBuf); 
  strcat(buffer,"Cmd length:");
  strcat(buffer,lengthBuf);
  printInfor(buffer,1000);
  if(Serial.find(">")){
    
    printInfor(">",1000);
  }else{
    
    Serial.println("AT+CIPCLOSE");
    printInfor("connect timeout",1000);
    initFunction();
  }
  printInfor(cmd,1000);
  Serial.print(cmd);
  flashColor(GREEN_COLOR);
  flashColor(BLUE_COLOR);
  //Serial.find("+IPD");
  tmpStr="";
  while (Serial.available()){
    
    char c = Serial.read();
    //dbgSerial.write(c);
    if(c=='\r') break;
    tmpStr=tmpStr+String(c);
  }
  printInfor(tmpStr,2000);
  
  printInfor("Data send complete!",2000);
  printInfor("Temperature:"+temperature+", waiting for next loop",2000);
  flashColor(YELLOW_COLOR,INTERVAL_TIME);
}
boolean connectWiFi(){
  
  Serial.println("AT+CWMODE=1");
  String cmd="AT+CWJAP=\"";
  cmd+=SSID;
  cmd+="\",\"";
  cmd+=PASS;
  cmd+="\"";
  printInfor(cmd,1000);
  Serial.println(cmd);
  delay(2000);
  
  if(Serial.find("OK")){
    
    printInfor("OK, Connected to WiFi.",100);
    return true;
  }else{
    
    printInfor("Can not connect to the WiFi.",100);
    return false;
  }
}
