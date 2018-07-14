int input1 = 2; // 定义uno的pin 2 向 input1 输出
int input2 = 3; // 定义uno的pin 3 向 input2 输出
int input3 = 4; // 定义uno的pin 4 向 input3 输出
int input4 = 5; // 定义uno的pin 5 向 input4 输出

int input5 = 6; // 定义uno的pin 6 向 input5 输出
int input6 = 7; // 定义uno的pin 7 向 input6 输出
int input7 = 8; // 定义uno的pin 8 向 input7 输出
int input8 = 9; // 定义uno的pin 9 向 input8 输出


void movePart_init(){
  
  pinMode(input1, OUTPUT);
  pinMode(input2, OUTPUT);
  pinMode(input3, OUTPUT);
  pinMode(input4, OUTPUT);

  pinMode(input5, OUTPUT);
  pinMode(input6, OUTPUT);
  pinMode(input7, OUTPUT);
  pinMode(input8, OUTPUT);
}

void stop() {
  //stop 停止
  digitalWrite(input1, LOW);
  digitalWrite(input2, LOW);
  digitalWrite(input3, LOW);
  digitalWrite(input4, LOW);

  digitalWrite(input5, LOW);
  digitalWrite(input6, LOW);
  digitalWrite(input7, LOW);
  digitalWrite(input8, LOW);
  delay(1);
}
void back() {
  //back 向后转
  digitalWrite(input1, LOW);
  digitalWrite(input2, HIGH);
  digitalWrite(input3, LOW);
  digitalWrite(input4, HIGH);

  digitalWrite(input5, LOW);
  digitalWrite(input6, HIGH);
  digitalWrite(input7, LOW);
  digitalWrite(input8, HIGH);
  
  delay(50);
  Serial.println("back");
  stop();
}
//void forwardWithSpeed(int speed) {
//  //forward 向前转
//  analogWrite(input1, speed); //给高电平
//  digitalWrite(input2, LOW); //给低电平
//  analogWrite(input3, speed); //给高电平
//  digitalWrite(input4, LOW); //给低电平
//  delay(50);
//  Serial.println("forwardWithSpeed");
//  stop();
//}
void forward() {
  //forward 向前转
  digitalWrite(input1, HIGH); //给高电平
  digitalWrite(input2, LOW); //给低电平
  digitalWrite(input3, HIGH); //给高电平
  digitalWrite(input4, LOW); //给低电平

  digitalWrite(input5, HIGH); //给高电平
  digitalWrite(input6, LOW); //给低电平
  digitalWrite(input7, HIGH); //给高电平
  digitalWrite(input8, LOW); //给低电平
  
  delay(50);
  Serial.println("forward");
  stop();
}

void turnLeft() {
  digitalWrite(input1, LOW);
  digitalWrite(input2, HIGH); //给低电平
  digitalWrite(input3, HIGH);
  digitalWrite(input4, LOW);

  digitalWrite(input5, HIGH);
  digitalWrite(input6, LOW); //给低电平
  digitalWrite(input7, LOW);
  digitalWrite(input8, HIGH);
  delay(50);
  Serial.println("turnLeft");
  stop();
}
void turnRight() {
  digitalWrite(input1, HIGH);
  digitalWrite(input2, LOW);
  digitalWrite(input3, LOW);
  digitalWrite(input4, HIGH); //给低电平

  digitalWrite(input5, LOW);
  digitalWrite(input6, HIGH);
  digitalWrite(input7, HIGH);
  digitalWrite(input8, LOW); //给低电平
  
  delay(50);
  Serial.println("turnRight");
  stop();
}

void translationLeft() {
  digitalWrite(input1, HIGH);
  digitalWrite(input2, LOW); //给低电平
  digitalWrite(input3, LOW);
  digitalWrite(input4, HIGH);

  digitalWrite(input5, HIGH);
  digitalWrite(input6, LOW); //给低电平
  digitalWrite(input7, LOW);
  digitalWrite(input8, HIGH);
  delay(50);
  Serial.println("turnLeft");
  stop();
}

void translationRight() {
  digitalWrite(input1, LOW);
  digitalWrite(input2, HIGH);
  digitalWrite(input3, HIGH);
  digitalWrite(input4, LOW); //给低电平

  digitalWrite(input5, LOW);
  digitalWrite(input6, HIGH);
  digitalWrite(input7, HIGH);
  digitalWrite(input8, LOW); //给低电平
  
  delay(50);
  Serial.println("turnRight");
  stop();
}

