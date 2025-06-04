#include <stdbool.h>
#include <stdio.h>

#define ARRAY_SIZE 2001
#define FREQ_SIZE 1001
#define INDEX_SHIFT 1000

bool uniqueOccurrences(int *arr, int arrSize) {
    int count[ARRAY_SIZE] = {0};
    int freq[FREQ_SIZE] = {0};

    for (int i = 0; i < arrSize; i++) {
        count[arr[i] + INDEX_SHIFT]++;
    }

    for (int i = 1; i < ARRAY_SIZE; i++) {
        if (count[i] > 0) {
            freq[count[i]]++;
        }

        if (freq[count[i]] > 1) {
            return false;
        }
    }

    return true;
}