/*
   LedDriverWS2801
*/

#ifndef LED_DRIVER_WS2801_H
#define LED_DRIVER_WS2801_H

#include "Arduino.h"
#include "LedDriver.h"
#include <Adafruit_WS2801.h>

class LedDriverWS2801 : public LedDriver {
  public:
    LedDriverWS2801(byte dataPin, byte clockPin);

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

    byte _brightnessScaleColor(byte brightness, byte colorPart);

    Adafruit_WS2801 *_strip;
};

#endif
