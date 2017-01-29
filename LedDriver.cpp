/**
   LedDriver
   Abstrakte Klasse fuer einen LED-Treiber. Hiervon koennen andere Implementierungen
   erben (75HC595, MAX7219, AS1130 etc.)

   @mc       Arduino/RBBB
   @autor    Christian Aschoff / caschoff _AT_ mac _DOT_ com
   @version  1.5
   @created  18.1.2013
*/

#include "LedDriver.h"
#include "Debug.h"

void LedDriver::setPixelInScreenBuffer(byte x, byte y, word matrix[16]) {
  matrix[y] |= 0b1000000000000000 >> x;
}

void LedDriver::unsetPixelInScreenBuffer(byte x, byte y, word matrix[16]) {
  matrix[y] = ~matrix[y];
  matrix[y] |= 0b1000000000000000 >> x;
  matrix[y] = ~matrix[y];
}

boolean LedDriver::getPixelFromScreenBuffer(byte x, byte y, word matrix[16]) {
  return (matrix[y] & (0b1000000000000000 >> x)) == (0b1000000000000000 >> x);
}

void LedDriver::demoTransition() {
  _demoTransition = true;
}

void LedDriver::resetWheelPos() {
  _wheelPos = 0;
  _lastColorUpdate = millis();
}

