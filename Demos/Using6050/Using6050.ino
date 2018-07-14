/*
*@Author: TONYLABS
*@Date: 2012.12.23
*/

//@引入 Wire.h 头文件，下面的 I2Cdev.h 依赖于它
#include "Wire.h"

//@I2Cdev 和 MPU6050 类库需要事先安装在 Arduino 类库文件夹下
//@引入 I2Cdev.h 头文件
#include "I2Cdev.h"

//@引入
#include "MPU6050_6Axis_MotionApps20.h"

//@实例化一个 MPU6050 对象，对象名称为 mpu
MPU6050 mpu(0x68);

//@ 声明 MPU6050 控制和状态变量
bool dmpReady = false;  //@set true if DMP init was successful
uint8_t mpuIntStatus;   //@此变量用于保存 MPU6050 中断状态
uint8_t devStatus;      //@返回设备状态，0为成功，不为0则发生错误
uint16_t packetSize;    // expected DMP packet size (default is 42 bytes)
uint16_t fifoCount;     // count of all bytes currently in FIFO
uint8_t fifoBuffer[64]; // FIFO storage buffer

//@声明方向和运动变量：
Quaternion q;           //@四元数变量 W,X,Y,Z
VectorFloat gravity;    //@重力矢量 X，Y, Z
float ypr[3];           // [yaw, pitch, roll]   yaw/pitch/roll container and gravity vector

// ================================================================
// =========================== 中断检测程序 =========================
// ================================================================

volatile bool mpuInterrupt = false;     // indicates whether MPU interrupt pin has gone high
void dmpDataReady()
{
  mpuInterrupt = true;
}

// ================================================================
// =============== 初始设置 凡 Arduino 代码都有 setup() ===============
// ================================================================

void setup()
{
  Serial.begin(115200); //@开启串口，设置波特率为 115200，程序下载到 Arduino 之后注意打开串口观察

  //@加入 I2C 总线序列
  Wire.begin();

  //@初始化MPU6050
  Serial.println("Initializing I2C devices...");
  mpu.initialize();

  //@验证连接
  Serial.println("Testing device connections...");
  Serial.println(mpu.testConnection() ? "MPU6050 connection successful" : "MPU6050 connection failed");

  delay(2); //@延时2毫秒

  //@加载并配置 DMP 数字运动处理引擎
  Serial.println("Initializing DMP...");
  devStatus = mpu.dmpInitialize(); //@返回 DMP 状态结果，0为成功，不为0则发生错误

  //@如果成功返回 0
  if (devStatus == 0)
  {
    //@使能 DMP 数字运动处理引擎
    Serial.println("Enabling DMP...");
    mpu.setDMPEnabled(true);

    //@使能 Arduino 中断检测
    Serial.println("Enabling interrupt detection (Arduino external interrupt 0)...");
    attachInterrupt(0, dmpDataReady, RISING);
    mpuIntStatus = mpu.getIntStatus();

    // set our DMP Ready flag so the main loop() function knows it's okay to use it
    Serial.println("DMP ready! Waiting for first interrupt...");
    dmpReady = true;

    // get expected DMP packet size for later comparison
    packetSize = mpu.dmpGetFIFOPacketSize();
  }
  else {
    // ERROR!
    // 1 = initial memory load failed
    // 2 = DMP configuration updates failed
    // (if it's going to break, usually the code will be 1)
    Serial.print("DMP Initialization failed (code ");
    Serial.print(devStatus);
    Serial.println(")");
  }
}

// ================================================================
// =========================== 主循环程序体 =========================
// ================================================================

void loop()
{
  float alpha, omiga; //@声明2个浮点数变量， alpha 和 omiga

  //@如果 MPU6050 的 DMP 状态为错误，程序停止工作
  if (!dmpReady)
    return;

  // wait for MPU interrupt or extra packet(s) available
  if (!mpuInterrupt && fifoCount < packetSize)
    return;

  // reset interrupt flag and get INT_STATUS byte
  mpuInterrupt = false;
  mpuIntStatus = mpu.getIntStatus();

  // get current FIFO count
  fifoCount = mpu.getFIFOCount();

  // check for overflow (this should never happen unless our code is too inefficient)
  if ((mpuIntStatus & 0x10) || fifoCount == 1024) {
    // reset so we can continue cleanly
    mpu.resetFIFO();
    Serial.println("FIFO overflow!");

    // otherwise, check for DMP data ready interrupt (this should happen frequently)
  }
  else if (mpuIntStatus & 0x02) {
    // wait for correct available data length, should be a VERY short wait
    while (fifoCount < packetSize) fifoCount = mpu.getFIFOCount();

    // read a packet from FIFO
    mpu.getFIFOBytes(fifoBuffer, packetSize);

    // track FIFO count here in case there is > 1 packet available
    // (this lets us immediately read more without waiting for an interrupt)
    fifoCount -= packetSize;

    mpu.dmpGetQuaternion(&q, fifoBuffer);
    mpu.dmpGetGravity(&gravity, &q);
    mpu.dmpGetYawPitchRoll(ypr, &q, &gravity);  //@从DMP中取出Yaw, Pitch, Roll三个轴的角度，放入数组ypr。单位：弧度
    alpha=-ypr[2] * 180/M_PI;

    omiga=mpu.getRotationX()/16.4; //@配置是16位表示正负2000°/s, 65536/4000

    Serial.print("Alpha ");
    Serial.print(alpha);
    Serial.print("\tOmiga ");
    Serial.println(omiga);

  }
}
