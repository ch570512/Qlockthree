/**
   LedDriverDotStar
   Implementierung auf der Basis von APA102-Streifen wie sie die Adafruit-Dot-Stars verwenden.

   @mc       Arduino/RBBB
   @autor    Christian Aschoff / caschoff _AT_ mac _DOT_ com
   @version  1.1
   @created  9.2.2015
*/

#ifndef LED_DRIVER_DOTSTAR_H
#define LED_DRIVER_DOTSTAR_H

#include "Arduino.h"
#include "LedDriver.h"
#include <Adafruit_DotStar.h>

class LedDriverDotStar : public LedDriver {
  public:
    LedDriverDotStar(byte dataPin, byte clockPin);

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

    boolean _dirty;

    void _setPixel(byte x, byte y, uint32_t c);
    void _setPixel(byte num, uint32_t c);

    uint32_t _wheel(byte brightness, byte wheelPos);

    void _clear();

    byte _brightnessScaleColor(byte brightness, byte colorPart);

    Adafruit_DotStar *_strip;
};

#endif
