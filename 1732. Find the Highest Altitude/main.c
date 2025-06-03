#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

int largestAltitude(int *gain, int gainSize) {
    int altitude = 0;
    int largest = 0;

    for (int i = 0; i < gainSize; i++) {
        altitude += gain[i];

        if (largest < altitude) {
            largest = altitude;
        }
    }

    return largest;
}