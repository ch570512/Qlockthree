/**
 * Settings
 * Die vom Benutzer getaetigten Einstellungen werden hier verwaltet
 * und im EEPROM persistiert.
 *
 * @mc       Arduino/RBBB
 * @autor    Christian Aschoff / caschoff _AT_ mac _DOT_ com
 * @version  1.3
 * @created  23.1.2013
 */
 
#include "Settings.h"
#include <EEPROM.h>
#include "Renderer.h"

#define SETTINGS_MAGIC_NUMBER 0x2A
#define SETTINGS_VERSION 0

/**
 *  Konstruktor.
 */
Settings::Settings() {
  // um 3 Uhr Display abschalten (Minuten, Stunden, -, -, -, -)
  _nightModeTime[0] = new TimeStamp(0, 3, 0, 0, 0, 0);
  // um 4:30 Uhr Display wieder anschalten (Minuten, Stunden, -, -, -, -)
  _nightModeTime[1] = new TimeStamp(30, 4, 0, 0, 0, 0);
  resetToDefault();
  // Versuche alte Einstellungen zu laden...
  loadFromEEPROM();
}

/**
 * Setzt alle Werte auf Defauleinstellungen zurück.
 */
void Settings::resetToDefault() {
  _language = 0; //erste Sprache in Renderer::eLanguage
  _event = 0;
  _renderCornersCw = true;
  _use_ldr = true;
  _brightness = 75;
  _enableAlarm = true;
  _transitionMode = TRANSITION_MODE_NORMAL;
  _dcfSignalIsInverted = false;
  _timeShift = 0;
  _color = color_white;
  _colorChangeRate = 0;
  // um 3 Uhr Display abschalten (Minuten, Stunden, -, -, -, -)
  _nightModeTime[0]->set(0, 3, 0, 0, 0, 0);
  // um 4:30 Uhr Display wieder anschalten (Minuten, Stunden, -, -, -, -)
  _nightModeTime[1]->set(30, 4, 0, 0, 0, 0);
  _jumpToNormalTimeout = 5;
  _esIst = true;
}

byte Settings::getLanguage() {
  return _language;
}

void Settings::setLanguage(byte language) {
  _language = language;
}

byte Settings::getEvent() {
  return _event;
}

void Settings::setEvent(byte event) {
  _event = event;
}

boolean Settings::getRenderCornersCw() {
  return _renderCornersCw;
}

void Settings::setRenderCornersCw(boolean cw) {
  _renderCornersCw = cw;
}

boolean Settings::getUseLdr() {
  return _use_ldr;
}

void Settings::setUseLdr(boolean useLdr) {
  _use_ldr = useLdr;
}

byte Settings::getBrightness() {
  return _brightness;
}

void Settings::setBrightness(byte brightness) {
  _brightness = brightness;
}

void Settings::setColor(eColors color) {
  _color = color;
}

eColors Settings::getColor() {
  return _color;
}

boolean Settings::getEnableAlarm() {
  return _enableAlarm;
}

void Settings::setEnableAlarm(boolean enableAlarm) {
  _enableAlarm = enableAlarm;
}

boolean Settings::getDcfSignalIsInverted() {
  return _dcfSignalIsInverted;
}

void Settings::setDcfSignalIsInverted(boolean dcfSignalIsInverted) {
  _dcfSignalIsInverted = dcfSignalIsInverted;
}

char Settings::getTimeShift() {
  return _timeShift;
}

byte Settings::getJumpToNormalTimeout() {
    return _jumpToNormalTimeout;
}

void Settings::setJumpToNormalTimeout(byte jumpToNormalTimeout) {
    _jumpToNormalTimeout = jumpToNormalTimeout;
}

void Settings::setTimeShift(char timeShift) {
  _timeShift = timeShift;
}

byte Settings::getTransitionMode() {
  return _transitionMode;
}
void Settings::setTransitionMode(byte transitionMode) {
  _transitionMode = transitionMode;
}

TimeStamp* Settings::getNightModeTime(bool onTime) {
  return _nightModeTime[onTime];
}

void Settings::setColorChangeRate(byte rate) {
  _colorChangeRate = rate;
}

byte Settings::getColorChangeRate() {
  return _colorChangeRate;
}

boolean Settings::getEsIst() {
    return _esIst;
}

void Settings::toggleEsIst() {
    _esIst = !_esIst;
}

/**
 * Die Einstellungen laden.
 */
void Settings::loadFromEEPROM() {
  if ((EEPROM.read(0) == SETTINGS_MAGIC_NUMBER) && (EEPROM.read(1) == SETTINGS_VERSION)) {
    // es sind gueltige Einstellungen vorhanden...
    if (EEPROM.read(2) < LANGUAGE_COUNT){
    _language = EEPROM.read(2);
    }
    _renderCornersCw = EEPROM.read(3);
    _use_ldr = EEPROM.read(4);
    _brightness = EEPROM.read(5);
    _enableAlarm = EEPROM.read(6);
    _dcfSignalIsInverted = EEPROM.read(7);
    _timeShift = EEPROM.read(8);
    _transitionMode = EEPROM.read(9);
    _color = (eColors)EEPROM.read(10);
    _event = EEPROM.read(11);
    _nightModeTime[0]->set(EEPROM.read(12), EEPROM.read(13), 0, 0, 0, 0);
    _nightModeTime[1]->set(EEPROM.read(14), EEPROM.read(15), 0, 0, 0, 0);
    _jumpToNormalTimeout = EEPROM.read(16);
    _colorChangeRate = EEPROM.read(17);
    _esIst = EEPROM.read(18);
  }
}

/**
 * Die Einstellungen speichern.
 */
void Settings::saveToEEPROM() {
  if (EEPROM.read(0) != SETTINGS_MAGIC_NUMBER) {
    EEPROM.write(0, SETTINGS_MAGIC_NUMBER);
  }
  if (EEPROM.read(1) != SETTINGS_VERSION) {
    EEPROM.write(1, SETTINGS_VERSION);
  }
  if (EEPROM.read(2) != _language) {
    EEPROM.write(2, _language);
  }
  if (EEPROM.read(3) != _renderCornersCw) {
    EEPROM.write(3, _renderCornersCw);
  }
  if (EEPROM.read(4) != _use_ldr) {
    EEPROM.write(4, _use_ldr);
  }
  if (EEPROM.read(5) != _brightness) {
    EEPROM.write(5, _brightness);
  }
  if (EEPROM.read(6) != _enableAlarm) {
    EEPROM.write(6, _enableAlarm);
  }
  if (EEPROM.read(7) != _dcfSignalIsInverted) {
    EEPROM.write(7, _dcfSignalIsInverted);
  }
  if (EEPROM.read(8) != _timeShift) {
    EEPROM.write(8, _timeShift);
  }
  if (EEPROM.read(9) != _transitionMode) {
    EEPROM.write(9, _transitionMode);
  }
  if (EEPROM.read(10) != _color) {
    EEPROM.write(10, _color);
  }
  if (EEPROM.read(11) != _event) {
    EEPROM.write(11, _event);
  }
  if (EEPROM.read(12) != _nightModeTime[0]->getMinutes()) {
    EEPROM.write(12, _nightModeTime[0]->getMinutes());
  }
  if (EEPROM.read(13) != _nightModeTime[0]->getHours()) {
    EEPROM.write(13, _nightModeTime[0]->getHours());
  }
  if (EEPROM.read(14) != _nightModeTime[1]->getMinutes()) {
    EEPROM.write(14, _nightModeTime[1]->getMinutes());
  }
  if (EEPROM.read(15) != _nightModeTime[1]->getHours()) {
    EEPROM.write(15, _nightModeTime[1]->getHours());
  }
  if (EEPROM.read(16) != _jumpToNormalTimeout) {
    EEPROM.write(16, _jumpToNormalTimeout);
  }
  if (EEPROM.read(17) != _colorChangeRate) {
    EEPROM.write(17, _colorChangeRate);
  }
  if (EEPROM.read(18) != _esIst) {
    EEPROM.write(18, _esIst);
  }
}
