/********************************************************* 
 This sketch demonstrates the use of a watchdog timer.
 The watchdog timer causes a processor reset to occur if
 it is allowed to time out. When the sketch is running
 inside the second while loop, the watch dog timer is
 consistently reset to prevent a timeout. When PB0 is 
 pulled high, it breaks out of the while loop and causes 
 the watch dog timer to reset the processor.
 ********************************************************/ 

#include <avr/io.h>
#include <util/delay.h>
#include <avr/wdt.h>

// Variable to store the counted value (uint16_t = unsigned int)
uint16_t counter = 0;

#define CHARLIE_A 0
#define CHARLIE_B 1
#define CHARLIE_C 2
byte randomLed = 0;

void setup ()
 {
// resetWatchdog ();  // do this first in case WDT fires
 pinMode(3, INPUT_PULLUP);
 pinMode(4, INPUT_PULLUP);
 pinMode(5, INPUT_PULLUP);
 pinMode(CHARLIE_A, OUTPUT);
 pinMode(CHARLIE_B, OUTPUT);
 pinMode(CHARLIE_C, OUTPUT);
// ADCSRA |= (1<<ADEN); //Enable ADC
 //randomSeed (analogRead (0));    // randomize
 ADCSRA &= ~(1<<ADEN); //Disable ADC, saves ~230uA
 }  // end of setup

void loop()
{
 
  //randomLed = random (1,7);  
  for (int i=0;i<=7;i++)
  {
   randomLEDs(i);
   wdt_enable(WDTO_1S); // Enable WDT with 1 second timeout
   _delay_ms(200);
   wdt_reset(); // 
  }

}


 void randomLEDs(int n)
{
//    pinMode(CHARLIE_A, OUTPUT); 
//    digitalWrite(CHARLIE_A, LOW);
//    pinMode(CHARLIE_B, OUTPUT); 
//    digitalWrite(CHARLIE_B, LOW);
//    pinMode(CHARLIE_C, OUTPUT); 
//    digitalWrite(CHARLIE_C, LOW);
//    
//
//    if(n==lastLED)
//    {
//      n = random(0, lastLED-1);
//    }
  switch(n)
   {
    case 1 :
       
       // LIGHT 1 
      //turn on LED L1
      pinMode(CHARLIE_A, OUTPUT);     //row 1
      digitalWrite(CHARLIE_A, LOW);
      pinMode(CHARLIE_B, OUTPUT);     //row 2
      digitalWrite(CHARLIE_B, HIGH);  
      pinMode(CHARLIE_C, INPUT);      //row 3
      digitalWrite(CHARLIE_C, LOW);
      
    break;
    case 2 :
    // LIGHT 2 
    //turn on LED L2
    pinMode(CHARLIE_A, OUTPUT);     //row 1
    digitalWrite(CHARLIE_A, HIGH);
    pinMode(CHARLIE_B, OUTPUT);     //row 2
    digitalWrite(CHARLIE_B, LOW);   
    pinMode(CHARLIE_C, INPUT);      //row 3
    digitalWrite(CHARLIE_C, LOW);
    
    break;
    case 3:
    // LIGHT 3
    pinMode(CHARLIE_A, INPUT);      //row 1
    digitalWrite(CHARLIE_A, LOW);
    pinMode(CHARLIE_B, OUTPUT);     //row 2
    digitalWrite(CHARLIE_B, LOW);  
    pinMode(CHARLIE_C, OUTPUT);     //row 3
    digitalWrite(CHARLIE_C, HIGH);
    
    break;
    case 4:
    // LIGHT 4 
    pinMode(CHARLIE_A, INPUT);     //row 1
    digitalWrite(CHARLIE_A, LOW);
    pinMode(CHARLIE_B, OUTPUT);    //row 2
    digitalWrite(CHARLIE_B, HIGH);  
    pinMode(CHARLIE_C, OUTPUT);    //row 3
    digitalWrite(CHARLIE_C, LOW);

    break;
    case 5:
    // LIGHT 5 
    pinMode(CHARLIE_A, OUTPUT);    //row 1
    digitalWrite(CHARLIE_A, LOW);
    pinMode(CHARLIE_B, INPUT);     //row 2
    digitalWrite(CHARLIE_B, LOW);
    pinMode(CHARLIE_C, OUTPUT);    //row3
    digitalWrite(CHARLIE_C, HIGH);
    
    break;
    case 6:
    // LIGHT 6 
    pinMode(CHARLIE_A, OUTPUT);
    digitalWrite(CHARLIE_A, HIGH);
    pinMode(CHARLIE_B, INPUT);
    digitalWrite(CHARLIE_B, LOW);
    pinMode(CHARLIE_C, OUTPUT);
    digitalWrite(CHARLIE_C, LOW);
    
    break;
//    default:
//     pinMode(CHARLIE_A, INPUT); 
//     pinMode(CHARLIE_B, INPUT); 
//     pinMode(CHARLIE_C, INPUT); 
   }

   //lastLED = n;
}
