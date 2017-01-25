/**
   Boards
   Defines for the various boards and LED drivers.

   @mc       Arduino
   @autor
   @version  1.1
   @created  20.01.2017
*/

#ifndef BOARDS_H
#define BOARDS_H

/******************************************************************************
   Board: DEFAULT
   A4 = I2C SDA
   A5 = I2C SCL
   D10 = Data
   D11 = Clock
   D12 = Load
   D3 = OutputEnable
******************************************************************************/

#ifdef BOARD_DEFAULT
#define PIN_MODE 7
#define PIN_H_PLUS 6
#define PIN_M_PLUS 5
#define BUTTONS_PRESSING_AGAINST HIGH
#define PIN_IR_RECEIVER A1
#define PIN_LDR A3
#define IS_INVERTED true
#define PIN_SQW_SIGNAL 2
#define PIN_DCF77_SIGNAL 9
#define PIN_DCF77_PON A0
#define PIN_SQW_LED -1
#define PIN_DCF77_LED -1
#define PIN_SPEAKER -1
#define PIN_TEMP_SENS A2
#define PIN_LEDS_CLOCK 11
#define PIN_LEDS_DATA 10
#define PIN_LEDS_LOAD 12
#define PIN_LEDS_OUTPUT_ENABLE 3
#endif

/******************************************************************************
   Board: UEBERPIXEL
   A4 = I2C SDA
   A5 = I2C SCL
   D5 = Data
   D6 = Clock
   D7 = Load
******************************************************************************/

#ifdef BOARD_UEBERPIXEL
#define PIN_MODE 8
#define PIN_H_PLUS 4
#define PIN_M_PLUS 3
#define BUTTONS_PRESSING_AGAINST HIGH
#define PIN_IR_RECEIVER A1
#define PIN_LDR A3
#define IS_INVERTED true
#define PIN_SQW_SIGNAL 2
#define PIN_DCF77_SIGNAL 9
#define PIN_DCF77_PON A0
#define PIN_SQW_LED 10
#define PIN_DCF77_LED 11
#define PIN_SPEAKER 13
#define PIN_TEMP_SENS A2
#define PIN_LEDS_CLOCK 6
#define PIN_LEDS_DATA 5
#define PIN_LEDS_LOAD 7
#endif

/******************************************************************************
   Board: AMBBRTCB
   A4 = I2C SDA
   A5 = I2C SCL
   D0 = Data
******************************************************************************/

#ifdef BOARD_AMBBRTCAD
#define PIN_MODE 5
#define PIN_H_PLUS 6
#define PIN_M_PLUS 7
#define BUTTONS_PRESSING_AGAINST LOW
#define PIN_IR_RECEIVER A1
#define PIN_LDR A0
#define IS_INVERTED false
#define PIN_SQW_SIGNAL 10
#define PIN_DCF77_SIGNAL 3
#define PIN_DCF77_PON -1
#define PIN_SQW_LED 1
#define PIN_DCF77_LED 2
#define PIN_SPEAKER -1
#define PIN_TEMP_SENS -1
#define PIN_LEDS_DATA 0
#endif

/******************************************************************************
   Board: BBRTCAD
   A4 = I2C SDA
   A5 = I2C SCL
   D6 = Data
   D7 = Clock
******************************************************************************/

#ifdef BOARD_BBRTCAD
#define PIN_MODE 11
#define PIN_H_PLUS 12
#define PIN_M_PLUS 13
#define BUTTONS_PRESSING_AGAINST LOW
#define PIN_IR_RECEIVER A1
#define PIN_LDR A0
#define IS_INVERTED false
#define PIN_SQW_SIGNAL 2
#define PIN_DCF77_SIGNAL 3
#define PIN_DCF77_PON 4
#define PIN_SQW_LED 9
#define PIN_DCF77_LED 10
#define PIN_SPEAKER -1
#define PIN_TEMP_SENS A2
#define PIN_LEDS_CLOCK 7
#define PIN_LEDS_DATA 6
#endif

/******************************************************************************
   Board: 303UNIVERSAL
   A4 = I2C SDA
   A5 = I2C SCL
   D10 = Data
******************************************************************************/

#ifdef BOARD_303UNIVERSAL
#define PIN_MODE 7
#define PIN_H_PLUS 6
#define PIN_M_PLUS 5
#define BUTTONS_PRESSING_AGAINST HIGH
#define PIN_IR_RECEIVER A1
#define PIN_LDR A3
#define IS_INVERTED true
#define PIN_SQW_SIGNAL 2
#define PIN_DCF77_SIGNAL 9
#define PIN_DCF77_PON A0
#define PIN_SQW_LED -1
#define PIN_DCF77_LED 12
#define PIN_SPEAKER -1
#define PIN_TEMP_SENS -1
#define PIN_LEDS_DATA 10
#endif

/******************************************************************************
   Board: CLT2
   A4 = I2C SDA
   A5 = I2C SCL
   D13 = Data
   D11 = Clock
******************************************************************************/

#ifdef BOARD_CLT2
#define PIN_MODE 7
#define PIN_M_PLUS 5
#define PIN_H_PLUS 6
#define BUTTONS_PRESSING_AGAINST HIGH
#define PIN_IR_RECEIVER 10
#define PIN_LDR A3
#define IS_INVERTED true
#define PIN_SQW_SIGNAL 2
#define PIN_DCF77_SIGNAL 9
#define PIN_DCF77_PON -1
#define PIN_SQW_LED 4
#define PIN_DCF77_LED 8
#define PIN_SPEAKER -1
#define PIN_TEMP_SENS -1
#define PIN_LEDS_CLOCK 11
#define PIN_LEDS_DATA 13
#endif

/******************************************************************************
   Board: NANO
   A4 = I2C SDA
   A5 = I2C SCL
   D2 = SQW Interrupt
   D6 = Data
   D5 = Clock
******************************************************************************/

#ifdef BOARD_NANO
#define PIN_MODE   10
#define PIN_H_PLUS  9
#define PIN_M_PLUS  8
#define BUTTONS_PRESSING_AGAINST LOW
#define PIN_IR_RECEIVER A1
#define PIN_LDR A0
#define IS_INVERTED true
#define PIN_SQW_SIGNAL   2
#define PIN_DCF77_SIGNAL 3
#define PIN_DCF77_PON 4
#define PIN_SQW_LED LED_BUILTIN
#define PIN_DCF77_LED 12
#define PIN_SPEAKER 11
#define PIN_TEMP_SENS A2
#define PIN_LEDS_CLOCK 5
#define PIN_LEDS_DATA 6
#endif

#endif
