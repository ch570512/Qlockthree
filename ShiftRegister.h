/**
 * ShiftRegister
 * Mit der ShiftRegister-Klasse wird das Ausgeben der Bitmuster auf die
 * 74HC595-Shift-Register gekapselt.
 *
 * @mc       Arduino/RBBB
 * @autor    Christian Aschoff / caschoff _AT_ mac _DOT_ com
 * @version  1.7
 * @created  24.2.2011
 */

#ifndef SHIFTREGISTER_H
#define SHIFTREGISTER_H

#include "Arduino.h"

class ShiftRegister {
  public:
    ShiftRegister(byte dataPin, byte clockPin, byte latchPin);

    void shiftOut(word data);
    void shiftOutABit(boolean bitIsSet);
    void prepareShiftregisterWrite();
    void finishShiftregisterWrite();

  private:
    // slow version
    byte _dataPin;
    byte _clockPin;
    byte _latchPin;

    // fast version
    uint8_t _dataBit;
    uint8_t _dataPort;
    volatile uint8_t *_dataOut;

    uint8_t _clockBit;
    uint8_t _clockPort;
    volatile uint8_t *_clockOut;

    uint8_t _latchBit;
    uint8_t _latchPort;
    volatile uint8_t *_latchOut;

    void fastDigitalWriteToData(uint8_t val);
    void fastDigitalWriteToClock(uint8_t val);
    void fastDigitalWriteToLatch(uint8_t val);
};

#endif
