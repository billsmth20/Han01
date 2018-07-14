//void action1(){
////  pwm.setPWM(0, 0, 500);
////  delay(5000);
//
//  pwm.setPWM(1, 0, 300);
//  delay(5000);
//    pwm.setPWM(2, 0, 300);
//    delay(5000);
//    pwm.setPWM(2, 0, 150);
//    delay(5000);
//  
//  pwm.setPWM(1, 0, 150);
//  delay(5000);
//
//  
////  pwm.setPWM(0, 0, 150);
////  delay(5000);
//}

void action1(){
  upPulse(0,500,2000);
  upPulse(1,300,2000);
  upPulse(2,300,2000);
    upPulse(3,300,2000);
    upPulse(4,300,2000);
    upPulse(5,300,2000);
    
    downPulse(5,300,150,2000);
    downPulse(4,300,150,2000);
    downPulse(3,300,150,2000);
  downPulse(2,300,150,2000);
  downPulse(1,300,150,2000);
  downPulse(0,500,150,2000);
}
    

