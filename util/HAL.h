#ifndef HAL_H
#define HAL_H

#include "pico/stdlib.h"
#include <stdint.h>

// typedef enum {
//   LOW     = 0,
//   HIGH    = 1,
//   CHANGE  = 2,
//   FALLING = 3,
//   RISING  = 4,
// } PinStatus;

// typedef enum {
//   INPUT           = 0x0,
//   OUTPUT          = 0x1,
//   INPUT_PULLUP    = 0x2,
//   INPUT_PULLDOWN  = 0x3,
//   OUTPUT_2MA      = 0x4,
//   OUTPUT_4MA      = 0x5,
//   OUTPUT_8MA      = 0x6,
//   OUTPUT_12MA     = 0x7,
// } PinMode;

void busy_wait_us_hal(uint64_t delay_us){

}

int digitalRead_hal(uint8_t pin){
  return 0; 
}

void digitalWrite_hal(uint8_t pinNumber, uint8_t status){

}

void pinMode_hal(uint8_t pinNumber, uint8_t pinMode){

}

void noInterrupts_hal(){

}

void interrupts_hal(){

}


#define delayMicroseconds(time)         busy_wait_us_hal(time)
#define PIN_TO_BASEREG(pin)             (0)
#define PIN_TO_BITMASK(pin)             (pin)
#define IO_REG_TYPE                     unsigned int
#define IO_REG_BASE_ATTR
#define IO_REG_MASK_ATTR
#define DIRECT_READ(base, pin)          digitalRead_hal(pin)
#define DIRECT_WRITE_LOW(base, pin)     digitalWrite_hal(pin, 0) 
#define DIRECT_WRITE_HIGH(base, pin)    digitalWrite_hal(pin, 1)
#define DIRECT_MODE_INPUT(base, pin)    pinMode_hal(pin, 0) 
#define DIRECT_MODE_OUTPUT(base, pin)   pinMode_hal(pin, 1)
// #undef interrupts
// #undef noInterrupts
// #define noInterrupts()                  noInterrupts_hal()
// #define interrupts()                    interrupts_hal()

#endif