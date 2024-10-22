// find_min_max.c
#include <stdio.h>
#include <limits.h>

int main() {
   int input[] = {89, 5, 91, INT_MIN+1, 10, 98, INT_MAX-100,};
   int n = sizeof(input) / sizeof(input[0]);

   // Initialization of min and max
   int min_value = INT_MAX;
   int max_value = INT_MIN;
   
   // loop iteration for min and max value
   for (int i = 0; i < n; ++i) {
       if (input[i] < min_value) {
           min_value = input[i];
       }
       if (input[i] > max_value) {
           max_value = input[i];
       }
       printf("Step %d: min=%d, max=%d\n", i, min_value, max_value);
   }
   // Display the result
   printf("Minimum value: %d\n", min_value);
   printf("Maximum value: %d\n", max_value);

   return 0;
}