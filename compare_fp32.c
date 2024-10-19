#include <stdio.h>
#include <stdint.h>

typedef struct {
    uint32_t sign : 1;
    uint32_t exponent : 8;
    uint32_t significand : 23;
} fp32;

fp32 extract_fp32(uint32_t hex) {
    fp32 number;
    number.sign = (hex >> 31) & 0x01;
    number.exponent = (hex >> 23) & 0xFF;
    number.significand = hex & 0x7FFFFF;
    return number;
}

int compare_fp32(uint32_t hex1, uint32_t hex2) {
    fp32 num1 = extract_fp32(hex1);
    fp32 num2 = extract_fp32(hex2);

    if (num1.sign != num2.sign) {
        return num1.sign ? -1 : 1; // Negative is smaller
    }
    if (num1.exponent != num2.exponent) {
        return (num1.exponent > num2.exponent) ? 1 : -1; // Compare exponents
    }
    if (num1.significand != num2.significand) {
        return (num1.significand > num2.significand) ? 1 : -1; // Compare significands
    }
    return 0; // They are equal
}

void compare_and_print(uint32_t hex1, uint32_t hex2) {
    int result = compare_fp32(hex1, hex2);
    if (result > 0) {
        printf("0x%08X is larger than 0x%08X\n", hex1, hex2);
    } else if (result < 0) {
        printf("0x%08X is larger than 0x%08X\n", hex2, hex1);
    } else {
        printf("0x%08X is equal to 0x%08X\n", hex1, hex2);
    }
}

int main() {
    uint32_t pairs[][2] = {
        {0x40400000, 0xC0500000},
        {0x40400000, 0x3F600000},
        {0x40400000, 0x40100000},
        {0xB0400000, 0xA0900000}
    };

    for (int i = 0; i < sizeof(pairs) / sizeof(pairs[0]); i++) {
        compare_and_print(pairs[i][0], pairs[i][1]);
    }

    return 0;
}