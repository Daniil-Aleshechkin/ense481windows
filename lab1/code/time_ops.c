#include "util.h"
#include "time_ops.h"

int32_t add32(int32_t int1, int32_t int2) {
    return int1 + int2;
}

int64_t add64(int64_t int1, int64_t int2) {
    return int1 + int2;
}

int32_t mult32(int32_t int1, int32_t int2) {
    return int1 * int2;
}

int64_t mult64(int64_t int1, int64_t int2) {
    return int1 * int2;
}


// TODO: Ask karim if he wants floats or ints for div
int32_t div32(int32_t int1, int32_t int2) {
    if (int2 == 0) {
        return 0xFFFFFFFF;
    }

    return int1 / int2;
}

int64_t div64(int64_t int1, int64_t int2) {
    if (int2 == 0) {
        return 0xFFFFFFFFFFFFFFFF;
    }

    return int2 / int2;
}

struct byte_8 copyByte8(struct byte_8* bytes) {
    struct byte_8 copy = *bytes;

    return copy;
}

struct byte_128 copyByte128(struct byte_128* bytes) {
    struct byte_128 copy = *bytes;

    return copy;
}

struct byte_1024 copyByte1024(struct byte_1024* bytes) {
    struct byte_1024 copy = *bytes;

    return copy;
}
