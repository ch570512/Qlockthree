/*
  Configuration
  Die Compiler-Einstellungen der Firmware an einer zentralen Stelle.

  @mc       Arduino/RBBB
  @autor    Christian Aschoff / caschoff _AT_ mac _DOT_ com
  @version  
  @created  23.1.2013

  *********************************************************************************************************************
  * QLOCKTHREE
  * Die Firmware der Selbstbau-QLOCKTWO.
  *********************************************************************************************************************

  Diese Firmware basiert auf dem CLT Master Branch von Manuel. Sie enthält aber auch die CLT2 und Elemente von Andreas.
  Einher geht die Firmware mit dem "neuen" BOARD_NANO aus Arduino Nano und einem DS3231 RTC-Modul.
  Ein Video gibt es hier: https://www.youtube.com/watch?v=X_I5B-dErzE&feature=youtu.be
  Die Firmware gibt es hier: https://github.com/ch570512/Qlockthree

  Je nach Schalter (USE_...) und Parameter (ABC_...) in der Konfiguration stehen verschiedene Funktionen der Uhr
  zur Verfuegung. Da der Speicher des Mikrocontrollers begrenzt ist, kann nicht alles gleichzeitig eingeschaltet
  werden.

  Generell blinkt das Display bei der Möglichkeit eine Zeit einzustellen. Ausserdem wird der Vormittag durch AM, der
  Nachmittag durch PM in der originalen Front angezeigt. Bei Sprachen die AM und PM nicht enthalten, leuchtet der erste
  Buchstabe fuer AM, der zweite Buchstabe fuer PM.
    
  *** Standard Modi ***

  Zeitanzeige: Der Standardmodus der Uhr. Er zeigt die Zeit an. :)
  Anzeige AM/PM: Zeigt an, ob es vormittags (AM) oder nachmittags (PM) ist. (USE_STD_MODE_AMPM)
  Sekunden: Anzeige der Sekunden. (USE_STD_MODE_SECONDS)
  Datum: Anzeige des aktuellen Tages und Monats. (USE_STD_MODE_DATE)
  Temperatur: Anzeige der gemessenen Temperatur. (USE_STD_MODE_TEMP)
  Alarm: H+ und M+ druecken um den Alarm (in 5 Minuten-Schritten) für die nächsten 24 Stunden zu stellen. Der Alarm
         schaltet sich nach Ablauf der Fallback-Time automatisch ein. Er wird durch Druecken der Mode-Taste deaktiviert.
         Fuer Alarm muss ein Lautsprecher oder Buzzer an den entsprechenden Ausgang des Controllers (D11 beim BOARD_NANO)
         und GND und optional eine weitere "Eck-LED" an die 5te Reihe der Matrix bzw. eine weitere LED am Streifen
         angebracht werden. Siehe auch Boards.h (USE_STD_MODE_ALARM)
  Helligkeit: H+ und M+ druecken um die LEDs im manuellen Modus heller oder dunkler zu stellen.
  Display aus: Hier H+ und M+ zusammen druecken wechselt zu den erweiterten Modi,
               5 Sekunden lang gedrueckt halten loescht alle Einstellungen und loesst einen Reset der Uhr aus.

  *** Erweiterte Modi ***

  Titel MAIN: H+ und M+ druecken um direkt in die naechste oder vorhergehende Kategorie zu wechseln. (USE_EXT_MODE_TITLES)
  Automatische Helligkeitsregelung ein/aus (A/M)
  Effekt beim Zeitwechsel (TR NO/FD/SD/MX): kein Effekt, Fading, Sliding, Matrix (nur mit Farb-LEDs)
  Farbe (C 0..18) oder Farbwechsel (CC 01/02): CC 01 siehe unten, CC 02 wechselt die Farbe im 5 Minutentakt.
  Geschwindigkeit fuer Farbwechsel (CR 00...10): 00 -> langsam, 10 -> schnell.
  Haeufigkeit der Events (EV 5, 15, 30, 45, 60), Event erscheint am eingestellten Tag alle 5, 15, 30, 45, 60 Minuten.
  Sprache (CH/DE/EN/...): Die passende Sprache zur benutzten Front waehlen.
  Ruecksprungverzoegerung (FB nn): Wie lange soll es dauern, bis z.B. aus der Sekundenanzeige wieder in den 
                                   Zeitanzeige-Modus gewechselt wird. (0 = deaktiviert.)
  Titel TIME: H+ und M+ druecken um direkt in die nächste oder vorhergehende Kategorie zu wechseln. (USE_EXT_MODE_TITLES)
  "Es ist" anzeigen oder nicht (IT EN/DA) (USE_EXT_MODE_IT_IS)
  Zeit einstellen: H+ und M+ druecken um die Zeit zu stellen. Die Sekunden springen mit jedem Druck auf Null.
  Zeitverschiebung zu DCF77, nicht Zeitzone. (USE_EXT_MODE_TIME_SHIFT)
  Tag einstellen (DD nn): H+ und M+ druecken um den aktuellen Tag einzustellen. (USE_EXT_MODE_DATE_MANUALLY)
  Monat einstellen (MM nn): H+ und M+ druecken um den aktuellen Monat einzustellen.
  Jahr einstellen (YY nn): H+ und M+ druecken um das aktuelle Jahr einzustellen.
  Nachtauschaltung (N OF): H+ und M+ druecken um die Ausschaltzeit des Displays einzustellen.
                           Durch das Abschalten des Displays verbessert sich der Empfang der DCF77-Zeit.
  Nachtwiedereinschaltung (N ON): H+ und M+ druecken um die Einschaltzeit des Displays einzustellen. Analog (N OFF).
  Titel TEST: H+ und M+ druecken um direkt in die nächste oder vorhergehende Kategorie zu wechseln. (USE_EXT_MODE_TITLES)
  LED-Test: Laesst einen senkrechten Streifen ueber das Display wandern.
  Zeit in Stunden und Minuten seit der letzten erfolgreichen DCF77 Synchronisation.
  Debug DCF77: Bei gutem DEF77-Empfang leuchten die Eck-LEDs nacheinander im Sekundentakt auf.

  *** sonstige Schalter und Parameter ***

  BOARD_DEFAULT: Der 3-Platinen-Aufbau oder das Nachbau-Board mit Schieberegistern von Christian.
  BOARD_AMBBRTCAD:
  BOARD_BBRTCAD: Ein weiteres Board, für das Moodlight, von Christian.
  BOARD_CLT: Das Board der CLT2.
  BOARD_NANO: Günstiges und einfaches selbstbau Board mit Arduino Nano, DS3231 RTC und vielen Optionen für die
              weitere Hardware. Dateien mit Informationen liegen im Verzeichnis.
              Der Aufbau auf einer kleinen Lochrasterplatine ist relativ einfach möglich sein.
              Bitte eine externe 5V Stromquelle verwenden da sonst evtl. der Arduino und/oder der USB-Port des
              Computers wegen der hohen LED-Last durchbrennt.

  LED_DRIVER_DEFAULT: LED-Matrix nach Christian.
  LED_DRIVER_UEBERPIXEL:
  LED_DRIVER_POWER_SHIFT_REGISTER:
  LED_DRIVER_DOTSTAR: RGB-LED-Streifen.
  LED_DRIVER_NEOPIXEL: WS2812B-RGB-LED-Streifen.
  LED_DRIVER_LPD8806: LPD8806-RGBW-LED-Streifen.

  RGB_LEDS: RGB-LEDs mit waagerechtem Streifen-Layout wie dem Moodlight von Christian.
  RGBW_LEDS: RGBW-LEDs mit waagerechtem Streifen-Layout wie dem Moodlight von Christian.
  RGBW_LEDS_CLT2: RGBW-LEDs mit senkrechtem Streifen-Layout der CLT2.

  MATRIX_XXL: Verdoppelt die Grösse der Matrix. Es werden immer 4 LEDs auf dem Streifen für einen Pixel benutzt.
  MOS_DRIVER:
  ENABLE_DCF_LED: Zeigt mit Hilfe der gelben LED auf dem Board die Funktion des DCF77 Empfängers an. Bei gutem
                  Empfang blinkt sie regelmaessig. Kann abgeschaltet werden, wenn kein DCF77 Empfaenger verbaut ist.
  ENABLE_SQW_LED: Zeigt mit Hilfe der grünen LED auf dem Board die Funktion der RTC an. Sie blinkt einmal pro
                  Sekunde.
  DS1307: Real Time Clock.
  DS3231: Moderne und sehr genaue Real Time Clock. Dadurch könnte man auf den DCF77 Empfänger verzichten.
  TEMP_SENS_NONE: Einschalten, wenn _kein_ Temperatursensor verbaut ist. Sonst abschalten.
  TEMP_SENS_LM35: Einschalten, wenn ein Temperatursensor vom Typ LM35 verbaut ist.
  TEMP_SENS_LM335: Einschalten, wenn ein Temperatursensor vom Typ LM335 verbaut ist.
  DCF77: Einschalten, wenn ein DCF77 Empfänger verbaut ist. Der PON-Pin wird von dieser Firmware geschaltet.

  REMOTE_NO_REMOTE: Einschalten, wenn _kein_ IR-Sensor verbaut ist.
  REMOTE_SPARKFUN: Fernbedienung von Sparkfun.
  REMOTE_MOONCANDLES: Fernbedienung von Mooncandles.
  REMOTE_LUNARTEC: Fernbedienung von Linartec.
  REMOTE_CLT: Fernbedienung der CLT2.
  REMOTE_APPLE: Alte kleine weisse Fernbedienung für iPod von Apple. Play: Standard Modi, Menu: Erweiterte Modi,
                Back: Zeitanzeige, FF: Display aus, +: Stunde+, -: Minute+
  REMOTE_BLUETOOTH: Bluetooth App für Android oder iPhone. (Kostenpflichtig.)

  LED_TEST_INTRO: Laesst alle LEDs nach dem Start der Uhr fuer 3 Sekunden leuchten.
  NONE_TECHNICAL_ZERO: Zeigt die Null ohne den diagonalen Strich.
  AUTO_JUMP_BLANK: Nach einem erfolgreichen DCF77 Sync bei ausgeschalteter Anzeige, geht sie automatisch wieder an.
  IR_LETTER_OFF: Schaltet die LED hinter dem IR-Sensor dauerhaft ab. Das verbessert den IR-Empfang.
                 Hier das K vor Uhr: letzte Zeile (matrix[9]), achter Buchstabe (0b1111111011111111).
  EVENTS:
  TEMP_OFFSET: Gibt an, um wieviel Grad die gemessene Temperatur (+ oder -) korrigiert werden soll.
  NO_OF_SAMPLES: Gibt an, wie oft zur Ermittlung der Temperatur gemessen werden soll.
  MAX_BUZZ_TIME_IN_MINUTES 2
  SPEAKER_IS_BUZZER
  SPEAKER_FREQUENCY 200000
  MYDCF77_SIGNAL_IS_INVERTED: Invertiert das DCF77-Empfänger-Signal.
  SERIAL_SPEED: Geschwindigkeit der seriellen Schnittstelle für die Debugging Konsole und dem Bluetooth-Modul.
  BUTTON_TRESHOLD:
  PWM_DURATION:
  SHIFTREGISTER_TURBO:
  UPSIDE_DOWN: Dreht die Ausgabe der Uhr auf den Kopf wenn man die Anoden falsch herum angeschlossen hat.
  RENDER_CORNERS_CCW: Laufrichtung der Eck-LEDs umderehen wenn man sie falsch herum angeschlossen hat.
  OPTIMIZED_FOR_DARKNESS:
  SKIP_BLANK_LINES: Überspringt Zeilen, welche nichts anzeigen. Das Display wird heller aber schwankt in der
                    Helligkeit.

  DEBUG: Gibt viele Informationen in der seriellen Konsole aus. Muss fuer die Benutzung der weiteren DEBUGs
         eingeschaltet sein.
  DEBUG_TIME: Zeigt die RTC-Zeit an.
  DEBUG_MATRIX: Rendert die Ausgabe der Matrix für die deutsche Front in der seriellen Konsole.
  DEBUG_FPS: Zeigt die FPS.
  DEBUG_DCF77: Infos vom DCF77-Empfänger.
  DEBUG_LDR: Infos vom LDR.
  DEBUG_HALT: Hält die RTC an. Die Anzeige läuft weiter.
  DEBUG_SET_DEFAULTS: Schreibt die Default-Werte bei jedem Start in den EEPROM.
  
  *** Important Info ***

  In order to get the firmware to compile, you have to install the following libraries
  using Arduino Library Manager (guide: https://www.arduino.cc/en/Guide/Libraries):
  * [NeoPixel library](https://github.com/adafruit/Adafruit_NeoPixel)
  * [DotStar library](https://github.com/adafruit/Adafruit_DotStar)
  * [LPD8806 library](https://github.com/adafruit/LPD8806)
  * [LedControl (MAX7219) library](https://github.com/wayoda/LedControl)
  You have to install these manually to your library directory in "C:\Users\MyUserName\Documents\Arduino\libraries\":
  * [LPD8806DBL library](https://github.com/bracci/LPD8806DBL)
  * [LPD8806RGBW library](https://github.com/bracci/LPD8806RGBW)
  * [LPD8806RGBW_DBL library] (https://github.com/bracci/LPD8806RGBW_DBL)

  P.S.: Unfortunately the LPD8806 library from Adafruit has a bug.
  You have to open the file "LPD8806.h" from "C:\Users\MyUserName\Documents\Arduino\libraries\LPD8806" and paste the
  following lines following the file header:

  #ifndef __LPD8806__H__
  #define __LPD8806__H__

  and at the end of the file:

  #endif

  *********************************************************************************************************************
  *** Vielen Dank an alle, insbesondere an Christian, Manuel und Andreas, auf deren Arbeit, Zeit und
  *** Einfallsreichtum diese Version der Firmware aufbaut.
  *********************************************************************************************************************
*/

#ifndef CONFIGURATION_H
#define CONFIGURATION_H

/******************************************************************************
  Standard Menu:
******************************************************************************/

// Show AM/PM.
#define USE_STD_MODE_AMPM

// Show seconds.
#define USE_STD_MODE_SECONDS

// Show date.
#define USE_STD_MODE_DATE

// Show temperature.
//#define USE_STD_MODE_TEMP

// Set an alarm.
//#define USE_STD_MODE_ALARM

/******************************************************************************
  Extended Menu:
******************************************************************************/

// Show MAIN/TIME/TEST
#define USE_EXT_MODE_TITLES

// Show setup for date.
#define USE_EXT_MODE_DATE_MANUALLY

// Show setup to disable "It is".
#define USE_EXT_MODE_IT_IS

// Show setup for timeshift to DCF77 signal.
#define USE_EXT_MODE_TIME_SHIFT

// Show time since last sync with DCF77.
#define USE_EXT_MODE_DCF_SYNC

// Show DCF77 debug.
#define USE_EXT_MODE_DCF_DEBUG

// Show LED test.
#define USE_EXT_MODE_TEST

// Supportet languages.
#define ENABLE_LANGUAGE_DE
#define ENABLE_LANGUAGE_CH
//#define ENABLE_LANGUAGE_EN
//#define ENABLE_LANGUAGE_FR
//#define ENABLE_LANGUAGE_IT
//#define ENABLE_LANGUAGE_NL
//#define ENABLE_LANGUAGE_ES

/******************************************************************************
  Hardware settings:
******************************************************************************/

// Which Board?
#define BOARD_DEFAULT
//#define BOARD_AMBBRTCAD
//#define BOARD_BBRTCAD
//#define BOARD_CLT
//#define BOARD_NANO

// Which LED-Driver?
#define LED_DRIVER_DEFAULT
//#define LED_DRIVER_UEBERPIXEL
//#define LED_DRIVER_POWER_SHIFT_REGISTER
//#define LED_DRIVER_DOTSTAR
//#define LED_DRIVER_NEOPIXEL
//#define LED_DRIVER_LPD8806

// Type of LEDs? (LED_DRIVER_DOTSTAR or LED_DRIVER_NEOPIXEL or LED_DRIVER_LPD8806)
//#define RGB_LEDS
//#define RGBW_LEDS
//#define RGBW_LEDS_CLT2

// Double the clocksize? (LED_DRIVER_NEOPIXEL or LED_DRIVER_LPD8806) (not working right now.)
//#define MATRIX_XXL

// Are MOS-FETs used? (LED_DRIVER_DEFAULT)
//#define MOS_DRIVER

// Which LEDs on the board should be enabled?
#define ENABLE_DCF_LED
#define ENABLE_SQW_LED

// Which RTC is used?
#define DS1307
//#define DS3231

// DCF77 receiver present?
#define DCF77

// Which Temperature-Sensor is used?
#define TEMP_SENS_NONE
//#define TEMP_SENS_LM35
//#define TEMP_SENS_LM335

// Which IR-Remote is used?
#define REMOTE_NO_REMOTE
//#define REMOTE_SPARKFUN
//#define REMOTE_MOONCANDLES
//#define REMOTE_LUNARTEC
//#define REMOTE_CLT
//#define REMOTE_APPLE

// Use a Bluetooth-Remote?
//#define REMOTE_BLUETOOTH

/******************************************************************************
  Software settings:
******************************************************************************/

// Turn on all LEDs for 3s on power-up.
#define LED_TEST_INTRO

// Show none technical zero.
//#define NONE_TECHNICAL_ZERO

// Turn on clock after successfull DCF77-sync.
//#define AUTO_JUMP_BLANK

// Turn off the letter containing the IR-Sensor.
//#define IR_LETTER_OFF matrix[9] &= 0b1111111011111111

// Events:
//#define EVENTS

// Temperature:
#define TEMP_OFFSET -2
#define NO_OF_SAMPLES 5

// Alarm:
#define MAX_BUZZ_TIME_IN_MINUTES 5
#define SPEAKER_IS_BUZZER
#define SPEAKER_FREQUENCY 200000

// DCF77:
#define DCF77HELPER_MAX_SAMPLES 3
//#define MYDCF77_SIGNAL_IS_INVERTED
//#define MYDCF77_SIGNAL_IS_ANALOG
//#define MYDCF77_ANALOG_SIGNAL_TRESHOLD 600
#define MYDCF77_TELEGRAMMLAENGE 59
#define MYDCF77_SIGNAL_BINS 11
#define MYDCF77_DRIFT_CORRECTION_TIME 30
#define MYDCF77_MEANSTARTVALUE 450

// LDR:
#define LDR_AUTOSCALE
#define LDR_MANUAL_MIN 0
#define LDR_MANUAL_MAX 1023
#define LDR_MIN_PERCENT 5
#define LDR_MAX_PERCENT 100
#define LDR_HYSTERESE 50
#ifdef LED_DRIVER_DEFAULT
  #define LDR_CHECK_RATE 1
#else
  #define LDR_CHECK_RATE 10
#endif

// misc:
#define SERIAL_SPEED 57600 // Set speed for debuging console and bluetooth remote.
#define BUTTON_TRESHOLD 300
#define PWM_DURATION 8
#define SHIFTREGISTER_TURBO
//#define UPSIDE_DOWN
//#define RENDER_CORNERS_CCW
//#define OPTIMIZED_FOR_DARKNESS
//#define SKIP_BLANK_LINES
#define FIRMWARE_VERSION "yaqtfw_20170108"

/******************************************************************************
  Debug to serial console. DEBUG has to be defined to use the other debugs.
******************************************************************************/

//#define DEBUG                 // Switch on debug.
//#define DEBUG_TIME            // Shows the time every secound.
//#define DEBUG_MATRIX          // Randers the matrix to console. German front.
//#define DEBUG_FPS             // Shows the FPS.
//#define DEBUG_DCF77           // Info for DCF77.
//#define DEBUG_LDR             // Info for LDR.
//#define DEBUG_HALT            // Stops the RTC.
//#define DEBUG_SET_DEFAULTS    // Sets the EEPROM to defauls on startup.

#endif
