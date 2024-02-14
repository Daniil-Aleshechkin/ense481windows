#include "sttimer.h"
#include "stm32f10x.h"

void timer_init(void) {
    RCC->APB1ENR  |= RCC_APB1ENR_TIM2EN;

    // Disable clock division
    TIM2->CR1 &= TIM_CR1_CKD;
    
    // Set to down counter
    TIM2->CR1 |= TIM_CR1_DIR; 

    // Set prescaler to 1
    TIM2->PSC = 0;

    // Set ARR to the maximum
    TIM2->ARR = 0xFFFF -1 ;

    // Enable the timer
    TIM2->CR1 |= TIM_CR1_CEN;

    while (!(TIM2->SR & TIM_SR_UIF));
}

uint16_t timer_start(void) {
    return TIM2->CNT & 0xFFFF;
}

uint16_t timer_stop(uint16_t start_time) {
    // This actually measures from a range of clock cycles from 1 - 65536, because it's impossible to measure a 0 clock cycle opperation. Starting the timer and exiting the function should take > 1 cycle

    uint16_t finalTime = TIM2->CNT & 0xFFFF;

    if (finalTime >= start_time) {
        return 0xFFFF - (start_time - finalTime);
    } else {
        return start_time - finalTime;
    }
}

void timer_shutdown(void) {
    TIM2->CR1 &= TIM_CR1_CEN;
}