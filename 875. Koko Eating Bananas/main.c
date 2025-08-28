#include <math.h>
#include <stdbool.h>
#include <stdio.h>

static int getEatingHours(int *piles, int pilesSize, int k) {
    int hours = 0;

    for (int i = 0; i < pilesSize; i++) {
        double x = (double)piles[i] / (double)k;
        hours += (int)ceil(x);
    }

    return hours;
}

static int compare(const void *a, const void *b) {
    return *(const int *)a - *(const int *)b;
}

int minEatingSpeed(int *piles, int pilesSize, int h) {
    qsort(piles, pilesSize, sizeof(int), compare);

    int left = 1;
    int right = piles[pilesSize - 1];

    while (left < right) {
        int mid = (left + right) / 2;
        int hours = getEatingHours(piles, pilesSize, mid);
        if (hours <= h) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return right;
}

static int getEatingHours(int *piles, int pilesSize, int k) {
    int hours = 0;

    for (int i = 0; i < pilesSize; i++) {
        double x = (double)piles[i] / (double)k;
        hours += (int)ceil(x);
    }

    return hours;
}

int minEatingSpeed(int *piles, int pilesSize, int h) {
    int maxPile = piles[0];

    for (int i = 0; i < pilesSize; i++) {
        if (piles[i] > maxPile) {
            maxPile = piles[i];
        }
    }

    int left = 1;
    int right = maxPile;

    while (left < right) {
        int mid = (left + right) / 2;
        int hours = getEatingHours(piles, pilesSize, mid);
        if (hours <= h) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return right;
}

static int getEatingHours(int *piles, int pilesSize, int k) {
    int hours = 0;

    for (int i = 0; i < pilesSize; i++) {
        double x = (double)piles[i] / (double)k;
        hours += (int)ceil(x);
    }

    return hours;
}

int minEatingSpeed(int *piles, int pilesSize, int h) {
    int maxPile = piles[0];

    for (int i = 0; i < pilesSize; i++) {
        if (piles[i] > maxPile) {
            maxPile = piles[i];
        }
    }

    int left = 1;
    int right = maxPile;

    while (left < right) {
        int mid = (left + right) / 2;
        int hours = getEatingHours(piles, pilesSize, mid);
        if (hours <= h) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return right;
}

static bool canEating(int *piles, int pilesSize, int h, int k) {
    int hours = 0;

    for (int i = 0; i < pilesSize; i++) {
        hours += (piles[i] + k - 1) / k;
    }

    return hours <= h;
}

int minEatingSpeed(int *piles, int pilesSize, int h) {
    int maxPile = piles[0];

    for (int i = 0; i < pilesSize; i++) {
        if (piles[i] > maxPile) {
            maxPile = piles[i];
        }
    }

    int left = 1;
    int right = maxPile;

    while (left < right) {
        int mid = (left + right) / 2;
        if (canEating(piles, pilesSize, h, mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return right;
}