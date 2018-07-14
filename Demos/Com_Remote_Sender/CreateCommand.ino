void createCommand(){
  data[0]='a';
  data[1]='b';
  Serial.print("Send data:");
  Serial.print(data[0]);
  Serial.println(data[1]);
}
