#include <stdio.h>
#include <stdint.h>

float fp32_to_decimal(uint32_t hex) {
    // Extract the sign, exponent, and fraction
    uint32_t sign = (hex >> 31) & 0x01;
    uint32_t exponent = (hex >> 23) & 0xFF;
    uint32_t fraction = hex & 0x7FFFFF;

    // Calculate the actual exponent
    int32_t actual_exponent = exponent - 127;

    // Calculate the mantissa
    float mantissa = 1.0; // Start with the implicit leading 1
    for (int i = 0; i < 23; i++) {
        if (fraction & (1 << (22 - i))) {
            mantissa += (1.0 / (1 << (i + 1))); // Add the fraction part
        }
    }

    // Calculate the final decimal value
    float value = (sign ? -1 : 1) * mantissa * (1 << actual_exponent);
    return value;
}
int main() {
    uint32_t hex_values[] = {0x40400000, 0xC0500000, 0x3F600000, 0x70500000, 0x00600000, 0x40400001};
    
    for (int i = 0; i < sizeof(hex_values) / sizeof(hex_values[0]); i++) {
        float decimal_value = fp32_to_decimal(hex_values[i]);
        printf("Hex: 0x%08X, Decimal: %.6f\n", hex_values[i], decimal_value);
    }
    
    return 0;
}