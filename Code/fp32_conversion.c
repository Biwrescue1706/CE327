#include <stdio.h>
#include <stdint.h>

void print_fp32(float value) {
    // Declare a union to access the bits of the float
    union {
        float f;
        uint32_t u;
    } fp;

    fp.f = value;

    // Print the value in hexadecimal
    printf("Decimal: %.4f, Hex: 0x%08X\n", value, fp.u);
}

int main() {
    float values[] = {0.125, 0.1875, 0.25, 3.25, 16.0, 13.0};
    
    for (int i = 0; i < sizeof(values) / sizeof(values[0]); i++) {
        print_fp32(values[i]);
    }
    
    return 0;
}
