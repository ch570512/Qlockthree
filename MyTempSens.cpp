/**
   MyTempSens.cpp
   Klasse fuer den Zugriff auf den Temperatursensor LM35 & LM335

   @mc       Arduino
   @autor    Manuel Bracher
   @version  1.0
   @created  30.06.2016
*/

#include "MyTempSens.h"
//#include "Debug.h"
//#include "Configuration.h"

MyTempSens::MyTempSens(byte pin) {
  _pin = pin;
  pinMode(_pin, INPUT);
  _tempSamplesSum = 0;
  _idx = 0;
  _slope = 100;
  _offsetC = 0;
  for (byte i = 0; i < NO_OF_SAMPLES; i++) {
    _tempSamples[i] = 0;
  }
}

void MyTempSens::initLM35() {
  _slope = 100;
  _offsetC = TEMP_OFFSET;
}

void MyTempSens::initLM335() {
  _slope = 100;
  _offsetC = TEMP_OFFSET - 273;
}

byte MyTempSens::getTempC() {
  unsigned long temp = (unsigned long)_tempSamplesSum * 5 * _slope / (1023 * NO_OF_SAMPLES) + _offsetC;
  return temp;
}

void MyTempSens::takeSample() {
  _tempSamplesSum -= _tempSamples[_idx];
  _tempSamples[_idx] = analogRead(_pin);
  _tempSamplesSum += _tempSamples[_idx];
  _idx++;
  if (_idx >= NO_OF_SAMPLES) {
    _idx = 0;
  }
}
