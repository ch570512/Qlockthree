/**
   IRTranslator
   Abstrakte Klasse fuer die Umsetzung von Fernbedienungs-Codes.

   @mc       Arduino/RBBB
   @autor    Christian Aschoff / caschoff _AT_ mac _DOT_ com
   @version  1.1
   @created  7.2.2015
*/

#include "IRTranslator.h"

eColors IRTranslator::getColor() {
  return _color;
}

Mode IRTranslator::getMode() {
  return _mode;
}

byte IRTranslator::getTransition() {
  return _transition;
}

void IRTranslator::setColor(eColors color) {
  _color = color;
}

void IRTranslator::setMode(Mode mode) {
  _mode = mode;
}

void IRTranslator::setTransition(byte transition) {
  _transition = transition;
}
