/* Purpose:  Door alarm for the refrigerator
 *        Alerts if fridge door is open with a RED light and 
 *        sounds the alarm if the door has been left open for a period of time
 *  
 *  Hardware Parts:
 *  - arduino nano v3
 *  - piezo buzzer
 *  - red LED
 *  - Magnetic Proximity Contact Switch
 *  - 220 Ohm resistor
 * 
 */

#define LED_PIN 11
#define SWITCH_PIN 12
#define BUZZ_PIN 5
#define DELAY 200

int count = 0;  // counter
int numberOfSecs = 120; // number of seconds to trigger the alarm sound
long triggerValue = (numberOfSecs * 1000L) / DELAY; // using DELAY value, convert the number of seconds to a trigger value used in loop
/*
  With a DELAY of 200 milliseconds in each loop, looping 5 times is about 1000 ms, or 1 second --> (1 / DELAY * 1000 = 5)
  For numberOfSecs of 120s (2 mins), the trigger value is 600 (or 600 loop counts before alarm sounds)
  The equation to generate triggerValue in this example is 120 * (1 / 200) * 1000 = 600
  When loop count reaches 600, it's been 120 secs of open door, sound the alarm
*/

void setup()
{
    // Start the serial connection
    Serial.begin(115200);
    Serial.println("Fridge Door Alarm");
    
    // Initialize pins
    pinMode(LED_PIN, OUTPUT);
    pinMode(SWITCH_PIN, INPUT_PULLUP);
    pinMode(BUZZ_PIN, OUTPUT);
}

void siren() 
{         
  for(int hz = 440; hz < 1000; hz+=25)
  {
    tone(BUZZ_PIN, hz, 50);
    delay(5);
  }
  for(int hz = 1000; hz > 440; hz-=25)
  {
    tone(BUZZ_PIN, hz, 50);
    delay(5);
  }
}

void loop()
{
   int state = digitalRead(SWITCH_PIN);
   if (state)   // Evaluates as TRUE if SWITCH_PIN state is 1 (HIGH)
   {
      // Magnets NOT in proximity and switch is OPEN; Door is ajar
      // Open Switch - SWITCH_PIN input reads HIGH (initial pinMode state of SWITCH_PIN)
      Serial.println("Door is open");
      Serial.print("Count in open door loop is "); Serial.println(count);
      digitalWrite(LED_PIN, HIGH);  // turn the LED ON
      if ( count > triggerValue ) { // sound the alarm if door is open too long
        Serial.println("Alarm Sound!");
        siren();
      }
      count++;
   }
   else   // Evaluates as FALSE if SWITCH_PIN is 0 (LOW)
   {
      // Magnets in proximity and switch is closed - Door is shut
      // Closed switch - circuit connects to ground - SWITCH_PIN input reads LOW
      Serial.println("Door is closed");
      digitalWrite(LED_PIN, LOW); // turn the LED OFF
      Serial.println("Reset counter");      
      count = 0;  // door is closed, reset the counter
   }
   delay(DELAY);
}
