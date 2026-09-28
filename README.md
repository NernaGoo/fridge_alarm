# Fridge Alarm

A refrigerator alarm that illuminates a red LED and activates a piezo buzzer if the door is left open

## Overview

Much to my chagrin, I would often leave my refrigerator door slightly ajar without realizing it. This lets the cool air out, which eventually makes the food bad and the household sad. Unfortunately, my fridge did not already come with an alarm feature. 

I needed a simple solution. This was it. Use a microcontroller to detect the door is open when the connection of a magnetic proximity contact switch is broken.

If the refrigerator door is open, a RED led light turns on. If the door is closed, the RED light turns off. An alarm will beep if the door is still open after a set number of seconds has passed. Nothing fancy.


## Hardware

| Parts                     
| ------------------------------
| Arduino Nano V3
| Piezo buzzer
| Red LED
| 220Ω resistor
| [Magnetic proximity/reed switch](https://www.sparkfun.com/magnetic-door-switch-set.html)
| [Solder-able Breadboard - Mini](https://www.sparkfun.com/sparkfun-solder-able-breadboard-mini.html)
| Jumper wires
| 


## Software

### Requirements

* Arduino IDE
* Arduino UNO board package

### Configuration

Pin Definitions:
```cpp
#define LED_PIN 11
#define SWITCH_PIN 12
#define BUZZ_PIN 5
```

Number of seconds to trigger the alarm:
```cpp
 int numberOfSecs = 120;
```
---

## Circuit Diagram

### Fritzing Diagram

![Fritzing Circuit Diagram](images/fridge_alarm_bb.png)

---

## Uploading the Software

1. Connect the Arduino UNO board to the computer using USB.

2. Open the project in the Arduino IDE.

3. Select:

   **Tools → Board → Arduino Uno**

4. Select the appropriate serial port.

5. Compile the sketch.

6. Upload the sketch to the Arduino.

---

