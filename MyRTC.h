/**
   MyRTC
   Klasse fuer den Zugriff auf die DS1307/DS3231 Echtzeituhr.

   @mc       Arduino/RBBB
   @autor    Christian Aschoff / caschoff _AT_ mac _DOT_ com
   @version  2.1
   @created  1.3.2011
*/

#ifndef MYRTC_H
#define MYRTC_H

#include "Arduino.h"
#include "TimeStamp.h"

class MyRTC : public TimeStamp {
  public:
    MyRTC(int address, byte statusLedPin);

    void statusLed(boolean on);

    void readTime();
    void writeTime();
    int8_t getTemperature();

    void enableSQWOnDS1307();
    void enableSQWOnDS3231();

    void setSeconds(byte seconds);

    byte getSeconds();

  private:
    int _address;
    byte _statusLedPin;

    byte _seconds;

    byte decToBcd(byte val);
    byte bcdToDec(byte val);
    uint8_t conv2d(const char* p);
};

#endif
