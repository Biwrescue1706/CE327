// array_pointer_hw.c
#include <stdio.h>
#include <stdint.h>

int main(void) {
    int scores[5] = {-1, 789, -16, 1025, -1025};
    printf("scores[1] = %d = %#x\n", scores[1], scores[1]);
    printf("*scores = %d = %#x\n", *scores, *scores);
    printf("*(scores + 1) = %d = %#x\n", *(scores + 1), *(scores + 1));
    // Note: Accessing scores[5] is out of bounds; it should be scores[4]
    // printf("scores[5] = %d = %#x\n", scores[5], scores[5]); // Uncommenting this line will cause undefined behavior
    printf("*(scores + 4) = %d = %#x\n", *(scores + 4), *(scores + 4));
    printf("scores = %p\n", scores);
    printf("scores + 1 = %p\n", scores + 1);
    printf("scores + 4 = %p\n", scores + 4);
    printf("Address of scores[0] = %p\n", &scores[0]);
    printf("Address of scores[1] = %p\n", &scores[1]);
    printf("Address of scores[4] = %p\n", &scores[4]);

    // New scores array
    int32_t new_scores[3] = {93, 81, 97}; 
    printf("new_scores[0] = %d = %#x\n", new_scores[0], new_scores[0]);
    printf("new_scores[1] = %d = %#x\n", new_scores[1], new_scores[1]);
    printf("new_scores[2] = %d = %#x\n", new_scores[2], new_scores[2]);

    return 0;
}