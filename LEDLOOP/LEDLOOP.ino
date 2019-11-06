
/*
 * A random (between 1 and 4) number of leds follow the leader
 */
#include <HC595.h>

const int chipCount = 1;  // Number of serialy connected 74HC595 (8 maximum)
const int latchPin = 16;  // Pin ST_CP (12) of the 74HC595
const int clockPin = 15;  // Pin SH_CP (11) of the 74HC595
const int dataPin = 14;   // Pin DS (14) of the 74HC595

const int sensorpins[] = {18,19,20};

float arrf[24];
int arr[24];

//Constructor
HC595 ledArray(chipCount,latchPin,clockPin,dataPin);

int powerLength = 50;
int delayBetweenPowers = 50;
int lastPin = ledArray.lastPin();

float analogValue;
float voltageValue;

void setup() {
  for (int i = 0; i <= 2; i++) {
    pinMode(sensorpins[i], INPUT);
  }
  ledArray.reset();
}

void loop() {
  for(int i = 0 ; i <= lastPin ; i++) {
    ledArray.setPin(i, ON);
    delay(powerLength);
    
    for (int j = 0; j <= 2; j++) 
    {
       analogValue = analogRead(sensorpins[j]);
       voltageValue = analogValue * (3.3 / 1023.0);
       if (voltageValue > 2.60 && voltageValue < 3.6)
       {
          arr[(i * 3) + j] = 1; // use arrf for float values
       }
       else
       {
          arr[(i * 3) + j] = 0; // use arrf for float values
       }

      //arr[(i * 3) + j] = voltageValue;
       
    }
    ledArray.setPin(i, OFF);
    delay(delayBetweenPowers);
  }
  for (int k = 0; k <= 23; k++)
  {
    Serial.print(arr[k]);
    //Serial.print("-");
    if (k % 3 == 2)
    {
      Serial.print(", ");
    }
  }
  Serial.println("");
}
