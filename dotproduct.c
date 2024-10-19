#include <stdio.h>

// Function to calculate the dot product of two vectors
int dotproduct(int a[], int b[], int size) {
    int result = 0;
    for (int i = 0; i < size; i++) {
        result += a[i] * b[i];
    }
    return result;
}

int main() {
    int a[] = {1, 2, 4, 0};
    int b[] = {-2, 1, 2, 5};
    int size = sizeof(a) / sizeof(a[0]); // Size of the arrays

    // Calculate the dot product
    int result = dotproduct(a, b, size);

    // Print the result
    printf("The dot product of a and b is: %d\n", result);
    
    return 0;
}
