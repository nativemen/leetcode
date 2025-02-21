#include <limits.h>
#include <stdio.h>

typedef struct {
    int *nums;
    int size;
} Solution;

Solution *solutionCreate(int *nums, int numsSize) {
    Solution *s = (Solution *)malloc(sizeof(Solution));
    if (s == NULL) {
        return NULL;
    }

    s->nums = (int *)malloc(numsSize * sizeof(int));
    if (s->nums == NULL) {
        free(s);
        return NULL;
    }
    s->size = numsSize;

    memcpy(s->nums, nums, numsSize * sizeof(int));

    return s;
}

int *solutionReset(Solution *obj, int *retSize) {
    int *res = (int *)malloc(obj->size * sizeof(int));
    for (int i = 0; i < obj->size; i++) {
        res[i] = obj->nums[i];
    }

    *retSize = obj->size;
    return res;
}

int *solutionShuffle(Solution *obj, int *retSize) {
    int *res = (int *)malloc(obj->size * sizeof(int));
    for (int i = 0; i < obj->size; i++) {
        res[i] = INT_MAX;
    }

    for (int i = 0; i < obj->size; i++) {
        int index = rand() % obj->size;
        while (res[index] != INT_MAX) {
            index = rand() % obj->size;
        }
        res[index] = obj->nums[i];
    }

    *retSize = obj->size;
    return res;
}

void solutionFree(Solution *obj) {
    if (obj == NULL) {
        return;
    }

    if (obj->nums != NULL) {
        free(obj->nums);
        obj->nums = NULL;
    }

    free(obj);
}

/**
 * Your Solution struct will be instantiated and called as such:
 * Solution* obj = solutionCreate(nums, numsSize);
 * int* param_1 = solutionReset(obj, retSize);
 * int* param_2 = solutionShuffle(obj, retSize);
 * solutionFree(obj);
 */

typedef struct {
    int *orig;
    int *shuffle;
    int size;
} Solution;

Solution *solutionCreate(int *nums, int numsSize) {
    Solution *s = (Solution *)malloc(sizeof(Solution));
    if (s == NULL) {
        return NULL;
    }

    s->orig = (int *)malloc(numsSize * sizeof(int));
    if (s->orig == NULL) {
        free(s);
        return NULL;
    }

    s->shuffle = (int *)malloc(numsSize * sizeof(int));
    if (s->shuffle == NULL) {
        free(s->orig);
        free(s);
        return NULL;
    }
    s->size = numsSize;

    memcpy(s->orig, nums, numsSize * sizeof(int));
    memset(s->shuffle, 0, numsSize * sizeof(int));

    return s;
}

int *solutionReset(Solution *obj, int *retSize) {
    *retSize = obj->size;
    return obj->orig;
}

int *solutionShuffle(Solution *obj, int *retSize) {
    for (int i = 0; i < obj->size; i++) {
        obj->shuffle[i] = INT_MAX;
    }

    for (int i = 0; i < obj->size; i++) {
        int index = rand() % obj->size;
        while (obj->shuffle[index] != INT_MAX) {
            index = rand() % obj->size;
        }
        obj->shuffle[index] = obj->orig[i];
    }

    *retSize = obj->size;
    return obj->shuffle;
}

void solutionFree(Solution *obj) {
    if (obj == NULL) {
        return;
    }

    if (obj->orig != NULL) {
        free(obj->orig);
    }

    if (obj->shuffle != NULL) {
        free(obj->shuffle);
    }

    free(obj);
}

/**
 * Your Solution struct will be instantiated and called as such:
 * Solution* obj = solutionCreate(nums, numsSize);
 * int* param_1 = solutionReset(obj, retSize);
 * int* param_2 = solutionShuffle(obj, retSize);
 * solutionFree(obj);
 */