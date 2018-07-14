//const char commands[13][12]={"STOP", "FRONT", "BACK", "LEFT", "RIGHT", "FRONT-LEFT", "FRONT-RIGHT", "BACK-LEFT", "BACK-RIGHT", "BNT-A", "BNT-B", "BNT-C", "BNT-D"};
//
//int cnt=0;
//char *curCmd;
//void doDisplay(){
//  cnt++;
//  if(cnt>15){
//    cnt=0;
//    directStr();
//    lcd_clear(); 
//    lcd_write_english_string(0,0," --Micro Car-- ");
//    lcd_write_english_string(0,2,curCmd); 
////    lcd_write_english_string(0,4,"Height: ");  
////    lcd_write_char(dataOld[0]); 
////    lcd_write_char(dataOld[1]); 
////    lcd_write_english_string(66,4,"m.");
//  }
//}
//void directStr(){
//  switch (data[1]){
//    case 48:
//      curCmd=commands[0];
//      break;
//    case 24:
//      curCmd=commands[1];
//      break;
//    case 25:
//      curCmd=commands[2];
//      break;
//    case 26:
//      curCmd=commands[3];
//      break;
//    case 27:
//      curCmd=commands[4];
//      break;
//    case 49:
//      curCmd=commands[5];
//      break;
//    case 50:
//      curCmd=commands[6];
//      break;
//    case 51:
//      curCmd=commands[7];
//      break;
//    case 52:
//      curCmd=commands[8];
//      break;
//    case 53:
//      curCmd=commands[9];
//      break;
//    case 54:
//      curCmd=commands[10];
//      break;
//    case 55:
//      curCmd=commands[11];
//      break;
//    case 56:
//      curCmd=commands[12];
//      break;
//  }
//}
