#include <stdbool.h>
#include <stdio.h>

static inline bool isEmpty(int *flowerbed, int flowerbedSize, int pos) {
    return pos < 0 || pos >= flowerbedSize || flowerbed[pos] == 0;
}

bool canPlaceFlowers(int *flowerbed, int flowerbedSize, int n) {
    int count = 0;

    for (int i = 0; i < flowerbedSize; i++) {
        if (isEmpty(flowerbed, flowerbedSize, i - 1) && isEmpty(flowerbed, flowerbedSize, i) &&
            isEmpty(flowerbed, flowerbedSize, i + 1)) {
            count++;
            flowerbed[i] = 1;
        }
    }

    return count >= n;
}

bool canPlaceFlowers(int *flowerbed, int flowerbedSize, int n) {
    int count = 0;

    for (int i = 0; i < flowerbedSize; i++) {
        bool left = false;
        bool right = false;
        if (i - 1 < 0 || flowerbed[i - 1] == 0) {
            left = true;
        }

        if (i + 1 >= flowerbedSize || flowerbed[i + 1] == 0) {
            right = true;
        }

        if (left && right && flowerbed[i] == 0) {
            count++;
            flowerbed[i] = 1;
        }
    }

    return count >= n;
}

bool canPlaceFlowers(int *flowerbed, int flowerbedSize, int n) {
    int count = 0;

    for (int i = 0; i < flowerbedSize; i++) {
        bool left = (i - 1 < 0) || (flowerbed[i - 1] == 0);
        bool right = (i + 1 >= flowerbedSize) || (flowerbed[i + 1] == 0);

        if (left && right && flowerbed[i] == 0) {
            count++;
            flowerbed[i] = 1;
        }
    }

    return count >= n;
}