int sumVal=0;
int subVal=0;
void wingAction(int wingAng, int wingAngDiff){
  wingAng=map(wingAng,0,15,0,180);
  wingAngDiff=map(wingAngDiff,0,15,-50,50);
  sumVal=wingAng+wingAngDiff;
  subVal=wingAng-wingAngDiff;
  if(sumVal>180){
    sumVal=180;
  }
  if(subVal<0){
    subVal=0;
  }
  servoWingLeft.write(sumVal); 
  servoWingRight.write(180-subVal); 
}
