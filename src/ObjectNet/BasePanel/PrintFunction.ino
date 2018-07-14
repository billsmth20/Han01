void printInfor(String str, int delayTime){
  
  str.toCharArray(buffer,64);
  doDisplay(buffer);
  delay(delayTime);
}
void printInfor(char buffer[], int delayTime){
  
  doDisplay(buffer);
  delay(delayTime);
}
