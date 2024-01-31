#include <stdint.h>
#include "util.h"

#ifndef TIME_OPS
#define TIME_OPS 

int32_t add32(int32_t, int32_t);
int64_t add64(int64_t, int64_t);
int32_t mult32(int32_t, int32_t);
int64_t mult64(int64_t, int64_t);
int32_t div32(int32_t, int32_t);
int64_t div64(int64_t, int64_t);
struct byte_8 copyByte8(struct byte_8* bytes);
struct byte_128 copyByte128(struct byte_128* bytes);
struct byte_1024 copyByte1024(struct byte_1024* bytes);

#endif