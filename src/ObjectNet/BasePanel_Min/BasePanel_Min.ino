void setup()
{
  Serial.begin(115200);
  Serial.setTimeout(5000);
  Serial.println("AT+RST");
  delay(2000);
  for (int i=0;i<5;i++){
    if(Serial.find("ready")){
    }else{
      delay(1000);
      i++;
    }
  }
  //connect to the wifi
  boolean connected=false;
  for(int i=0;i<5;i++)
  {
    if(connectWiFi())
    {
      connected = true;
      break;
    }
  }
}

void loop() 
{
  if(!connected){
    setup();
  }
  String cmd = "AT+CIPSTART=\"TCP\",\"127.0.0.1\",8080";
  Serial.println(cmd);
  if(Serial.find("Error")) return;
  
  cmd = "GET http://127.0.0.1:8080/statistics/shown?deviceid=abc&adid=217 HTTP/1.0\r\n\r\n";
  Serial.print("AT+CIPSEND=");
  Serial.println(cmd.length());
  if(Serial.find(">")){
    Serial.print(cmd);
    delay(2000);
  }else{
    Serial.println("AT+CIPCLOSE");
    delay(1000);
    return;
  }
}

boolean connectWiFi(){
  Serial.println("AT+CWMODE=1");
  String cmd="AT+CWJAP=\"Vip_Net\",\"wang943425\"";
  Serial.println(cmd);
  delay(2000);
  if(Serial.find("OK")){
    return true;
  }else{
    return false;
  }
}
