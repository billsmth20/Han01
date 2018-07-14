void doAction(byte d){

  if(d==53){
    Serial.println("BNT-A");
    AUTO_DRIVE=!AUTO_DRIVE;
    Serial.print("DRIVE Mode Changed :");
    Serial.println(AUTO_DRIVE?"AUTO":"MANUAL");
  // 按钮B
  }else if(d==54){
    Serial.println("BNT-B");
    AUTO_DRIVE=false;
    Serial.println("B:DRIVE Mode Changed");
    Serial.println("B:MANUAL DRIVE");
  }
  if(!AUTO_DRIVE){
    // 停
    if(d==48){
      Serial.println("STOP");
      stop();
    // 向前
    }else if(d==24){
      Serial.println("FRONT");
      forward();
    // 向后
    }else if(d==25){
      Serial.println("BACK");
      back();
    // 向左
    }else if(d==26){
      Serial.println("LEFT");
      turnLeft();
    // 向右
    }else if(d==27){
      Serial.println("RIGHT");
      turnRight();
    // 向左前
    }else if(d==49){
      Serial.println("FRONT-LEFT");
    // 向右前
    }else if(d==50){
      Serial.println("FRONT-RIGHT");
    // 向左后
    }else if(d==51){
      Serial.println("BACK-LEFT");
    // 向右后
    }else if(d==52){
      Serial.println("BACK-RIGHT");
    // 按钮A
    }
  }
//  else{
//    // 停
//    Serial.println("STOP");
//    stop();
//  }
}
void autoDrive(){
  if(AUTO_DRIVE){
    destince = checkDestince(100);
    Serial.print(destince);
    Serial.print(" cm");
    Serial.println();
    if (destince >= 50) {
      forwardWithSpeed(150);
    } else if (destince >= 20) {
      forwardWithSpeed(50);
    } else if (destince >= 5) {
      turnRight();
    } else {
      back();
    }
  }
}
void manualDrive(String command){
  if(command=="FORWARD"){
    forwardWithSpeed(CNT_SPEED);
  }else if(command=="LEFT"){
    turnLeft();
  }else if(command=="RIGHT"){
    turnRight();
  }else if(command=="STOP"){
    stop();
  }else{
    stop();
  }
  delayMicroseconds(2);
}
void checkCommand(){
  if(data[0]==15){
    Serial.print("Directon:");
//    Serial.println();
    doAction(data[1]);
  }else{
    stop();
  }
}
void stop() {
  //stop 停止
  digitalWrite(input1, LOW);
  digitalWrite(input2, LOW);
  digitalWrite(input3, LOW);
  digitalWrite(input4, LOW);
  delayMicroseconds(2);
}
void back() {
  //back 向后转
  digitalWrite(input1, LOW);
  digitalWrite(input2, HIGH);
  digitalWrite(input3, LOW);
  digitalWrite(input4, HIGH);
  delayMicroseconds(2);
}
void forwardWithSpeed(int speed) {
  //forward 向前转
  analogWrite(input1, speed); //给高电平
  digitalWrite(input2, LOW); //给低电平
  analogWrite(input3, speed); //给高电平
  digitalWrite(input4, LOW); //给低电平
  delayMicroseconds(2);
}
void forward() {
  //forward 向前转
  digitalWrite(input1, HIGH); //给高电平
  digitalWrite(input2, LOW); //给低电平
  digitalWrite(input3, HIGH); //给高电平
  digitalWrite(input4, LOW); //给低电平
  delayMicroseconds(2);
}

void turnLeft() {
  analogWrite(input1, CNT_SPEED); //给高电平
  digitalWrite(input2, LOW); //给低电平
  digitalWrite(input3, LOW);
  analogWrite(input4, CNT_SPEED);
  delayMicroseconds(2);
}
void turnRight() {
  digitalWrite(input1, LOW);
  analogWrite(input2, CNT_SPEED);
  analogWrite(input3, CNT_SPEED); //给高电平
  digitalWrite(input4, LOW); //给低电平
  delayMicroseconds(2);
}
