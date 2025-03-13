#ifndef HAL_H
#define HAL_H

#include "pico/stdlib.h"
#include <stdint.h>

void busy_wait_us_hal(uint64_t delay_us){

}

int digitalRead_hal(uint8_t pin){

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
#define DIRECT_READ(base, pin)          digitalRead(pin)
#define DIRECT_WRITE_LOW(base, pin)     digitalWrite_hal(pin, 0) 
#define DIRECT_WRITE_HIGH(base, pin)    digitalWrite_hal(pin, 1)
#define DIRECT_MODE_INPUT(base, pin)    pinMode_hal(pin, 0) 
#define DIRECT_MODE_OUTPUT(base, pin)   pinMode_hal(pin, 1)
#undef interrupts
#undef noInterrupts
#define noInterrupts()                  noInterrupts_hal()
#define interrupts()                    interrupts_hal()

#endif