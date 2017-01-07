/**
   Button
   Kleine Klasse zum Entprellen der Tasten.

   @mc       Arduino/RBBB
   @autor    Christian Aschoff / caschoff _AT_ mac _DOT_ com
   @version  1.7
   @created  18.2.2011
*/

#ifndef BUTTON_H
#define BUTTON_H

#include "Arduino.h"

class Button {
  public:
    Button(byte pin, byte pressedAgainst);
    Button(byte pin1, byte pin2, byte pressedAgainst);

    boolean pressed();
    boolean pressedRaw();

  private:
    byte _pin1;
    byte _pin2;
    boolean _doubleMode;
    byte _pressedAgainst;
    unsigned long _lastPressTime;
};

#endif
