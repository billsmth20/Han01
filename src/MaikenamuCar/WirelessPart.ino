PS2X ps2x; // create PS2 Controller Class
int error = 0;
byte type = 0;
byte vibrate = 0;
void Vireless_init(){
  error = ps2x.config_gamepad(13,11,10,12, true, true);   //setup pins and settings:  GamePad(clock, command, attention, data, Pressures?, Rumble?) check for error
  if(error == 0){
     Serial.println("Found Controller, configured successful");
     Serial.println("Try out all the buttons, X will vibrate the controller, faster as you press harder;");
    Serial.println("holding L1 or R1 will print out the analog stick values.");
    Serial.println("Go to www.billporter.info for updates and to report bugs.");
  }
  else if(error == 1)
   Serial.println("No controller found, check wiring, see readme.txt to enable debug. visit www.billporter.info for troubleshooting tips");
  else if(error == 2)
   Serial.println("Controller found but not accepting commands. see readme.txt to enable debug. Visit www.billporter.info for troubleshooting tips");
  else if(error == 3)
   Serial.println("Controller refusing to enter Pressures mode, may not support it. ");
   //Serial.print(ps2x.Analog(1), HEX);
   type = ps2x.readType();
     switch(type) {
       case 0:
        Serial.println("Unknown Controller type");
       break;
       case 1:
        Serial.println("DualShock Controller Found");
       break;
       case 2:
         Serial.println("GuitarHero Controller Found");
       break;
     }
}
void WirelessFunction(){
  if(error == 1) //skip loop if no controller found
    return;
  if(type == 2){ //Guitar Hero Controller
     ps2x.read_gamepad();          //read controller
  }else { //DualShock Controller
      ps2x.read_gamepad(false, vibrate);          //read controller and set large motor to spin at 'vibrate' speed
      if(ps2x.Button(PSB_START))                   //will be TRUE as long as button is pressed
        Serial.println("Start is being held");
      if(ps2x.Button(PSB_SELECT))
        Serial.println("Select is being held");
       if(ps2x.Button(PSB_PAD_UP)) {         //will be TRUE as long as button is pressed
         forward();
        }
        if(ps2x.Button(PSB_PAD_RIGHT)){
          turnRight();
        }
        if(ps2x.Button(PSB_PAD_LEFT)){
          turnLeft();
        }
        if(ps2x.Button(PSB_PAD_DOWN)){
          back();
        }
        vibrate = ps2x.Analog(PSAB_BLUE);        //this will set the large motor vibrate speed based on
                                                //how hard you press the blue (X) button   
      if (ps2x.NewButtonState())               //will be TRUE if any button changes state (on to off, or off to on)
      {
        if(ps2x.Button(PSB_L3))
          Serial.println("L3 pressed");
        if(ps2x.Button(PSB_R3))
          Serial.println("R3 pressed");
        if(ps2x.Button(PSB_L2))
          Serial.println("L2 pressed");
        if(ps2x.Button(PSB_R2))
          Serial.println("R2 pressed");
        if(ps2x.Button(PSB_GREEN))
          Serial.println("Triangle pressed");
      }
      if(ps2x.ButtonPressed(PSB_RED)){             //will be TRUE if button was JUST pressed
        Serial.println("Circle just pressed");
        //modelFlg=!modelFlg;
      }
      if(ps2x.ButtonReleased(PSB_PINK)){             //will be TRUE if button was JUST released
        Serial.println("Square just released");
      }  
      if(ps2x.NewButtonState(PSB_BLUE)){            //will be TRUE if button was JUST pressed OR released
        Serial.println("X just changed");
        
      }  
      if(ps2x.Button(PSB_L1)) // print stick values if either is TRUE
      {
        translationLeft();
      }
      if(ps2x.Button(PSB_R1)) // print stick values if either is TRUE
      {
        translationRight();
      }
  }
  delay(10);
}
