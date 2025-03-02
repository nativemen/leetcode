#include <stdbool.h>

#define ARRAY_SIZE 2001

int findKthPositive(int *arr, int arrSize, int k) {
    bool isMissing[ARRAY_SIZE];

    for (int i = 0; i < ARRAY_SIZE; i++) {
        isMissing[i] = true;
    }

    for (int i = 0; i < arrSize; i++) {
        isMissing[arr[i]] = false;
    }

    for (int i = 1; i < ARRAY_SIZE; i++) {
        if (!isMissing[i]) {
            continue;
        }

        k--;
        if (k == 0) {
            return i;
        }
    }

    return -1;
}

int findKthPositive(int *arr, int arrSize, int k) {
    int left = 0;
    int right = arrSize - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] - (mid + 1) < k) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return left + k;
}


int findKthPositive(int *arr, int arrSize, int k) {
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] <= k) {
            k++;
        }
    }

    return k;
}