/**
   DCF77Helper
   Klasse um die Qualitaet der DCF77-Samples zu verbessern. Dazu wird der Minutenabstand
   zwischen den empfangenen DCF77-Samples mit Hilfe der Echtzeituhr verglichen.

   @mc       Arduino/RBBB
   @autor    Christian Aschoff / caschoff _AT_ mac _DOT_ com
   @version  1.8a
   @created  19.3.2011
*/

#ifndef DCF77HELPER_H
#define DCF77HELPER_H

#include "Arduino.h"
#include "TimeStamp.h"
#include "MyDCF77.h"
#include "MyRTC.h"
#include "Configuration.h"

class DCF77Helper {
  public:
    DCF77Helper();

    void addSample(MyDCF77* dcf77, MyRTC* rtc);
    boolean samplesOk();

  private:
    byte _cursor;
    TimeStamp *_zeitstempelDcf77[DCF77HELPER_MAX_SAMPLES];
    TimeStamp *_zeitstempelRtc[DCF77HELPER_MAX_SAMPLES];
};

#endif
