#include <stdio.h>

typedef struct foo {
    int b;
    float x, y;
} foo;

int main() {
    int a = 45; // suppose a is stored at address 0x1000
    int s[15]; // hence, s[0] is stored at address 0x1004
    int *ptr1 = &a, *ptr2 = s, *ptr3, *ptr5;
    foo z;
    float *ptr4 = &(z.x);

    int c1 = sizeof(a);
    int c2 = sizeof(z);
    int c3 = sizeof(ptr1);
    int c4 = sizeof(s);

    for (int i = 0; i < 6; i++) {
        s[i] = 2 + i; // Initializing s[0] to s[5]
    }

    ptr3 = &s[2];
    ptr5 = &(z.b);

    // Output the sizes
    printf("c1 = %d\n", c1);
    printf("c2 = %d\n", c2);
    printf("c3 = %d\n", c3);
    printf("c4 = %d\n", c4);

    // Output pointer values
    printf("ptr1 = %p\n", (void*)ptr1);
    printf("ptr2 = %p\n", (void*)ptr2);
    printf("ptr3 = %p\n", (void*)ptr3);
    printf("ptr5 = %p\n", (void*)ptr5);

    // Output dereferenced values
    printf("*ptr1 = %d\n", *ptr1);
    printf("*ptr2 = %d\n", *ptr2);
    printf("*(ptr2 + 2) = %d\n", *(ptr2 + 2));

    // Output s[3] and s[6] values
    printf("s[3] = %d (uninitialized, may be garbage)\n", s[3]);
    printf("s[6] = %d (uninitialized, may be garbage)\n", s[6]);

    // Set s[8] to 20 using ptr2
    *(ptr2 + 8) = 20;
    printf("s[8] = %d (after setting to 20)\n", s[8]);

    return 0;
}
