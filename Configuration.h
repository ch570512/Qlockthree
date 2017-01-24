/*
  Configuration
  Die Compiler-Einstellungen der Firmware an einer zentralen Stelle.

  @mc       Arduino/RBBB
  @autor    Christian Aschoff / caschoff _AT_ mac _DOT_ com
  @version
  @created  23.1.2013

  *********************************************************************************************************************
    Yet Another QLOCKTHREE Firmware
    Eine Firmware der Selbstbau-QLOCKTWO.
  *********************************************************************************************************************

  Diese Firmware basiert auf dem Master-Branch von Manuel. Sie enthaelt aber auch die CLT2 und Elemente von Andreas.
  Einher geht die Firmware mit dem "neuen" BOARD_NANO bestehend aus Arduino Nano und einem DS3231 RTC-Modul.
  Ein Video gibt es hier: https://www.youtube.com/watch?v=X_I5B-dErzE&feature=youtu.be
  Die Firmware gibt es hier: https://github.com/ch570512/Qlockthree

  Je nach Schalter (USE_...) und Parameter (ABC_...) in der Konfiguration stehen verschiedene Funktionen der Uhr
  zur Verfuegung. Da der Speicher des Microcontrollers begrenzt ist, kann nicht alles gleichzeitig eingeschaltet
  werden.

  Generell blinkt das Display bei der Moeglichkeit eine Zeit einzustellen. Ausserdem wird der Vormittag durch AM, der
  Nachmittag durch PM in der originalen Front angezeigt. Bei Sprachen die AM und PM nicht enthalten, leuchtet der erste
  Buchstabe fuer AM, der zweite Buchstabe fuer PM.

  *** Standard Modi ***

  Zeitanzeige: Der Standardmodus der Uhr. Er zeigt die Zeit an. :)
  Anzeige AM/PM: Zeigt an, ob es vormittags (AM) oder nachmittags (PM) ist. (USE_STD_MODE_AMPM)
  Sekunden: Anzeige der Sekunden. Hier H+ und M+ zusammen druecken zeigt die Demoevents. (USE_STD_MODE_SECONDS)
  Datum: Anzeige des aktuellen Tages und Monats. (USE_STD_MODE_DATE)
  Temperatur: Anzeige der gemessenen Temperatur. (USE_STD_MODE_TEMP)
  Alarm: H+ und M+ druecken um den Alarm (in 5 Minuten-Schritten) fuer die naechsten 24 Stunden zu stellen. Der Alarm
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
  Geschwindigkeit fuer fortdauernden Farbwechselmodus CC 01 (CR 00...10): 00 -> langsam, 10 -> schnell.
  Events (EV 5, 15, 30, 60): Event erscheint am eingestellten Tag alle 5, 15, 30 oder 60 Minuten fuer 1 Minute.
                             Ein Event enthaelt eine Laufschrift, gefolgt von einem Bildeffekt (Herz, Feuerwerk, etc.).
                             Konfiguration in Events.h (EVENTS)
  Sprache (DE/CH/EN/...): Die passende Sprache zur benutzten Front waehlen.
  Ruecksprungverzoegerung (FB nn): Wie lange soll es dauern, bis z.B. aus der Sekundenanzeige wieder zurück in die
                                   Zeitanzeige gewechselt wird. (0 = deaktiviert.)
                                   
  Titel TIME: H+ und M+ druecken um direkt in die naechste oder vorhergehende Kategorie zu wechseln. (USE_EXT_MODE_TITLES)
  "Es ist" anzeigen oder nicht (IT EN/DA) (USE_EXT_MODE_IT_IS)
  Zeit einstellen: H+ und M+ druecken um die Zeit zu stellen. Die Sekunden springen mit jedem Druck auf Null.
  Zeitverschiebung zu DCF77, nicht Zeitzone. (USE_EXT_MODE_TIME_SHIFT)
  Tag einstellen   (DD nn): H+ und M+ druecken um den aktuellen Tag einzustellen. (USE_EXT_MODE_DATE_MANUALLY)
  Monat einstellen (MM nn): H+ und M+ druecken um den aktuellen Monat einzustellen.
  Jahr einstellen  (YY nn): H+ und M+ druecken um das aktuelle Jahr einzustellen.
  Nachtauschaltung        (N OF): H+ und M+ druecken um die Ausschaltzeit des Displays einzustellen. (USE_EXT_MODE_NIGHT_OFF)
  Nachtwiedereinschaltung (N ON): H+ und M+ druecken um die Einschaltzeit des Displays einzustellen. Analog (N OFF).
                                  Durch das Abschalten des Displays verbessert sich der Empfang der DCF77-Zeit.
                                  
  Titel TEST: H+ und M+ druecken um direkt in die naechste oder vorhergehende Kategorie zu wechseln. (USE_EXT_MODE_TITLES)
  LED-Test: Laesst einen senkrechten Streifen ueber das Display wandern. (USE_EXT_MODE_TEST)
  Zeit in Stunden und Minuten seit der letzten erfolgreichen DCF77 Synchronisation. (USE_EXT_MODE_DCF_SYNC)
  Debug DCF77: Bei gutem DEF77-Empfang leuchten die Eck-LEDs nacheinander im Sekundentakt auf. (USE_EXT_MODE_DCF_DEBUG)

  *** sonstige Schalter und Parameter ***

  BOARD_DEFAULT:      Der 3-Platinen-Aufbau oder das Nachbau-Board mit Schieberegistern von Christian.
  BOARD_AMBBRTCAD:
  BOARD_BBRTCAD:      Ein weiteres Board, fuer das Moodlight, von Christian.
  BOARD_303UNIVERSAL:
  BOARD_CLT:          Das Board der CLT2.
  BOARD_NANO:         Guenstiges und einfaches selbstbau Board mit Arduino Nano, DS3231 RTC und vielen Optionen fuer die
                      weitere Hardware. Dateien mit Informationen liegen im Verzeichnis.
                      Der Aufbau auf einer kleinen Lochrasterplatine ist relativ einfach moeglich.
                      Bitte eine externe 5V Stromquelle verwenden da sonst evtl. der Arduino und/oder der USB-Port des
                      Computers wegen der hohen LED-Last durchbrennt.

  LED_DRIVER_DEFAULT: LED-Matrix nach Christian.
  LED_DRIVER_UEBERPIXEL:
  LED_DRIVER_POWER_SHIFT_REGISTER:
  LED_DRIVER_DOTSTAR: RGB-LED-Streifen.
  LED_DRIVER_NEOPIXEL: WS2812B-RGB-LED-Streifen.
  LED_DRIVER_LPD8806: LPD8806-RGBW-LED-Streifen.
  LED_DRIVER_WS2801:  WS2801-RGB-LED-Streifen. Nicht wirklich unterstuetzt da in der Adafroit Library Funktionen fehlen. Color und clear().

  RGB_LEDS:           RGB-LEDs mit waagerechtem Streifen-Layout wie dem Moodlight von Christian.
  RGBW_LEDS:          RGBW-LEDs mit waagerechtem Streifen-Layout wie dem Moodlight von Christian.
  RGBW_LEDS_CLT2:     RGBW-LEDs mit senkrechtem Streifen-Layout der CLT2.

  MOS_DRIVER:
  ENABLE_DCF_LED:     Zeigt mit Hilfe der gelben LED auf dem Board die Funktion des DCF77 Empfaengers an. Bei gutem
                      Empfang blinkt sie regelmaessig. Kann abgeschaltet werden, wenn kein DCF77 Empfaenger verbaut ist.
  ENABLE_SQW_LED:     Zeigt mit Hilfe der gruenen LED auf dem Board die Funktion der RTC an. Sie blinkt einmal pro
                      Sekunde.
  DS1307:             Real Time Clock.
  DS3231:             Moderne und sehr genaue Real Time Clock. Dadurch koennte man auf den DCF77 Empfaenger verzichten.
  TEMP_SENS_LM35:     Einschalten, wenn ein Temperatursensor vom Typ LM35 verbaut ist.
  TEMP_SENS_LM335:    Einschalten, wenn ein Temperatursensor vom Typ LM335 verbaut ist.
  TEMP_SENS_DS3231:   Nutzt den eingebauten Temperatursensor der DS3231 RTC.
  TEMP_OFFSET:        Gibt an, um wieviel Grad die gemessene Temperatur (+ oder -) korrigiert werden soll.
  DCF77:              Einschalten, wenn ein DCF77 Empfaenger verbaut ist. Der PON-Pin wird von dieser Firmware geschaltet.

  REMOTE_NO_REMOTE:   Einschalten, wenn _kein_ IR-Sensor verbaut ist.
  REMOTE_SPARKFUN:    Fernbedienung von Sparkfun.
  REMOTE_MOONCANDLES: Fernbedienung von Mooncandles.
  REMOTE_LUNARTEC:    Fernbedienung von Lunartec.
  REMOTE_CLT:         Fernbedienung der CLT2.
  REMOTE_APPLE:       Alte kleine weisse Fernbedienung fuer iPod von Apple:
                      Play: Standard Modi
                      Menu: Erweiterte Modi
                      Back: Ruecksprung zur Zeitanzeige
                      FF:   Display ein/aus
                      +:    Stunde+
                      -:    Minute+
  REMOTE_PHILIPS:     Universal Fernbedienung Philips SRP1 101/10 mit dem Geraetecode 0815:
                      PROG+: Standard Modi
                      PROG-: Erweiterte Modi
                      POWER: Display ein/aus
                      MUTE:  Ruecksprung zur Zeitanzeige
                      VOL+:  Stunde+
                      VOL-:  Minute+
                      1:     Uebergang Fade
                      2:     Uebergang Matrix
                      3:     Uebergang Slide
                      4:     Farbe weiss
                      5:     Farbe rot
                      6:     Farbe gruen
                      7:     Farbe dunkelblau
                      8:     Farbe gelb
                      9:     automatischer Farbwechsel
                      A/V:   Helligkeit-
                      -/--:  Helligkeit+
                      0:     LDR ein/aus
  REMOTE_BLUETOOTH:   Bluetooth App fuer Android oder iPhone. (Kostenpflichtig.)

  LED_TEST_INTRO:     Laesst alle LEDs nach dem Start der Uhr fuer 3 Sekunden leuchten.
  NONE_TECHNICAL_ZERO: Zeigt die Null ohne den diagonalen Strich.
  AUTO_JUMP_BLANK:    Nach einem erfolgreichen DCF77 Sync bei ausgeschalteter Anzeige, geht sie automatisch wieder an.
  IR_LETTER_OFF:      Schaltet die LED hinter dem IR-Sensor dauerhaft ab. Das verbessert den IR-Empfang.
                      Hier das K vor Uhr: letzte Zeile (matrix[9]), achter Buchstabe (0b1111111011111111).
  MAX_BUZZ_TIME_IN_MINUTES: Wie lange soll der Alarm laufen wenn er nicht abgeschaltet wird.
  SPEAKER_IS_BUZZER:  Setzen, wenn ein Buzzer statt eines Lautsprechers verbaut ist.
  SPEAKER_FREQUENCY:  Frequenz des Wechtons fuer einen Lautsprecher.
  MYDCF77_SIGNAL_IS_INVERTED: Invertiert das DCF77-Empfaenger-Signal.
  SERIAL_SPEED:       Geschwindigkeit der seriellen Schnittstelle fuer die Debugging Konsole und dem Bluetooth-Modul.
  BUTTON_TRESHOLD:
  PWM_DURATION:
  SHIFTREGISTER_TURBO:
  UPSIDE_DOWN:        Dreht die Ausgabe der Uhr auf den Kopf wenn man die Anoden falsch herum angeschlossen hat.
  RENDER_CORNERS_CCW: Laufrichtung der Eck-LEDs umderehen wenn man sie falsch herum angeschlossen hat.
  OPTIMIZED_FOR_DARKNESS:
  SKIP_BLANK_LINES:   Ueberspringt Zeilen, welche nichts anzeigen. Das Display wird heller aber schwankt in der
                      Helligkeit.

  DEBUG:              Gibt viele Informationen in der seriellen Konsole aus.
  DEBUG_TIME:         Zeigt die RTC-Zeit an.
  DEBUG_MATRIX:       Rendert die Ausgabe der Matrix fuer die deutsche Front in der seriellen Konsole.
  DEBUG_EVENT_MATRIX: Rendert die Ausgabe der Matrix bei Events in der seriellen Konsole. Funktioniert am Besten
                      mit Putty.
  DEBUG_FPS:          Zeigt die FPS.
  DEBUG_DCF77:        Infos vom DCF77-Empfaenger.
  DEBUG_LDR:          Infos vom LDR.
  DEBUG_HALT:         Haelt die RTC an. Die Anzeige laeuft weiter.
  DEBUG_SET_DEFAULTS: Schreibt die Default-Werte bei jedem Start in den EEPROM.

  *** Important Info ***

  In order to get the firmware to compile, you have to install the following libraries:
  https://github.com/wayoda/LedControl
  https://github.com/adafruit/Adafruit_NeoPixel
  https://github.com/adafruit/Adafruit_DotStar
  https://github.com/adafruit/Adafruit-WS2801-Library
  https://github.com/ch570512/LPD8806
  https://github.com/ch570512/LPD8806RGBW

  *********************************************************************************************************************
  *** Vielen Dank an alle, insbesondere an Christian, Manuel und Andreas, auf deren Arbeit, Zeit und
  *** Einfallsreichtum diese Version der Firmware aufbaut.
  *********************************************************************************************************************
*/

#ifndef CONFIGURATION_H
#define CONFIGURATION_H

/******************************************************************************
  Standard Menu
******************************************************************************/

// Show AM/PM
#define USE_STD_MODE_AMPM

// Show seconds
#define USE_STD_MODE_SECONDS

// Show date
#define USE_STD_MODE_DATE

// Show temperature
//#define USE_STD_MODE_TEMP

// Set an alarm
//#define USE_STD_MODE_ALARM

/******************************************************************************
  Extended Menu
******************************************************************************/

// Show MAIN/TIME/TEST titles
#define USE_EXT_MODE_TITLES

// Set events time
//#define EVENTS

// Supportet languages
#define ENABLE_LANGUAGE_DE
//#define ENABLE_LANGUAGE_DE_MKF
//#define ENABLE_LANGUAGE_D3
#define ENABLE_LANGUAGE_CH
//#define ENABLE_LANGUAGE_EN
//#define ENABLE_LANGUAGE_FR
//#define ENABLE_LANGUAGE_IT
//#define ENABLE_LANGUAGE_NL
//#define ENABLE_LANGUAGE_ES

// Show setup to disable "It is"
#define USE_EXT_MODE_IT_IS

// Show setup for timeshift to DCF77 signal
#define USE_EXT_MODE_TIME_SHIFT

// Show setup for date
#define USE_EXT_MODE_DATE_MANUALLY

// Show setup for night on/off
#define USE_EXT_MODE_NIGHT_OFF

// Show LED test
#define USE_EXT_MODE_TEST

// Show time since last sync with DCF77
#define USE_EXT_MODE_DCF_SYNC

// Show DCF77 debug
#define USE_EXT_MODE_DCF_DEBUG

/******************************************************************************
  Hardware settings
******************************************************************************/

// Board
#define BOARD_DEFAULT
//#define BOARD_AMBBRTCAD
//#define BOARD_BBRTCAD
//#define BOARD_303UNIVERSAL
//#define BOARD_CLT2
//#define BOARD_NANO

// LED-Driver
#define LED_DRIVER_DEFAULT
//#define LED_DRIVER_UEBERPIXEL
//#define LED_DRIVER_POWER_SHIFT_REGISTER
//#define LED_DRIVER_DOTSTAR
//#define LED_DRIVER_NEOPIXEL
//#define LED_DRIVER_LPD8806
//#define LED_DRIVER_WS2801

// Type of LEDs (LED_DRIVER_DOTSTAR or LED_DRIVER_NEOPIXEL or LED_DRIVER_LPD8806)
//#define RGB_LEDS
//#define RGBW_LEDS
//#define RGBW_LEDS_CLT2

// MOS-FETs (LED_DRIVER_DEFAULT)
//#define MOS_DRIVER

// LEDs on board
#define ENABLE_DCF_LED
#define ENABLE_SQW_LED

// RTC
#define DS1307
//#define DS3231

// DCF77
#define DCF77

// Temperature-Sensor
//#define TEMP_SENS_LM35
//#define TEMP_SENS_LM335
//#define TEMP_SENS_DS3231
#define TEMP_OFFSET 5

// IR-Remote
#define REMOTE_NO_REMOTE
//#define REMOTE_SPARKFUN
//#define REMOTE_MOONCANDLES
//#define REMOTE_LUNARTEC
//#define REMOTE_CLT
//#define REMOTE_APPLE // Apple Remote Control for iPod
//#define REMOTE_PHILIPS // Philips SRP1 101/10 - Code 0815

// Bluetooth-Remote
//#define REMOTE_BLUETOOTH

/******************************************************************************
  Software settings
******************************************************************************/

// Turn on all LEDs for 3s on power-up
#define LED_TEST_INTRO

// None technical zero
//#define NONE_TECHNICAL_ZERO

// Turn on clock after successfull DCF77-sync
#define AUTO_JUMP_BLANK

// Turn off the letter containing the IR-Sensor (here: 10, 8)
//#define IR_LETTER_OFF matrix[9] &= 0b1111111011111111

// Alarm
#define MAX_BUZZ_TIME_IN_MINUTES 5
#define SPEAKER_IS_BUZZER
#define SPEAKER_FREQUENCY 200000

// DCF77
#define DCF77HELPER_MAX_SAMPLES 3
//#define MYDCF77_SIGNAL_IS_INVERTED
//#define MYDCF77_SIGNAL_IS_ANALOG
//#define MYDCF77_ANALOG_SIGNAL_TRESHOLD 600
#define MYDCF77_TELEGRAMMLAENGE 59
#define MYDCF77_SIGNAL_BINS 11
#define MYDCF77_DRIFT_CORRECTION_TIME 30
#define MYDCF77_MEANSTARTVALUE 450

// LDR
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

// misc
#define SERIAL_SPEED 57600 // Set speed for debuging console and bluetooth remote
#define BUTTON_TRESHOLD 300
#define PWM_DURATION 8
#define SHIFTREGISTER_TURBO
//#define UPSIDE_DOWN
//#define RENDER_CORNERS_CCW
//#define OPTIMIZED_FOR_DARKNESS
//#define SKIP_BLANK_LINES
#define FIRMWARE_VERSION "yaqtfw_20170124"

/******************************************************************************
  Debug to serial console.
******************************************************************************/

//#define DEBUG                 // Switch on debug
//#define DEBUG_TIME            // Shows the time every secound
//#define DEBUG_MATRIX          // Renders the matrix to console - German front - Works best with Putty
//#define DEBUG_EVENT_MATRIX    // Renders events to console - Works best with Putty
//#define DEBUG_FPS             // Shows the FPS
//#define DEBUG_DCF77           // Info for DCF77
//#define DEBUG_LDR             // Info for LDR
//#define DEBUG_HALT            // Stops the RTC
//#define DEBUG_SET_DEFAULTS    // Sets the EEPROM to defauls on every startup

#endif
