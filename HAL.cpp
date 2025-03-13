#include "HAL.h"
#include "hardware/sync.h"

#define DEFAULT 0
#if DEFAULT
#include <Arduino.h>
#else
typedef enum {
    INPUT           = 0x0,
    OUTPUT          = 0x1,
    INPUT_PULLUP    = 0x2,
    INPUT_PULLDOWN  = 0x3,
    OUTPUT_2MA      = 0x4,
    OUTPUT_4MA      = 0x5,
    OUTPUT_8MA      = 0x6,
    OUTPUT_12MA     = 0x7,
} PinMode;
#endif

void delayMicroseconds_hal(uint64_t delay_us){
    busy_wait_us(delay_us); 
}

int digitalRead_hal(uint8_t pin){
    #if DEFAULT && 0
    return digitalRead(pin); 
    #else
    return gpio_get(pin); 
    #endif 
}

void digitalWrite_hal(uint8_t pinNumber, uint8_t status){
    #if DEFAULT && 0
    digitalWrite(pinNumber, status); 
    #else
    gpio_put(pinNumber, status); 
    #endif 
}

void copiedPinMode(uint8_t ulPin, uint8_t ulMode){
    // if (ulPin >= __GPIOCNT) {
    //     DEBUGCORE("ERROR: Illegal pin in pinMode (%d)\n", ulPin);
    //     return;
    // }

    switch (ulMode) {
    case INPUT:
        gpio_init(ulPin);
        gpio_set_dir(ulPin, false);
        gpio_disable_pulls(ulPin);
        break;
    case INPUT_PULLUP:
        gpio_init(ulPin);
        gpio_set_dir(ulPin, false);
        gpio_pull_up(ulPin);
        gpio_put(ulPin, 0);
        break;
    case INPUT_PULLDOWN:
        gpio_init(ulPin);
        gpio_set_dir(ulPin, false);
        gpio_pull_down(ulPin);
        gpio_put(ulPin, 1);
        break;
    case OUTPUT:
    case OUTPUT_4MA:
        gpio_init(ulPin);
        gpio_set_drive_strength(ulPin, GPIO_DRIVE_STRENGTH_4MA);
        gpio_set_dir(ulPin, true);
        break;
    case OUTPUT_2MA:
        gpio_init(ulPin);
        gpio_set_drive_strength(ulPin, GPIO_DRIVE_STRENGTH_2MA);
        gpio_set_dir(ulPin, true);
        break;
    case OUTPUT_8MA:
        gpio_init(ulPin);
        gpio_set_drive_strength(ulPin, GPIO_DRIVE_STRENGTH_8MA);
        gpio_set_dir(ulPin, true);
        break;
    case OUTPUT_12MA:
        gpio_init(ulPin);
        gpio_set_drive_strength(ulPin, GPIO_DRIVE_STRENGTH_12MA);
        gpio_set_dir(ulPin, true);
        break;
    default:
        // DEBUGCORE("ERROR: Illegal pinMode mode (%d)\n", ulMode);
        // Error
        return;
    }

    // _pm[ulPin] = ulMode;

    // if (ulPin >= __FIRSTANALOGGPIO) {
    //     __clearADCPin(ulPin);
    // }
}

void pinMode_hal(uint8_t pinNumber, uint8_t mode){
    #if DEFAULT && 0
    pinMode(pinNumber, mode); 
    #else
    copiedPinMode(pinNumber, mode); 
    #endif 
}

void interrupts_toggle(uint8_t on){
    static uint32_t ints = 0; 
    if(on){
        restore_interrupts(ints); 
    } else {
        ints = save_and_disable_interrupts(); 
    }
}

void noInterrupts_hal(){
    #if DEFAULT && 0
    noInterrupts(); 
    #else
    interrupts_toggle(0); 
    #endif 
}

void interrupts_hal(){
    #if DEFAULT && 0
    interrupts();
    #else
    interrupts_toggle(1); 
    #endif 
}