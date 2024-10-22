// limits_ex_hw.c
#include <stdio.h>
#include <limits.h> // for limits
#include <stdint.h> // for uint32_t type
int main() {
int a=-1;
unsigned int b=0;
printf("0. INT_MIN = %#x, Signed value = %d, Unsigned value = %u\n",
INT_MIN, INT_MIN, INT_MIN);
printf("1. a = %#x, Signed value = %d, Unsigned value = %u\n", a, a, a);

printf("2 a-1 = %#x, Signed value = %d, Unsigned value = %u\n", a-1, a-
1, a-1);

printf("3. b = %#x, Signed value = %d, Unsigned value = %u\n", b, b, b);

printf("4. b-1 = %#x, Signed value = %d, Unsigned value = %u\n", b-1, b-
1, b-1);

printf("5. sizeof: a=%d, b=%d, char=%d, long int=%d\n", (int) sizeof(a),
(int) sizeof(b), (int) sizeof(char), (int) sizeof(long int));
}