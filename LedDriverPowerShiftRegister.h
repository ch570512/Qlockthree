/**
   LedDriverPowerShiftRegister
   Implementierung auf der Basis von TPICB595N.

   @mc       Arduino/RBBB
   @autor    Christian Aschoff / caschoff _AT_ mac _DOT_ com
   @version  1.3
   @created  13.8.2013
*/

#ifndef LED_DRIVER_POWER_SHIFT_REGISTER_H
#define LED_DRIVER_POWER_SHIFT_REGISTER_H

#include "Arduino.h"
#include "LedDriver.h"
#include "ShiftRegister.h"

class LedDriverPowerShiftRegister : public LedDriver {
  public:
    LedDriverPowerShiftRegister(byte data, byte clock, byte latch, byte outputEnable);

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

    byte _outputEnable;

    ShiftRegister *_shiftRegister;
};

#endif
