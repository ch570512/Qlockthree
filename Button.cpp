/**
   Button
   Kleine Klasse zum Entprellen der Tasten.

   @mc       Arduino/RBBB
   @autor    Christian Aschoff / caschoff _AT_ mac _DOT_ com
   @version  1.7
   @created  18.2.2011
*/

#include "Button.h"
#include "Configuration.h"
#include "Debug.h"

/**
   Initialisierung mit dem Pin, an dem der Taster haengt.

   @param  pin: der Pin, an dem der Taster haengt
           pressedAgainst: wogegen schaltet der Taster? (HIGH/LOW)
*/
Button::Button(byte pin, byte pressedAgainst) {
  _pin1 = pin;
  _lastPressTime = 0;
  _doubleMode = false;
  _pressedAgainst = pressedAgainst;
  if (_pressedAgainst == HIGH) {
    pinMode(_pin1, INPUT);
  } else {
    pinMode(_pin1, INPUT_PULLUP);
  }
}

/**
   Initialisierung mit den zwei Pins, an denen die Taster haengen, die man gleichzeitig abfragen moechte.

   @param  pin1, pin2: die Pins, an dem der virtuelle Taster haengt
           pressedAgainst: wogegen schalten die Taster? (HIGH/LOW)
*/
Button::Button(byte pin1, byte pin2, byte pressedAgainst) {
  _pin1 = pin1;
  _pin2 = pin2;
  _lastPressTime = 0;
  _doubleMode = true;
  _pressedAgainst = pressedAgainst;
  if (_pressedAgainst == HIGH) {
    pinMode(_pin1, INPUT);
    pinMode(_pin2, INPUT);
  } else {
    pinMode(_pin1, INPUT_PULLUP);
    pinMode(_pin2, INPUT_PULLUP);
  }
}

/**
   Wurde der Taster gedrueckt?
*/
boolean Button::pressed() {
  boolean _retVal = false;

  if (!_doubleMode) {
    if ((digitalRead(_pin1) == _pressedAgainst) && (millis() - _lastPressTime > BUTTON_TRESHOLD)) {
      _lastPressTime = millis();
      _retVal = true;
    }
  } else {
    if ((digitalRead(_pin1) == _pressedAgainst) && (digitalRead(_pin2) == _pressedAgainst) && (millis() - _lastPressTime > BUTTON_TRESHOLD)) {
      _lastPressTime = millis();
      _retVal = true;
    }
  }

  return _retVal;
}

/**
   Ist der Taster aktuell gedrueckt?
*/
boolean Button::pressedRaw() {
  boolean _retVal = false;

  if (!_doubleMode) {
    if (digitalRead(_pin1) == _pressedAgainst) {
      _retVal = true;
    }
  } else {
    if ((digitalRead(_pin1) == _pressedAgainst) && (digitalRead(_pin2) == _pressedAgainst)) {
      _retVal = true;
    }
  }

  return _retVal;
}
