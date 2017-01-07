/**
   LedDriverDefault
   Implementierung auf der Basis 74HC595 und UDN2981A.

   @mc       Arduino/RBBB
   @autor    Christian Aschoff / caschoff _AT_ mac _DOT_ com
   @version  1.4
   @created  18.1.2013
*/

#ifndef LED_DRIVER_DEFAULT_H
#define LED_DRIVER_DEFAULT_H

#include "Arduino.h"
#include "ShiftRegister.h"
#include "LedDriver.h"

class LedDriverDefault : public LedDriver {
  public:
    LedDriverDefault(byte data, byte clock, byte latch, byte outputEnable, byte linesToWrite);

    void init();

    void printSignature();

    void writeScreenBufferToMatrix(word matrix[16], boolean onChange, eColors a_color = color_none);

    void setBrightness(byte brightnessInPercent);
    byte getBrightness();

    void setLinesToWrite(byte linesToWrite);

    void shutDown();
    void wakeUp();

    void clearData();

  private:
    byte _brightnessInPercent;

    byte _linesToWrite;

    byte _outputEnablePin;

    ShiftRegister *_shiftRegister;
    unsigned int _delayOldMatrix;
    unsigned int _delayNewMatrix;
};

#endif
