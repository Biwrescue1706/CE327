#include <stdio.h>
#include <stdint.h> // needed for uint8_t definition
int main() {
uint8_t a=0x86, b=0x7d; // hw
uint8_t c = a+b, d=a-b, e='A';
printf("a = %#x = %d, b = %#x = %d \n", a, a, b, b);
printf("c = a+b = %#x = %d \n", c, c);
printf("d = a-b = %#x = %d \n", d, d);
printf("char: e = %c = %#x \n", e, e);
printf("a & b = %#x = %d\n", a & b, a & b); // bit-wise AND
printf("a | b = %#x = %d\n", a | b, a | b); // bit-wise OR
printf("a ^ b = %#x = %d\n", a ^ b, a ^ b); // bit-wise XOR
printf("~a = %#x = %d\n", ~a, ~a); // bit-wise NOT
c = a << 2;
d = a >> 2;
e = c >> 2;
printf("c = a << 2 = %#x = %d\n", c, c);
printf("d = a >> 2 = %#x = %d\n", d, d);
printf("e = c >> 2 = %#x = %d\n", e, e);
printf("a && 0 = %#x = %d\n", a && 0, a && 0); // Boolean AND
printf("a || 0 = %#x = %d\n", a || 0, a || 0); // Boolean OR
printf("!a = %#x = %d\n", !a, !a); // Boolean NOT
return 0;
}