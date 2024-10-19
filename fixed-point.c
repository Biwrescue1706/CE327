#include <stdio.h>
#include <math.h>

#define FIXED_POINT_BITS 8
#define INTEGER_BITS 3
#define FRACTION_BITS 5

unsigned char to_fixed_point(double value) {
    // Check if the value is in range
    if (value < 0 || value >= (1 << INTEGER_BITS)) {
        printf("Value %f out of range\n", value);
        return 0;
    }

    // Round to the nearest value in fixed-point
    double scaled_value = value * (1 << FRACTION_BITS);
    unsigned char fixed_value = (unsigned char)round(scaled_value);

    return fixed_value;
}

void print_fixed_point(double value) {
    unsigned char fixed_value = to_fixed_point(value);
    
    // Calculate decimal representation from fixed point
    double decimal_value = (fixed_value >> FRACTION_BITS) + (fixed_value & ((1 << FRACTION_BITS) - 1)) / (double)(1 << FRACTION_BITS);
    
    // Calculate conversion error
    double conversion_error = decimal_value - value;

    // Print results
    printf("Original: %.4f, Fixed: 0b", value);
    for (int i = FIXED_POINT_BITS - 1; i >= 0; i--) {
        printf("%d", (fixed_value >> i) & 1);
    }
    printf(" (0x%02X), Decimal Value: %.4f, Error: %.4f\n", fixed_value, decimal_value, conversion_error);
}

int main() {
    double values[] = {0.25, 0.025, 2.75, 5.0625, 0.1, 3.125};
    
    for (int i = 0; i < sizeof(values) / sizeof(values[0]); i++) {
        print_fixed_point(values[i]);
    }
    
    return 0;
}