/*
   LedDriverLPD8806
*/

#ifndef LED_DRIVER_LPD8806_H
#define LED_DRIVER_LPD8806_H

#include "Arduino.h"
#include "LedDriver.h"

#ifdef RGB_LEDS
#include <LPD8806.h>
#endif
#if defined(RGBW_LEDS) || defined(RGBW_LEDS_CLT2)
#include <LPD8806RGBW.h>
#endif

class LedDriverLPD8806 : public LedDriver {
  public:
    LedDriverLPD8806(byte dataPin, byte clockPin);

    void init();

    void printSignature();

    void writeScreenBufferToMatrix(word matrix[16], boolean onChange, eColors a_color);

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

    unsigned int _lastLEDsOn;

#ifdef RGB_LEDS
    LPD8806 *_strip;
#endif
#if defined(RGBW_LEDS) || defined(RGBW_LEDS_CLT2)
    LPD8806RGBW *_strip;
#endif

};

#endif

