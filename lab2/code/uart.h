#include "stdint.h"

#ifndef UTIL
#define UTIL


struct byte_8 {
    int8_t bytes[8];
};

struct byte_128 {
    int8_t bytes[128];
};

struct byte_1024 {
    int8_t bytes[1024];
};


void getRandomInt32s(int32_t* ints, uint16_t amount);
void getRandomInt64s(int64_t* ints, uint16_t amount);
void getRandomByte8s(struct byte_8** byte8s, uint16_t amount);
void getRandomByte128s(struct byte_128** byte8s, uint16_t amount);
void getRandomByte1024s(struct byte_1024** byte8s, uint16_t amount);

void assignRandomInt32s(int32_t* ints, uint16_t amount);
void assignRandomInt64s(int64_t* ints, uint16_t amount);
void assignRandomDoubles(double* doubles, uint16_t amount);
void assignRandomByte8(struct byte_8* byte8s);
void assignRandomByte128s(struct byte_128* byte8s);
void assignRandomByte1024s(struct byte_1024* byte8s);

double getAverageTime(uint16_t* times, uint16_t amount);

void clockInit(void);
#endif