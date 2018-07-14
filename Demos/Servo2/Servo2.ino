#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
#define SERVOMIN  150 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  600 // this is the 'maximum' pulse length count (out of 4096)

// our servo # counter
//uint8_t servonum = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("16 channel Servo test!");
  pwm.begin();
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates
  actionReset();
}

void setServoPulse(uint8_t n, double pulse) {
  double pulselength;
  
  pulselength = 1000000;   // 1,000,000 us per second
  pulselength /= 60;   // 60 Hz
  Serial.print(pulselength); Serial.println(" us per period"); 
  pulselength /= 4096;  // 12 bits of resolution
  Serial.print(pulselength); Serial.println(" us per bit"); 
  pulse *= 1000;
  pulse /= pulselength;
  Serial.println(pulse);
  pwm.setPWM(n, 0, pulse);
}

void loop() {
 
}

void upPulse(uint8_t n,int servoMax,uint16_t delayTime){
  Serial.print("up:");
  Serial.println(servoMax,DEC);
  for (uint16_t pulselen = 0; pulselen < servoMax; pulselen++) {
    pwm.setPWM(n, 0, pulselen);
  }
  delay(delayTime);
}
void downPulse(uint8_t n,int servoMax,int servoMin,uint16_t delayTime){
  Serial.print("down from :");
  Serial.print(servoMax,DEC);
  Serial.print(" to :");
  Serial.println(servoMin,DEC);
  for (uint16_t pulselen = servoMax; pulselen > servoMin; pulselen--) {
    pwm.setPWM(n, 0, pulselen);
  }
  delay(delayTime);
}
