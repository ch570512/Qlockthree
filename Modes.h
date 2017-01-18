/**
   Modes.h
   Modi Enum

   @mc       Arduino/UNO
   @autor    Manuel Bracher / manuel.bracher@gmail.com
   @version  1.0
   @created  20.08.15
*/

#ifndef MODES_H
#define MODES_H

#include "Configuration.h"

/**
   Die Standard-Modi.
*/
typedef enum eMode : byte
{
  STD_MODE_NORMAL,
#ifdef USE_STD_MODE_AMPM
  STD_MODE_AMPM,
#endif
#ifdef USE_STD_MODE_SECONDS
  STD_MODE_SECONDS,
#endif
#ifdef USE_STD_MODE_DATE
  STD_MODE_DATE,
#endif
#ifdef USE_STD_MODE_TEMP
  STD_MODE_TEMP,
#endif
#ifdef USE_STD_MODE_ALARM
  STD_MODE_ALARM,
#endif
  STD_MODE_BRIGHTNESS,
  STD_MODE_BLANK,
  STD_MODE_COUNT, // letzter STD_MODE - Rücksprung zur Zeit.
  STD_MODE_NIGHT, // nicht manuell zu erreichender Modus...

  /**
     Die erweiterten Modi.
  */
  EXT_MODE_START,
#ifdef USE_EXT_MODE_TITLES
  EXT_MODE_TEXT_MAIN = EXT_MODE_START,
  EXT_MODE_LDR_MODE,
#else
  EXT_MODE_LDR_MODE = EXT_MODE_START,
#endif
  EXT_MODE_TRANSITION,
#if defined(RGB_LEDS) || defined(RGBW_LEDS) || defined(RGBW_LEDS_CLT2)
  EXT_MODE_COLOR,
  EXT_MODE_COLOR_CHANGE,
#endif
#ifdef EVENTS
  EXT_MODE_EVENT,
#endif
  EXT_MODE_LANGUAGE,
  EXT_MODE_JUMP_TIMEOUT,
#ifdef USE_EXT_MODE_CORNERS
  EXT_MODE_CORNERS,
#endif
#if defined(USE_EXT_MODE_DCF_INVERTED) && defined(DCF77)
  EXT_MODE_DCF_IS_INVERTED,
#endif
#ifdef USE_EXT_MODE_TITLES
  EXT_MODE_TEXT_TIME,
#endif
#ifdef USE_EXT_MODE_IT_IS
  EXT_MODE_IT_IS,
#endif
  EXT_MODE_TIMESET,
#ifdef USE_EXT_MODE_TIME_SHIFT
  EXT_MODE_TIME_SHIFT,
#endif
#ifdef USE_EXT_MODE_DATE_MANUALLY
  EXT_MODE_DAYSET,
  EXT_MODE_MONTHSET,
  EXT_MODE_YEARSET,
#endif
#ifdef USE_EXT_MODE_NIGHT_OFF
  EXT_MODE_NIGHT_OFF,
  EXT_MODE_NIGHT_ON,
#endif
#ifdef USE_EXT_MODE_TITLES
  EXT_MODE_TEXT_TEST,
#endif
#ifdef USE_EXT_MODE_TEST
  EXT_MODE_TEST,
#endif
#if defined(USE_EXT_MODE_DCF_SYNC) && defined(DCF77)
  EXT_MODE_DCF_SYNC,
#endif
#if defined(USE_EXT_MODE_DCF_DEBUG) && defined(DCF77)
  EXT_MODE_DCF_DEBUG,
#endif
  EXT_MODE_COUNT // letzter EXT_MODE - Rücksprung zur Zeit.
} Mode;

// Overload the ControlType++ operator
inline Mode& operator++(Mode& eDOW, int)  // <--- note -- must be a reference
{
  const byte i = static_cast<byte>(eDOW) + 1;
  eDOW = static_cast<Mode>((i) % EXT_MODE_COUNT);
  return eDOW;
}

#endif
