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
   LED-Treiber: 74HC595
   A4 = I2C SDA
   A5 = I2C SCL
   D10 = Data
   D12 = Clock
   D11 = Latch
   D3 = OutputEnable
   (LinesToWrite: 10)
******************************************************************************/

#if defined(LED_DRIVER_DEFAULT) && defined(BOARD_DEFAULT)
LedDriverDefault ledDriver(10, 12, 11, 3, 10);
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
#define PIN_SQW_LED 4
#define PIN_DCF77_LED 8
#define PIN_SPEAKER 13
#define PIN_TEMP_SENS A2
#endif

/******************************************************************************
   Board: DEFAULT
   LED-Treiber: POWER_SHIFT_REGISTER
   A4 = I2C SDA
   A5 = I2C SCL
   D10 = Data
   D11 = Clock
   D12 = Load
   D3 = OutputEnable
******************************************************************************/

#if defined (LED_DRIVER_POWER_SHIFT_REGISTER) && defined(BOARD_DEFAULT)
LedDriverPowerShiftRegister ledDriver(10, 12, 11, 3);
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
#endif

/******************************************************************************
   Board: UEBERPIXEL
   LED-Treiber: MAX7219
   A4 = I2C SDA
   A5 = I2C SCL
   D10 = Data
   D11 = Clock
   D12 = Load
******************************************************************************/

#if defined (LED_DRIVER_UEBERPIXEL) && defined(BOARD_UEBERPIXEL)
LedDriverUeberPixel ledDriver(5, 6, 7);
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
#endif

/******************************************************************************
   Board: AMBBRTCB
   LED-Treiber: WS2812B
   A4 = I2C SDA
   A5 = I2C SCL
   D0 = Data
******************************************************************************/

#if defined (LED_DRIVER_NEOPIXEL) && defined(BOARD_AMBBRTCAD)
LedDriverNeoPixel ledDriver(0);
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
#endif

/******************************************************************************
   Board: BBRTCAD
   LED-Treiber: DotStars
   A4 = I2C SDA
   A5 = I2C SCL
   D6 = Data
   D7 = Clock
******************************************************************************/

#if defined (LED_DRIVER_DOTSTAR) && defined(BOARD_BBRTCAD)
LedDriverDotStar ledDriver(6, 7);
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
#define PIN_TEMP_SENS -1
#endif

/******************************************************************************
   Board: BBRTCAD
   LED-Treiber: WS2812B
   A4 = I2C SDA
   A5 = I2C SCL
   D6 = Data
******************************************************************************/

#if defined (LED_DRIVER_NEOPIXEL) && defined(BOARD_BBRTCAD)
LedDriverNeoPixel ledDriver(6);
#define PIN_MODE 11
#define PIN_H_PLUS 12
#define PIN_M_PLUS 13
#define BUTTONS_PRESSING_AGAINST LOW
#define PIN_IR_RECEIVER A1
#define PIN_LDR A0
#define IS_INVERTED true
#define PIN_SQW_SIGNAL 2
#define PIN_DCF77_SIGNAL 3
#define PIN_DCF77_PON 4
#define PIN_SQW_LED 9
#define PIN_DCF77_LED 10
#define PIN_SPEAKER -1
#define PIN_TEMP_SENS A2
#endif

/******************************************************************************
   Board: BBRTCAD
   LED-Treiber: LPD8806
   A4 = I2C SDA
   A5 = I2C SCL
   D6 = Data
   D7 = Clock
******************************************************************************/

#if defined (LED_DRIVER_LPD8806) && defined(BOARD_BBRTCAD)
LedDriverLPD8806 ledDriver(6, 7);
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
#endif

/******************************************************************************
   Board: 303UNIVERSAL
   LED-Treiber: WS2812B
   A4 = I2C SDA
   A5 = I2C SCL
   D10 = Data
******************************************************************************/

#if defined (LED_DRIVER_NEOPIXEL) && defined(BOARD_303UNIVERSAL)
LedDriverNeoPixel ledDriver(10);
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
#endif

/******************************************************************************
   Board: CLT2
   LED-Treiber: WS2812B
   A4 = I2C SDA
   A5 = I2C SCL
   D13 = Data
******************************************************************************/

#if defined (LED_DRIVER_NEOPIXEL) && defined(BOARD_CLT2)
LedDriverNeoPixel ledDriver(13);
#define PIN_MODE 7
#define PIN_H_PLUS 6
#define PIN_M_PLUS 5
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
#define PIN_TEMP_SENS A0
#endif

/******************************************************************************
   Board: CLT2
   LED-Treiber: LPD8806
   A4 = I2C SDA
   A5 = I2C SCL
   D13 = Data
   D11 = Clock
******************************************************************************/

#if defined (LED_DRIVER_LPD8806) && defined(BOARD_CLT2)
LedDriverLPD8806 ledDriver(13, 11);
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
#endif

/******************************************************************************
   Board: NANO
   LED-Treiber: DotStars
   A4 = I2C SDA
   A5 = I2C SCL
   D2 = SQW Interrupt
   D6 = Data
   D5 = Clock
******************************************************************************/

#if defined (LED_DRIVER_DOTSTAR) && defined(BOARD_NANO)
LedDriverDotStar ledDriver(6, 5);
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
#endif

/******************************************************************************
   Board: NANO
   LED-Treiber: WS2812B
   A4 = I2C SDA
   A5 = I2C SCL
   D2 = SQW Interrupt
   D6 = Data
******************************************************************************/

#if defined (LED_DRIVER_NEOPIXEL) && defined(BOARD_NANO)
LedDriverNeoPixel ledDriver(6);
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
#endif

/******************************************************************************
   Board: NANO
   LED-Treiber: LPD8806
   A4 = I2C SDA
   A5 = I2C SCL
   D2 = SQW Interrupt
   D6 = Data
   D5 = Clock
******************************************************************************/

#if defined (LED_DRIVER_LPD8806) && defined(BOARD_NANO)
LedDriverLPD8806 ledDriver(6, 5);
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
#endif

#endif
