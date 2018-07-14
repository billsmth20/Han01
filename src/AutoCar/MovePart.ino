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
  analogWrite(input2, CNT_SPEED);
//  digitalWrite(input2, HIGH);
  digitalWrite(input3, LOW);
  analogWrite(input4, CNT_SPEED);
//  digitalWrite(input4, HIGH);
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
void forwardWithSpeed() {
  //forward 向前转
  analogWrite(input1, CNT_SPEED); //给高电平
  digitalWrite(input2, LOW); //给低电平
  analogWrite(input3, CNT_SPEED); //给高电平
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

void left() {
  analogWrite(input1, CNT_SPEED); //给高电平
  digitalWrite(input2, LOW); //给低电平
  digitalWrite(input3, LOW);
  analogWrite(input4, CNT_SPEED);
  delayMicroseconds(2);
}
void right() {
  digitalWrite(input1, LOW);
  analogWrite(input2, CNT_SPEED);
  analogWrite(input3, CNT_SPEED); //给高电平
  digitalWrite(input4, LOW); //给低电平
  delayMicroseconds(2);
}
