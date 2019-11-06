
/*
 * A random (between 1 and 4) number of leds follow the leader
 */
#include <HC595.h>

const int chipCount = 1;  // Number of serialy connected 74HC595 (8 maximum)
const int latchPin = 16;  // Pin ST_CP (12) of the 74HC595
const int clockPin = 15;  // Pin SH_CP (11) of the 74HC595
const int dataPin = 14;   // Pin DS (14) of the 74HC595

int pinled = 13;

int startbutton = 12;
int exitbutton = 11;

bool oldSwitchState = false;
bool newSwitchState = false;

bool oldSwitchState2 = false;
bool newSwitchState2 = false;

bool LEDstatus = false;
bool LEDstatus2 = false;

const int sensorpins[] = {18,19,20};

float arrf[24];
int arr[24];

int checkervalue = 0;

int checks[5][24];

//Constructor
HC595 ledArray(chipCount,latchPin,clockPin,dataPin);

int powerLength = 50;
int delayBetweenPowers = 50;
int lastPin = ledArray.lastPin();

float analogValue;
float voltageValue;

void setup() {
  Serial.begin(9600);

  pinMode(pinled, OUTPUT);  
  digitalWrite(pinled,LOW); 
  
  pinMode(startbutton, INPUT); 
  pinMode(exitbutton, INPUT); 
  
  for (int i = 0; i <= 2; i++) {
    pinMode(sensorpins[i], INPUT);
  }
  ledArray.reset();
}

void checkStartButton()
{
  newSwitchState = digitalRead(startbutton);
  
  if ( newSwitchState != oldSwitchState ) 
  {
    if ( newSwitchState == HIGH )
    {
      if ( LEDstatus == LOW ) 
      { 
        digitalWrite(pinled, HIGH);  LEDstatus = HIGH; 
      }
      else                    
      { 
        digitalWrite(pinled, LOW);   LEDstatus = LOW;  
      }
    }
    oldSwitchState = newSwitchState;
  } 
}

void checkExitButton()
{
  newSwitchState2 = digitalRead(exitbutton);
  
  if ( newSwitchState2 != oldSwitchState2 ) 
  {
    if ( newSwitchState2 == HIGH )
    {
      if ( LEDstatus2 == LOW ) 
      { 
        digitalWrite(pinled, HIGH);  LEDstatus2 = HIGH; 
      }
      else                    
      { 
        digitalWrite(pinled, LOW);   LEDstatus2 = LOW;  
      }
    }
    oldSwitchState2 = newSwitchState2;
  } 
}

void fillarray()
{
  for(int i = 0 ; i <= lastPin ; i++) {
    ledArray.setPin(i, ON);
    delay(powerLength);
    for (int j = 0; j <= 2; j++) 
    {
       analogValue = analogRead(sensorpins[j]);
       voltageValue = analogValue * (3.3 / 1023.0);
       if (voltageValue > 2.60 && voltageValue < 3.6)
       {
          checks[checkervalue][(i * 3) + j] = 2; // use arrf for float values
       }
       else
       {
          checks[checkervalue][(i * 3) + j] = 1; // use arrf for float values
       }
    }
    ledArray.setPin(i, OFF);
    delay(delayBetweenPowers);
  }
}

void fixandprintarray()
{
  if (checkervalue >= 4) 
  {
    for (int n = 0; n <= 23; n++)
    {
      arr[n] = ((checks[0][n] + checks[1][n] + checks[2][n] + checks[3][n] + checks[4][n]) / 5);
      checks[0][n] = checks[1][n] = checks[2][n] = checks[3][n] = checks[4][n] = 0;
    }
    for (int k = 0; k <= 23; k++)
    {
      Serial.print(arr[k]);
      //Serial.print("-");
      if (k % 3 == 2)
      {
        Serial.print(",");
      }
      arr[k] = 0;
    }
    Serial.println("");
    Serial.flush();
    delay(50);
    checkervalue = 0;
  }
  else
  {
    checkervalue++;
  }
}

void loop() {
  checkStartButton();
  checkExitButton();
  fillarray();
  checkStartButton();
  checkExitButton();
  fixandprintarray();
  checkStartButton();
  checkExitButton();
}
