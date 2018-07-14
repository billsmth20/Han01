void checkHeartbeat(){
  heartVal = digitalRead(inputPin);

  if(endTime < millis() && stateFlg == 1){
    stateFlg = 2;
    endSound();
  }

  if(heartVal == 1 && stateFlg != 2){
    if(stateFlg == 0){
      stateFlg = 1;
      endTime = millis()+60000;
    }
    count++;
    delay(timeDelay);
    Serial.print("No:");
    Serial.println(count);
    sound();
  }
}
