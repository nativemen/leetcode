#include <stdbool.h>

typedef struct {
    int num;
    int index;
} Map;

static int compare(const void *a, const void *b) {
    const Map *map1 = (const Map *)a;
    const Map *map2 = (const Map *)b;
    return map1->num - map2->num;
}

bool containsNearbyDuplicate(int *nums, int numsSize, int k) {
    Map maps[numsSize];

    for (int i = 0; i < numsSize; i++) {
        maps[i].num = nums[i];
        maps[i].index = i;
    }

    qsort(maps, numsSize, sizeof(Map), compare);

    for (int i = 1; i < numsSize; i++) {
        if (maps[i].num == maps[i - 1].num && abs(maps[i].index - maps[i - 1].index) <= k) {
            return true;
        }
    }

    return false;
}



bool containsNearbyDuplicate(int *nums, int numsSize, int k) {
    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = i + 1; j < numsSize && j <= i + k; j++) {
            if (nums[i] == nums[j]) {
                return true;
            }
        }
    }

    return false;
}