void actionReset(){
  upPulse(1,220,2000);//大臂向上
  upPulse(2,210,2000);//肘伸直
  upPulse(0,300,2000);//肩正前
  upPulse(3,150,2000);//手腕伸直
  upPulse(4,800,1000);//手腕转90°
  upPulse(4,400,1000);//手腕复位
  upPulse(4,800,1000);//手腕转90°
  upPulse(4,400,1000);//手腕复位
  upPulse(5,300,1000);//夹子合紧
  upPulse(5,100,800);//夹子张开
  upPulse(5,300,800);//夹子合紧
  upPulse(5,100,800);//夹子张开
  upPulse(5,300,800);//夹子合紧
//  downPulse(0,500,150,2000);
}
