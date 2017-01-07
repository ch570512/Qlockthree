/**
   LDR
   Klasse fuer den Zugriff auf einen lichtabhaengigen Widerstand.

   @mc       Arduino/RBBB
   @autor    Christian Aschoff / caschoff _AT_ mac _DOT_ com
   @version  1.8
   @created  18.3.2012
*/

#include "LDR.h"
#include "Debug.h"

/**
   Initialisierung mit dem Pin, an dem der LDR haengt.
   Die Maximalwerte vom LDR koennen automatisch
   eingemessen werden (LDR_AUTOSCALE).
   Ansonsten muss man diese Werte im #define-DEBUG-Mode
   ausmessen und eintragen.
*/
LDR::LDR(byte pin, boolean isInverted) {
  _pin = pin;
  _isInverted = isInverted;
  _lastValue = 1;
  _outputValue = 0;

#ifdef LDR_AUTOSCALE
  _min = 1023;
  _max = 0;
#else
  _min = LDR_MANUAL_MIN;
  _max = LDR_MANUAL_MAX;
#endif
}

/**
   Welchen Wert hat der LDR? In Prozent...
*/
byte LDR::value() {
  int rawVal, val;
  if (!_isInverted) {
    rawVal = analogRead(_pin);
  }
  else {
    rawVal = (1023 - analogRead(_pin));
  }

  if ((rawVal != _lastValue) && ((rawVal == 0) || (rawVal == 1023) || (rawVal > (_lastValue + LDR_HYSTERESE) || (rawVal < _lastValue - LDR_HYSTERESE)))) {
    val = rawVal;
    _lastValue = val;

#ifdef LDR_AUTOSCALE
    if (val < _min) {
      _min = val;
    }
    if (val > _max) {
      _max = val;
    }
#else
    val = constrain(val, _min, _max);
#endif

    byte mapVal = map(val, _min, _max, 0, 100);
    mapVal = constrain(mapVal, LDR_MIN_PERCENT, LDR_MAX_PERCENT);
    _outputValue = mapVal;

#ifdef DEBUG_LDR
    DEBUG_PRINT(F("rawVal: "));
    DEBUG_PRINT(rawVal);
    DEBUG_PRINT(F(" val: "));
    DEBUG_PRINT(val);
    DEBUG_PRINT(F(" _min: "));
    DEBUG_PRINT(_min);
    DEBUG_PRINT(F(" _max: "));
    DEBUG_PRINT(_max);
    DEBUG_PRINT(F(" mapValue: "));
    DEBUG_PRINTLN(mapVal);
#endif

  }
  return _outputValue;
}

