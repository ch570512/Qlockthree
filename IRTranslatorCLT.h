/*
   IRTranslatorCLT

   @mc       Arduino/RBBB
   @autor    Manuel Bracher / bracher _AT_ win _DOT_ com
   @version  1.1
   @created  5.5.2015
*/

#ifndef IRTRANSLATORCLT_H
#define IRTRANSLATORCLT_H

#include "IRTranslator.h"

class IRTranslatorCLT : public IRTranslator {
  public:
    void printSignature();
    byte buttonForCode(unsigned long code);
};

#endif
