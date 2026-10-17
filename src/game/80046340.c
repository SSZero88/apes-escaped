#include "common.h"
#include "m2c_macros.h"
#include "gte.h"
#include "gte.h"

long ratan2(long y, long x);

s32 Vec_Length(s32 x, s32 y, s32 z);
/* integer square root, rounded: two bits per step from the highest set bit */
s32 Math_ISqrt(s32 n);
/* length of (x, y, z): Math_ISqrt is the square root */

s32 Math_Atan2(s32 x, s32 y) {
    if (y == 0) {
        return (x >> 31) & 0x800;
    }
    return ratan2(y, x);
}

void func_8004637C(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x14) = 0;
    M2C_FIELD(arg0, s32 *, 0x18) = 0;
    M2C_FIELD(arg0, s32 *, 0x1C) = 0;
    M2C_FIELD(arg0, s32 *, 4) = 0;
    M2C_FIELD(arg0, s32 *, 0xC) = 0;
    M2C_FIELD(arg0, s32 *, 0) = 0x1000;
    M2C_FIELD(arg0, s32 *, 8) = 0x1000;
    M2C_FIELD(arg0, s32 *, 0x10) = 0x1000;
}

s32 func_800463A4(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_v1;

    temp_v1 = arg0 - arg1;
    if (temp_v1 == 0) {
        return arg0;
    }
    if (temp_v1 >= arg2) {
        return arg0 - arg2;
    }
    if (-arg2 >= temp_v1) {
        return arg0 + arg2;
    }
    return arg1;
}

void func_800463E4(void *arg0, void *arg1, s32 arg2) {
    s32 temp_s2;
    s32 temp_s4;
    s32 temp_s5;
    s32 temp_v0;

    temp_s5 = M2C_FIELD(arg1, s16 *, 0) - M2C_FIELD(arg0, s16 *, 0);
    temp_s2 = M2C_FIELD(arg1, s16 *, 2) - M2C_FIELD(arg0, s16 *, 2);
    temp_s4 = M2C_FIELD(arg1, s16 *, 4) - M2C_FIELD(arg0, s16 *, 4);
    temp_v0 = Vec_Length(temp_s5, temp_s2, temp_s4);
    if (arg2 >= temp_v0) {
        M2C_FIELD(arg0, s16 *, 0) = (s16) (u16) M2C_FIELD(arg1, s16 *, 0);
        M2C_FIELD(arg0, s16 *, 2) = (s16) (u16) M2C_FIELD(arg1, s16 *, 2);
        M2C_FIELD(arg0, s16 *, 4) = (s16) (u16) M2C_FIELD(arg1, s16 *, 4);
        return;
    }
    M2C_FIELD(arg0, s16 *, 0) = (s16) ((u16) M2C_FIELD(arg0, s16 *, 0) + ((s32) (temp_s5 * arg2) / temp_v0));
    M2C_FIELD(arg0, s16 *, 2) = (s16) ((u16) M2C_FIELD(arg0, s16 *, 2) + ((s32) (temp_s2 * arg2) / temp_v0));
    M2C_FIELD(arg0, s16 *, 4) = (s16) ((u16) M2C_FIELD(arg0, s16 *, 4) + ((s32) (temp_s4 * arg2) / temp_v0));
}

s32 Math_ISqrt(s32 n) {
    s32 root;
    s32 rem;
    s32 i;
    s32 half;
    s32 t;
    s32 bits;

    if (n <= 0) {
        return 0;
    }
    gte_ldLZCS(n);
    root = 0;
    rem = 0;
    gte_stLZCR(half);
    i = 1;
    half = (0x21 - half) >> i;
    for (; i <= half + 1; i++) {
        root <<= 1;
        bits = (n >> ((half - i) * 2)) & 3;
        rem = (rem << 2) + bits;
        t = root * 2 + 1;
        if (rem >= t) {
            rem -= t;
            root++;
        }
    }
    return (root >> 1) + (root & 1);
}

s32 Vec_Length(s32 x, s32 y, s32 z) {
    gte_ldIR1(x);
    gte_ldIR2(y);
    gte_ldIR3(z);
    gte_sqr0();
    gte_stMAC1(x);
    gte_stMAC2(y);
    gte_stMAC3(z);
    return Math_ISqrt(x + y + z);
}
