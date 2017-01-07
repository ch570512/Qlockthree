/**
   DCF77Helper
   Klasse um die Qualitaet der DCF77-Samples zu verbessern. Dazu wird der Minutenabstand
   zwischen den empfangenen DCF77-Samples mit Hilfe der Echtzeituhr verglichen.

   @mc       Arduino/RBBB
   @autor    Christian Aschoff / caschoff _AT_ mac _DOT_ com
   @version  1.8a
   @created  19.3.2011
*/

#include "DCF77Helper.h"
#include "Debug.h"

/**
   Initialisierung und das Array 'falsch' vorbelegen, damit der Zeitabstand
   der Samples zum Anfang nicht stimmt.
*/
DCF77Helper::DCF77Helper() {
  _cursor = 0;
  for (byte i = 0; i < DCF77HELPER_MAX_SAMPLES; i++) {
    _zeitstempelDcf77[i] = new TimeStamp(i, i, i, i, i, i);
    _zeitstempelRtc[i] = new TimeStamp(100, 0, 0, 0, 0, 0);
  }
}

/**
   Einen neuen Sample hinzufuegen.
*/
void DCF77Helper::addSample(MyDCF77* dcf77, MyRTC* rtc) {
  DEBUG_PRINT(F("DCF: "));
  _zeitstempelDcf77[_cursor]->set(dcf77);
  DEBUG_PRINTLN(_zeitstempelDcf77[_cursor]->asString());

  DEBUG_PRINT(F("RTC: "));
  _zeitstempelRtc[_cursor]->set(rtc);
  DEBUG_PRINTLN(_zeitstempelRtc[_cursor]->asString());

  _cursor++;
  if (_cursor == DCF77HELPER_MAX_SAMPLES) {
    _cursor = 0;
  }
}

/**
   Die Samples vergleichen
*/
boolean DCF77Helper::samplesOk() {
  boolean ret = true;
  for (byte i = 0; i < DCF77HELPER_MAX_SAMPLES - 1; i++) {
#ifdef DEBUG
    long minuteDiffDcf77 = _zeitstempelDcf77[i]->getMinutesOfCentury() - _zeitstempelDcf77[i + 1]->getMinutesOfCentury();
    long minuteDiffRtc = _zeitstempelRtc[i]->getMinutesOfCentury() - _zeitstempelRtc[i + 1]->getMinutesOfCentury();
#endif
    long diff = _zeitstempelDcf77[i]->getMinutesOfCentury() - _zeitstempelDcf77[i + 1]->getMinutesOfCentury()
                - (_zeitstempelRtc[i]->getMinutesOfCentury() - _zeitstempelRtc[i + 1]->getMinutesOfCentury());
    // Teste den Minutenabstand (über den gesamten Datumsbereich) zwischen den Zeitstempeln...
    if (abs(diff) > 1) {
      DEBUG_PRINT(F("Diff #"));
      DEBUG_PRINT(i);
      DEBUG_PRINT(F(" dist. wrong. ("));
      DEBUG_PRINT(minuteDiffDcf77);
      DEBUG_PRINT(F("!="));
      DEBUG_PRINT(minuteDiffRtc);
      DEBUG_PRINTLN(F(")"));
      ret = false;
    } else {
      DEBUG_PRINT(F("Diff #"));
      DEBUG_PRINT(i);
      DEBUG_PRINT(F(" dist. ok. ("));
      DEBUG_PRINT(minuteDiffDcf77);
      DEBUG_PRINT(F("~="));
      DEBUG_PRINT(minuteDiffRtc);
      DEBUG_PRINTLN(F(")"));
    }
  }

  return ret;
}

