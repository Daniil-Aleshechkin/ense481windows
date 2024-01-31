#include "util.h"
#include "stm32f10x.h"
#include <stdlib.h>

#define SEED 69

struct byte_8* allocByte8();
struct byte_128* allocByte128();
struct byte_1024* allocByte1024();

void getRandomInt32s(int32_t* ints, uint16_t amount) {
    srand(SEED);
    ints = (int32_t*)malloc(sizeof(int32_t) * amount);


    for (int i = 0; i < amount; i++) {
        ints[i] = (int32_t)(rand() & 0xFFFFFFFF);
    }
}


void getRandomInt64s(int64_t* ints, uint16_t amount) {
    srand(SEED);
    ints = (int64_t*)malloc(sizeof(int64_t) * amount);


    for (int i = 0; i < amount; i++) {
        ints[i] = (int64_t)(rand() & 0xFFFFFFFFFFFFFFFF);
    }
}

void getRandomByte8s(struct byte_8** byte8s, uint16_t amount) {
    srand(SEED);
    byte8s = (struct byte_8**)malloc(sizeof(struct byte_8*) * amount);

    for (int i = 0; i < amount; i++) {
        byte8s[i] = allocByte8();
    }
}

void getRandomByte128s(struct byte_128** byte128s, uint16_t amount) {
    srand(SEED);
    byte128s = (struct byte_128**)malloc(sizeof(struct byte_128*) * amount);

    for (int i = 0; i < amount; i++) {
        byte128s[i] = allocByte128();
    }
}

void getRandomByte1024s(struct byte_1024** byte1024s, uint16_t amount) {
    srand(SEED);
    byte1024s = (struct byte_1024**)malloc(sizeof(struct byte_1024*) * amount);

    for (int i = 0; i < amount; i++) {
        byte1024s[i] = allocByte1024();
    }
}

struct byte_8* allocByte8() {
    struct byte_8* bytes = (struct byte_8*)malloc(sizeof(struct byte_8));

    for (int i = 0; i < 8; i++) {
        bytes->bytes[i] = (int8_t)(rand() & 0xFF);
    }

    return bytes;

}

struct byte_128* allocByte128() {
    struct byte_128* bytes = (struct byte_128*)malloc(sizeof(struct byte_128));

    for (int i = 0; i < 128; i++) {
        bytes->bytes[i] = (int8_t)(rand() & 0xFF);
    }

    return bytes;
}

struct byte_1024* allocByte1024() {
    struct byte_1024* bytes = (struct byte_1024*)malloc(sizeof(struct byte_1024));

    for (int i = 0; i < 1024; i++) {
        bytes->bytes[i] = (int8_t)(rand() & 0xFF);
    }

    return bytes;
}

void assignRandomInt32s(int32_t* ints, uint16_t amount) {
	    for (int i = 0; i < amount; i++) {
        ints[i] = (int32_t)(rand() & 0xFFFFFFFF);
    }
}

void assignRandomInt64s(int64_t* ints, uint16_t amount) {
	for (int i = 0; i < amount; i++) {
		ints[i] = (int64_t)(rand() & 0xFFFFFFFFFFFFFFFF);
	}
}

void assignRandomByte8(struct byte_8* byte8s) {
	for (int i = 0; i < 128; i++) {
		byte8s->bytes[i] = (int8_t)(rand() & 0xFF);
	}
}

void assignRandomByte128s(struct byte_128* byte128) {
	for (int i = 0; i < 128; i++) {
		byte128->bytes[i] = (int8_t)(rand() & 0xFF);
	}
}

void assignRandomByte1024s(struct byte_1024* byte1024) {
	for (int i = 0; i < 128; i++) {
		byte1024->bytes[i] = (int8_t)(rand() & 0xFF);
	}
}


double getAverageTime(uint16_t* times, uint16_t amount) {
		int sum = 0;
		for (int i = 0; i < amount; i++) {
			sum += times[i];
		}
		
		return sum / amount;
}

/* Dave's useful clock init function */
void clockInit(void)
{
  
		//RCC->CR |= RCC_CR_HSION;
    //while (((RCC->CR) & (RCC_CR_HSION | RCC_CR_HSIRDY)) == 0);
	
		RCC->CR |= RCC_CR_HSEON | RCC_CR_HSEBYP;
    while (((RCC->CR) & (RCC_CR_HSEON | RCC_CR_HSEBYP | RCC_CR_HSERDY)) == 0);
				
    
//SET HSI as SYSCLK and wait for it to be recognized

		//RCC->CFGR = RCC_CFGR_SW_HSI;
    //while (((RCC->CFGR) & (RCC_CFGR_SW_HSI | RCC_CFGR_SWS_HSI)) != 0);
			
//SET HSE as SYSCLK and wait for it to be recognized

		RCC->CFGR = RCC_CFGR_SW_HSE;
    while (((RCC->CFGR) & (RCC_CFGR_SW_HSE | RCC_CFGR_SWS_HSE)) == 0);

//****************To Use PLL as SYSCLK	
// Disable PLL. 
		
		//RCC->CR &= ~RCC_CR_PLLON;
			
//Change PLL source and set the PLL multiplier
			
//These are the SYSCLK values when using the PLL with HSI/2 as the input. The max value is 64 MHz
		//RCC->CFGR = 0x00000000;// 8MHz
		//RCC->CFGR = 0x00040000;// 12 MHz
		//RCC->CFGR = 0x00080000;// 16 MHz
		//RCC->CFGR = 0x000c0000;// 20 MHz			
		//RCC->CFGR = 0x00100000;// 24 MHz
		//RCC->CFGR = 0x00140000;//	28 MHz
		//RCC->CFGR = 0x00180000;// 32 MHz
		//RCC->CFGR = 0x001C0000;// 36 MHz			
		//RCC->CFGR = 0x00200000;// 40 MHz
		//RCC->CFGR = 0x00240000;//	44 MHz
		//RCC->CFGR = 0x00280000;// 48 MHz
		//RCC->CFGR = 0x002C0000;// 52 MHz
		//RCC->CFGR = 0x003C0000;// 64 MHz			

//These are the SYSCLK values when using the PLL with HSE/Bypass as the input. The max value is 72 MHz
		//RCC->CFGR = 0x00010000;// 16 MHz
		//RCC->CFGR = 0x00050000;// 24 MHz 
		//RCC->CFGR = 0x00090000;// 32 MHz
		//RCC->CFGR = 0x000d0000;// 40 MHz			
		//RCC->CFGR = 0x00110000;// 48 MHz
		//RCC->CFGR = 0x00150000;//	56 MHz
		//RCC->CFGR = 0x00190000;// 64 MHz
		RCC->CFGR = 0x001d0000;// 72 MHz		


//ENABLE PLL and wait for it to be ready

    RCC->CR |= RCC_CR_PLLON;
    while (((RCC->CR) & (RCC_CR_PLLON | RCC_CR_PLLRDY)) == 0);
   
// Set PLL as SYSCLK and wait for it to be ready
			
    RCC->CFGR |= RCC_CFGR_SW_PLL;// 0x00000002;
    while (((RCC->CFGR) & (RCC_CFGR_SW_PLL | RCC_CFGR_SWS_PLL)) == 0);
			


// Enable clock visibity on PA8 and select desired source (By default, the output will be the PLL frequency divided by 2)
			
		//RCC->CFGR |= RCC_CFGR_MCO_HSI;
		//RCC->CFGR |= RCC_CFGR_MCO_HSE;
		//RCC->CFGR |= RCC_CFGR_MCO_SYSCLK;
		//RCC->CFGR |= RCC_CFGR_MCO_PLLCLK_DIV2;		
}
