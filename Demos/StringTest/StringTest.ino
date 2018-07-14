
struct ColorSpot{
    unsigned char spotType;
    int posIndex;
    unsigned char cl_r;
    unsigned char cl_g;
    unsigned char cl_b;
    int delayTime;
};

void setup()  
{  
    Serial.begin(9600);  
    String str="C,17,247,150,70,0";
    String strc;
    char buffer[30];
    str.toCharArray(buffer,str.length()+1);
    for(int s=0;s<str.length()+1;s++){
      strc+=buffer[s];
    }
    Serial.println(strc);
    struct ColorSpot cs1=getSpot(strc);
    Serial.print("cs1:spotType:");
    Serial.write(cs1.spotType);
    Serial.print(" ");
    Serial.print(cs1.posIndex);
    Serial.print(" ");
    Serial.print(cs1.cl_r);
    Serial.print(" ");
    Serial.print(cs1.cl_g);
}


struct ColorSpot getSpot(String spotStr){
  struct ColorSpot cs;
  int index = 0;
  String temp[6];
  Serial.println(spotStr);  
  for(int struIndex=0;struIndex<6; struIndex++){
    int index2 = spotStr.indexOf(',',index);
    Serial.print(index,DEC);
    Serial.print("  ");
    Serial.print(index2,DEC);
    Serial.print("   struIndex:");
    Serial.println(struIndex);
    temp[struIndex]=spotStr.substring(index,index2);
    Serial.println(temp[struIndex]);
    
    index = index2+1;
  }
  cs.spotType=char(temp[0].charAt(0));
  cs.posIndex=temp[1].toInt();
  cs.cl_r=temp[2].toInt();
  cs.cl_g=temp[3].toInt();
  cs.cl_b=temp[4].toInt();
  cs.delayTime=temp[5].toInt();
  return cs ;
}


void loop()  
{  
    float a=62.6;
    String str2=String(a);
    Serial.println(str2);  
    unsigned long along = 1234213;  
    String str1 = String(along);  
    str1 += "mimi";  
    char cArr[str1.length() + 1];  
    char cArr2[str1.length() + 3];  
    str1.toCharArray(cArr,str1.length() + 1);  
    str1.toCharArray(cArr2,str1.length() + 3);  
    Serial.println(str1);  
    Serial.println(cArr);  
    Serial.println(cArr2);  
    Serial.println(sizeof(str1));  
    Serial.println(sizeof(cArr));  
    Serial.println(sizeof(cArr2));  
    Serial.println(strlen(cArr));  
    Serial.println(strlen(cArr2));  
    if(cArr[str1.length()] == '\0')  
    {  
        Serial.println("cArr1: has ending mark. ");  
    }  
    if(cArr2[str1.length()] == '\0')  
    {  
        Serial.println("cArr2: has ending mark. ");  
    }  
    while(1);  
}  
