//#include <FastLED.h>
//
//#define LED_PIN     5
//#define COLOR_ORDER GRB
//#define CHIPSET     WS2812
//#define NUM_LEDS    8
//
//#define BRIGHTNESS  200
//#define FRAMES_PER_SECOND 30
//
//bool gReverseDirection = false;
//
//CRGB leds[NUM_LEDS];
//CRGBPalette16 gPal;
//void action4_setUp(){  
//  delay(3000); // sanity delay
//  FastLED.addLeds<CHIPSET, 2, COLOR_ORDER>(leds, 8).setCorrection( TypicalLEDStrip );
//  FastLED.addLeds<CHIPSET, 3, COLOR_ORDER>(leds, 8).setCorrection( TypicalLEDStrip );
//  FastLED.addLeds<CHIPSET, 4, COLOR_ORDER>(leds, 8).setCorrection( TypicalLEDStrip );
//  FastLED.addLeds<CHIPSET, 5, COLOR_ORDER>(leds, 8).setCorrection( TypicalLEDStrip );
//  FastLED.addLeds<CHIPSET, 6, COLOR_ORDER>(leds, 8).setCorrection( TypicalLEDStrip );
//  FastLED.addLeds<CHIPSET, 7, COLOR_ORDER>(leds, 8).setCorrection( TypicalLEDStrip );
//  FastLED.addLeds<CHIPSET, 8, COLOR_ORDER>(leds, 8).setCorrection( TypicalLEDStrip );
//  FastLED.addLeds<CHIPSET, 9, COLOR_ORDER>(leds, 8).setCorrection( TypicalLEDStrip );
//  FastLED.addLeds<CHIPSET, 10, COLOR_ORDER>(leds, 8).setCorrection( TypicalLEDStrip );
//  FastLED.addLeds<CHIPSET, 11, COLOR_ORDER>(leds, 8).setCorrection( TypicalLEDStrip );
//  FastLED.addLeds<CHIPSET, 12, COLOR_ORDER>(leds, 8).setCorrection( TypicalLEDStrip );
//  FastLED.addLeds<CHIPSET, 13, COLOR_ORDER>(leds, 8).setCorrection( TypicalLEDStrip );
//  FastLED.addLeds<CHIPSET, 14, COLOR_ORDER>(leds, 8).setCorrection( TypicalLEDStrip );
//  FastLED.addLeds<CHIPSET, 15, COLOR_ORDER>(leds, 8).setCorrection( TypicalLEDStrip );
//  FastLED.addLeds<CHIPSET, 16, COLOR_ORDER>(leds, 8).setCorrection( TypicalLEDStrip );
//  FastLED.addLeds<CHIPSET, 17, COLOR_ORDER>(leds, 8).setCorrection( TypicalLEDStrip );
//  FastLED.setBrightness( BRIGHTNESS );
//  gPal = HeatColors_p;
//}
//void action4(){
//  random16_add_entropy( random());
//  Fire2012WithPalette(); // run simulation frame, using palette colors
//  
//  FastLED.show(); // display this frame
//  FastLED.delay(1000 / FRAMES_PER_SECOND);
//}
//
//// Fire2012 by Mark Kriegsman, July 2012
//// as part of "Five Elements" shown here: http://youtu.be/knWiGsmgycY
////// 
//// This basic one-dimensional 'fire' simulation works roughly as follows:
//// There's a underlying array of 'heat' cells, that model the temperature
//// at each point along the line.  Every cycle through the simulation, 
//// four steps are performed:
////  1) All cells cool down a little bit, losing heat to the air
////  2) The heat from each cell drifts 'up' and diffuses a little
////  3) Sometimes randomly new 'sparks' of heat are added at the bottom
////  4) The heat from each cell is rendered as a color into the leds array
////     The heat-to-color mapping uses a black-body radiation approximation.
////
//// Temperature is in arbitrary units from 0 (cold black) to 255 (white hot).
////
//// This simulation scales it self a bit depending on NUM_LEDS; it should look
//// "OK" on anywhere from 20 to 100 LEDs without too much tweaking. 
////
//// I recommend running this simulation at anywhere from 30-100 frames per second,
//// meaning an interframe delay of about 10-35 milliseconds.
////
//// Looks best on a high-density LED setup (60+ pixels/meter).
////
////
//// There are two main parameters you can play with to control the look and
//// feel of your fire: COOLING (used in step 1 above), and SPARKING (used
//// in step 3 above).
////
//// COOLING: How much does the air cool as it rises?
//// Less cooling = taller flames.  More cooling = shorter flames.
//// Default 55, suggested range 20-100 
//#define COOLING  55
//
//// SPARKING: What chance (out of 255) is there that a new spark will be lit?
//// Higher chance = more roaring fire.  Lower chance = more flickery fire.
//// Default 120, suggested range 50-200.
//#define SPARKING 120
//
//
//void Fire2012WithPalette()
//{
//// Array of temperature readings at each simulation cell
//  static byte heat[NUM_LEDS];
//
//  // Step 1.  Cool down every cell a little
//    for( int i = 0; i < NUM_LEDS; i++) {
//      heat[i] = qsub8( heat[i],  random8(0, ((COOLING * 10) / NUM_LEDS) + 2));
//    }
//  
//    // Step 2.  Heat from each cell drifts 'up' and diffuses a little
//    for( int k= NUM_LEDS - 1; k >= 2; k--) {
//      heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
//    }
//    
//    // Step 3.  Randomly ignite new 'sparks' of heat near the bottom
//    if( random8() < SPARKING ) {
//      int y = random8(7);
//      heat[y] = qadd8( heat[y], random8(160,255) );
//    }
//
//    // Step 4.  Map from heat cells to LED colors
//    for( int j = 0; j < NUM_LEDS; j++) {
//      // Scale the heat value from 0-255 down to 0-240
//      // for best results with color palettes.
//      byte colorindex = scale8( heat[j], 240);
//      CRGB color = ColorFromPalette( gPal, colorindex);
//      int pixelnumber;
//      if( gReverseDirection ) {
//        pixelnumber = (NUM_LEDS-1) - j;
//      } else {
//        pixelnumber = j;
//      }
//      leds[pixelnumber] = color;
//    }
//}
