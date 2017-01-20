/**
   MyRTC
   Klasse fuer den Zugriff auf die DS1307/DS3231 Echtzeituhr.

   @mc       Arduino/RBBB
   @autor    Christian Aschoff / caschoff _AT_ mac _DOT_ com
   @version  2.1
   @created  1.3.2011
*/

#include <Wire.h>
#include "MyRTC.h"
#include "Debug.h"

/**
   Initialisierung mit der Adresse der DS1307/DS3231.
*/
MyRTC::MyRTC(int address, byte statusLedPin) : TimeStamp(0, 0, 0, 0, 0, 0) {
  _address = address;
  _statusLedPin = statusLedPin;
  pinMode(_statusLedPin, OUTPUT);
  digitalWrite(_statusLedPin, LOW);
}

/**
   Die LED ein- oder ausschalten.
*/
void MyRTC::statusLed(boolean on) {
  if (on) {
    digitalWrite(_statusLedPin, HIGH);
  } else {
    digitalWrite(_statusLedPin, LOW);
  }
}

/**
   Die Uhrzeit auslesen und in den Variablen ablegen
*/
void MyRTC::readTime() {
  byte returnStatus, count, result, retries = 0;
  do {
    // Reset the register pointer
    Wire.beginTransmission(_address);
    Wire.write((uint8_t) 0x00);
    result = Wire.endTransmission(false); // false, damit der Bus nicht freigegeben wird und eventuell andere dazwischen kommen (in Multi-MCU-Umgebungen)
    //DEBUG_PRINT(F("Wire.endTransmission(false) = "));
    //DEBUG_PRINTLN(result);
    count = Wire.requestFrom(_address, 7);
    //DEBUG_PRINT(F("Wire.requestFrom(_address, 7) = "));
    //DEBUG_PRINTLN(count);

    if (count == 7) {
      // Success
      // A few of these need masks because certain bits are control bits
      _seconds = bcdToDec(Wire.read() & 0x7f);
      _minutes = bcdToDec(Wire.read());
      _hours = bcdToDec(Wire.read() & 0x3f); // Need to change this if 12 hour am/pm
      _dayOfWeek = bcdToDec(Wire.read());
      _date = bcdToDec(Wire.read());
      _month = bcdToDec(Wire.read());
      _year = bcdToDec(Wire.read());
    } else {
      // Fail
      // keine 7 Byte zurueck gekommen? Buffer verwerfen...
      for (int i = 0; i < count; i++) {
        Wire.read();
      }
      retries++;
    }

    result = Wire.endTransmission(true); // true, jetzt den Bus freigeben.
    //DEBUG_PRINT(F("Wire.endTransmission(true) = "));
    //DEBUG_PRINTLN(result);
  } while ((count != 7) && (retries < 8));

  if (retries == 8) {
    // Es konnte nichts gelesen werden
    _seconds = 11;
    _minutes = 11;
    _hours = 11;
    _dayOfWeek = 1;
    _date = 1;
    _month = 1;
    _year = 17;
    DEBUG_PRINTLN(F("RTC error. Set defaults."));
  }

  DEBUG_PRINT(F("Time: "));
  DEBUG_PRINT(getHours());
  DEBUG_PRINT(F(":"));
  DEBUG_PRINT(getMinutes());
  DEBUG_PRINT(F(":"));
  DEBUG_PRINTLN(getSeconds());
  DEBUG_FLUSH();
}

/**
   Die Uhrzeit aus den Variablen in die DS1307/DS3231 schreiben.
*/
void MyRTC::writeTime() {
  Wire.beginTransmission(_address);
  Wire.write((uint8_t) 0x00); // 0 to bit 7 starts the clock
  Wire.write(decToBcd(_seconds));
  Wire.write(decToBcd(_minutes));
  Wire.write(decToBcd(_hours)); // If you want 12 hour am/pm you need to set
  // bit 6 (also need to change readDateDs1307)
  Wire.write(decToBcd(_dayOfWeek));
  Wire.write(decToBcd(_date));
  Wire.write(decToBcd(_month));
  Wire.write(decToBcd(_year));
  Wire.endTransmission();
}

/**
   SQW fuer DS1307.
*/
void MyRTC::enableSQWOnDS1307() {
  Wire.beginTransmission(_address);
  Wire.write(0x07); // Datenregister
  Wire.write(0b00010000); // enable 1HZ square wave output
  Wire.endTransmission();
}

/**
   SQW fuer DS3231.
*/
void MyRTC::enableSQWOnDS3231() {
  Wire.beginTransmission(_address);
  Wire.write(0x0E); // Datenregister
  Wire.write(0b0000000); // enable 1HZ square wave output
  Wire.endTransmission();
}

/**
   Konvertierung Dezimal zu "Binary Coded Decimal"
*/
byte MyRTC::decToBcd(byte val) {
  return ((val / 10 * 16) + (val % 10));
}

/**
   Konvertierung "Binary Coded Decimal" zu Dezimal
*/
byte MyRTC::bcdToDec(byte val) {
  return ((val / 16 * 10) + (val % 16));
}

/**
   Aus einem String zwei Stellen als Zahl bekommen.
   (Geklaut von Jee-Labs.)
*/
uint8_t MyRTC::conv2d(const char* p) {
  uint8_t v = 0;
  if ('0' <= *p && *p <= '9')
    v = *p - '0';
  return 10 * v + *++p - '0';
}

/**
   Setter/Getter
*/
void MyRTC::setSeconds(byte seconds) {
  _seconds = seconds;
}

byte MyRTC::getSeconds() {
  return _seconds;
}

/**
   Temperatur aus DS3231 lesen.
*/
int8_t MyRTC::getTemperature() {
  Wire.beginTransmission(_address);
  Wire.write(0x11);
  Wire.endTransmission();
  Wire.requestFrom(_address, 2);
  return Wire.read();
}
