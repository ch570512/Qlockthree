/**
   Alarm
   Klasse fuer die Weckfunktion.

   @mc       Arduino/RBBB
   @autor    Christian Aschoff / caschoff _AT_ mac _DOT_ com
   @version  1.1
   @created  22.1.2013
*/

#include "Alarm.h"
#include "Configuration.h"
#include "Debug.h"

/**
   Konstruktor.
*/
Alarm::Alarm(byte speakerPin) : TimeStamp(0, 1, 0, 0, 0, 0) {
  _speakerPin = speakerPin;
  pinMode(_speakerPin, OUTPUT);
  _isActive = false;
  _showAlarmTimeTimer = 0;
}

/**
   Den Weckton einschalten.
*/
void Alarm::buzz(boolean on) {
#ifdef SPEAKER_IS_BUZZER
  if (on) {
    digitalWrite(_speakerPin, HIGH);
    //DEBUG_PRINTLN(F("Buzzz..."));
  } else {
    digitalWrite(_speakerPin, LOW);
  }
#else
  if (on) {
    tone(_speakerPin, SPEAKER_FREQUENCY);
  } else {
    noTone(_speakerPin);
  }
#endif
}

/**
   Die verbleibende Zeit in Sekunden bekommen, fuer die die Weckzeit angezeigt werden soll.
*/
byte Alarm::getShowAlarmTimeTimer() {
  return _showAlarmTimeTimer;
}

/**
   Die Zeit in Sekunden setzten, fuer die die Weckzeit angezeigt werden soll.
*/
void Alarm::setShowAlarmTimeTimer(byte seconds) {
  _showAlarmTimeTimer = seconds;
}

/**
   Die Zeit, fuer die die Weckzeit angezeigt werden soll, um eine Sekunde verringern.
*/
void Alarm::decShowAlarmTimeTimer() {
  if (_showAlarmTimeTimer > 0) {
    _showAlarmTimeTimer--;
  }
}

/**
   Ist der Wecker aktiv?
*/
boolean Alarm::isActive() {
  return _isActive;
}

/**
   Den Wecker einschalten.
*/
void Alarm::activate() {
  _isActive = true;
}

/**
   Den Wecker ausschalten.
*/
void Alarm::deactivate() {
  _isActive = false;
  buzz(false);
}
