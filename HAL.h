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
void default_delayMicroseconds_hal(uint64_t delay_us);

int digitalRead_hal(uint8_t pin);

void digitalWrite_hal(uint8_t pinNumber, uint8_t status);

void pinMode_hal(uint8_t pinNumber, uint8_t pinMode);

void noInterrupts_hal();

void interrupts_hal();

#endif