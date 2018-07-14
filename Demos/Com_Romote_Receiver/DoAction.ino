// 数据接收后的处理函数
void doAction(){
  // TODO 编写接收的处理函数
  // data[] 是接收到的数据
  Serial.print("Received:");
  Serial.write(data[0]);
  Serial.print("  ");
  Serial.write(data[1]);
  Serial.println("");
}
// 发送程序
void returnMsg(){
  // TODO 编写要发送的数据
  /////////////////////////////
  retData[0]='c';
  if(random(255)>100){
    retData[1]='d';
  }else{
    retData[1]='f';
  }
  Serial.print("Send:");
  Serial.write(retData[0]);
  Serial.print("  ");
  Serial.write(retData[1]);
  Serial.println("");

 /////////////////////////////////// 
  while (Serial.available() > 0)  {
    receiveData += char(Serial.read());
    delay(2);
  }
  if(retData[0]!='0'){
    Mirf.setTADDR((byte *)"Sender01");
    Mirf.send(retData);
    //while死循环等待发送完毕，才能进行下一步操作。
    while(Mirf.isSending()) {}
    retData[0]='0';
  }
}
