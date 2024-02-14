#include "stdint.h"

#ifndef TIMER
#define TIMER

void timer_init(void);
uint16_t timer_start(void);
uint16_t timer_stop(uint16_t start_time);
void timer_shutdown(void);

#endif 
