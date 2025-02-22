#include <limits.h>
#include <stdio.h>

#define STACK_SIZE 30000

typedef struct {
    int val_stack[STACK_SIZE];
    int count;
} MinStack;

MinStack *minStackCreate() {
    MinStack *val_stack = (MinStack *)calloc(1, sizeof(MinStack));
    if (val_stack == NULL) {
        return NULL;
    }

    return val_stack;
}

void minStackPush(MinStack *obj, int val) {
    obj->val_stack[obj->count] = val;
    obj->count++;
}

void minStackPop(MinStack *obj) {
    if (obj->count == 0) {
        return;
    }

    obj->count--;
}

int minStackTop(MinStack *obj) {
    return obj->val_stack[obj->count - 1];
}

int minStackGetMin(MinStack *obj) {
    int min = INT_MAX;
    for (int i = 0; i < obj->count; i++) {
        min = (min < obj->val_stack[i]) ? min : obj->val_stack[i];
    }

    return min;
}

void minStackFree(MinStack *obj) {
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 * minStackPop(obj);
 * int param_3 = minStackTop(obj);
 * int param_4 = minStackGetMin(obj);
 * minStackFree(obj);
 */

#define STACK_SIZE 30000

typedef struct {
    int val_stack[STACK_SIZE];
    int min_stack[STACK_SIZE];
    int count;
} MinStack;

MinStack *minStackCreate() {
    MinStack *val_stack = (MinStack *)calloc(1, sizeof(MinStack));
    if (val_stack == NULL) {
        return NULL;
    }

    return val_stack;
}

void minStackPush(MinStack *obj, int val) {
    obj->val_stack[obj->count] = val;
    if (obj->count == 0) {
        obj->min_stack[obj->count] = 0;
    } else if (val < obj->val_stack[obj->min_stack[obj->count - 1]]) {
        obj->min_stack[obj->count] = obj->count;
    } else {
        obj->min_stack[obj->count] = obj->min_stack[obj->count - 1];
    }
    obj->count++;
}

void minStackPop(MinStack *obj) {
    if (obj->count == 0) {
        return;
    }

    obj->count--;
}

int minStackTop(MinStack *obj) {
    return obj->val_stack[obj->count - 1];
}

int minStackGetMin(MinStack *obj) {
    return obj->val_stack[obj->min_stack[obj->count - 1]];
}

void minStackFree(MinStack *obj) {
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 * minStackPop(obj);
 * int param_3 = minStackTop(obj);
 * int param_4 = minStackGetMin(obj);
 * minStackFree(obj);
 */