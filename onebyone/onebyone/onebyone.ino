//Pin connected to latch pin (ST_CP) of 74HC595
const int latchPin = 16;
//Pin connected to clock pin (SH_CP) of 74HC595
const int clockPin = 15;
////Pin connected to Data in (DS) of 74HC595
const int dataPin = 14;

void setup() 
{
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop()
{
  //0 = 61
  digitalWrite(latchPin, LOW); // stop data for new data
  shiftOut(dataPin, clockPin, MSBFIRST, 64); // set the data
  digitalWrite(latchPin, HIGH); //send data
  digitalWrite(13, HIGH);
  delay(1000);
  digitalWrite(13, LOW);
  //1 = 121
  digitalWrite(latchPin, LOW); // stop data for new data
  shiftOut(dataPin, clockPin, MSBFIRST, 121); // set the data
  digitalWrite(latchPin, HIGH); //send data
  digitalWrite(13, HIGH);
  delay(1000);
  digitalWrite(13, LOW);
  //2 = 36
  digitalWrite(latchPin, LOW); // stop data for new data
  shiftOut(dataPin, clockPin, MSBFIRST, 36); // set the data
  digitalWrite(latchPin, HIGH); //send data
  digitalWrite(13, HIGH);
  delay(1000);
  digitalWrite(13, LOW);
  //3 = 48
  digitalWrite(latchPin, LOW); // stop data for new data
  shiftOut(dataPin, clockPin, MSBFIRST, 48); // set the data
  digitalWrite(latchPin, HIGH); //send data
  digitalWrite(13, HIGH);
  delay(1000);
  digitalWrite(13, LOW);
  //4 = 25
  digitalWrite(latchPin, LOW); // stop data for new data
  shiftOut(dataPin, clockPin, MSBFIRST, 25); // set the data
  digitalWrite(latchPin, HIGH); //send data
  digitalWrite(13, HIGH);
  delay(1000);
  digitalWrite(13, LOW);
  //5 = 18
  digitalWrite(latchPin, LOW); // stop data for new data
  shiftOut(dataPin, clockPin, MSBFIRST, 18); // set the data
  digitalWrite(latchPin, HIGH); //send data
  digitalWrite(13, HIGH);
  delay(1000);
  digitalWrite(13, LOW);
  //6 = 2
  digitalWrite(latchPin, LOW); // stop data for new data
  shiftOut(dataPin, clockPin, MSBFIRST, 2); // set the data
  digitalWrite(latchPin, HIGH); //send data
  digitalWrite(13, HIGH);
  delay(1000);
  digitalWrite(13, LOW);
  //7 = 120
  digitalWrite(latchPin, LOW); // stop data for new data
  shiftOut(dataPin, clockPin, MSBFIRST, 120); // set the data
  digitalWrite(latchPin, HIGH); //send data
  digitalWrite(13, HIGH);
  delay(1000);
  digitalWrite(13, LOW);
  //8 = 0
  digitalWrite(latchPin, LOW); // stop data for new data
  shiftOut(dataPin, clockPin, MSBFIRST, 0); // set the data
  digitalWrite(latchPin, HIGH); //send data
  digitalWrite(13, HIGH);
  delay(1000);
  digitalWrite(13, LOW);
  //9 = 24
  digitalWrite(latchPin, LOW); // stop data for new data
  shiftOut(dataPin, clockPin, MSBFIRST, 24); // set the data
  digitalWrite(latchPin, HIGH); //send data
  digitalWrite(13, HIGH);
  delay(1000);
  digitalWrite(13, LOW);
  delay(1000);
}
