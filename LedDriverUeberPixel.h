/**
   LedDriverUeberPixel
   Implementierung auf der Basis von 4 MAX7219 wie es der Ueberpixel verwendet.

   @mc       Arduino/RBBB
   @autor    Christian Aschoff / caschoff _AT_ mac _DOT_ com
   @version  1.4
   @created  18.1.2013
*/

#ifndef LED_DRIVER_UEBERPIXEL_H
#define LED_DRIVER_UEBERPIXEL_H

#include "Arduino.h"
#include <LedControl.h>
#include "LedDriver.h"

class LedDriverUeberPixel : public LedDriver {
  public:
    LedDriverUeberPixel(byte data, byte clock, byte load);

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
    void _setPixel(byte x, byte y, boolean state);

    byte _brightnessInPercent;

    LedControl *_ledControl;
};

#endif
