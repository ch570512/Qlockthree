/**
   Events.h
   Instanzierung jährlicher Events

   @mc       Arduino/UNO
   @autor    Manuel Bracher / manuel.bracher@gmail.com
   @version  1.0
   @created  02.01.15

   Versionshistorie:
   V 1.0:  - Erstellt.
*/

#ifndef EVENTS_H
#define EVENTS_H

#include "Event.h"
#include "Colors.h"

/**************************************************************************************************************
  Instanzierung und Initialisierung jährlicher Events. Ein Event enthält eine Laufschrift, gefolgt
  von einem Bildeffekt (Herz, Feuerwerk, etc.). Diese werden am definierten Jahrestag angezeigt.
  Soll nur eine Laufschrift (ohne Bildeffekt) angezeigt werden,
  ist als Effekt-Input NO_EFFECT zu wählen. Soll nur ein Bildeffekt (ohne Laufschrift) gezeigt werden, ist als
  Text-Input "" zu definieren. (Monat, Tag, Text, Effekt, Effektfarbe) Das Event-Array kann "beliebig" ergänzt
  werden.
**************************************************************************************************************/

const char* eventText[] = {
  "Happy Birthday",
  "Testevent"  // letzter Eintrag ohne Komma.
};

Event events[] = {
  Event(7, 16, eventText[0], Effects::EFFECT_CANDLE, color_orange1),
  Event(1, 14, eventText[1], Effects::ANI_BITMAP_SMILEY_WINK, color_yellow)  // letzter Eintrag ohne Komma.
};

//NO_EFFECT = 255,
//EFFECT_FIREWORK = 0,
//EFFECT_HEART,
//EFFECT_CANDLE,
//EFFECT_LOVEU,
//EFFECT_INTRO,
//
//BITMAP_MIN,
//BITMAP_HEART = BITMAP_MIN,
//BITMAP_DOTCIRCLE,
//BITMAP_WEDDINGRING,
//BITMAP_BDPIE,
//BITMAP_CHAMPGLASS1,
//BITMAP_CHAMPGLASS2,
//BITMAP_CHRISTTREE1,
//BITMAP_CHRISTTREE2,
//BITMAP_SMILEY,
//BITMAP_SMILEY_WINK,
//
//ANI_BITMAP_MIN,
//ANI_BITMAP_CHAMPGLASS = ANI_BITMAP_MIN,
//ANI_BITMAP_CHRISTTREE,
//ANI_BITMAP_SMILEY_WINK,

//color_white,
//color_red,
//color_green,
//color_darkBlue,
//color_brightBlue,
//color_pink,
//color_yellow,
//color_orange1,
//color_orange2,
//color_orange3,
//color_orange4,
//color_turquois1,
//color_turquois2,
//color_turquois3,
//color_turquois4,
//color_purple1,
//color_purple2,
//color_purple3,
//color_purple4,
//
//color_rgb_continuous,
//color_rgb_step,
//color_none

int nbrOfEvts = sizeof(events) / sizeof(Event);

#endif
