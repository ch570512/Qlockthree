/**
   LDR
   Klasse fuer den Zugriff auf einen lichtabhaengigen Widerstand.

   @mc       Arduino/RBBB
   @autor    Christian Aschoff / caschoff _AT_ mac _DOT_ com
   @version  1.8
   @created  18.3.2012
*/

#ifndef LDR_H
#define LDR_H

#include "Arduino.h"
#include "Configuration.h"

class LDR {
  public:
    LDR(byte pin, boolean isInverted);

    byte value();

  private:
    byte _pin;
    boolean _isInverted;
    int _lastValue;
    byte _outputValue;
    int _min;
    int _max;
};

#endif
