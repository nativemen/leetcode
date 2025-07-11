#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct {
    int *array;
    int capacity;
    int size;
} MinHeap;

static MinHeap *createMinHeap(int capacity) {
    MinHeap *heap = (MinHeap *)malloc(sizeof(MinHeap));
    if (heap == NULL) {
        return NULL;
    }

    heap->array = (int *)malloc(capacity * sizeof(int));
    if (heap->array == NULL) {
        free(heap);
        return NULL;
    }

    heap->capacity = capacity;
    heap->size = 0;

    return heap;
}

static void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

static void heapifyDown(MinHeap *heap, int idx) {
    int smallest = idx;
    int left = (idx * 2) + 1;
    int right = (idx * 2) + 2;

    if (left < heap->size && heap->array[smallest] > heap->array[left]) {
        smallest = left;
    }

    if (right < heap->size && heap->array[smallest] > heap->array[right]) {
        smallest = right;
    }

    if (smallest != idx) {
        swap(&heap->array[idx], &heap->array[smallest]);
        heapifyDown(heap, smallest);
    }
}

static void heapifyUp(MinHeap *heap, int idx) {
    while (idx > 0 && heap->array[(idx - 1) / 2] > heap->array[idx]) {
        swap(&heap->array[idx], &heap->array[(idx - 1) / 2]);
        idx = (idx - 1) / 2;
    }
}

static bool push(MinHeap *heap, int value) {
    if (heap->size >= heap->capacity) {
        printf("Heap overflow!\n");
        return false;
    }

    heap->array[heap->size++] = value;
    heapifyUp(heap, heap->size - 1);

    return true;
}

static int top(MinHeap *heap) {
    if (heap->size <= 0) {
        printf("Heap is empty!\n");
        return INT_MIN;
    }

    return heap->array[0];
}

static int pop(MinHeap *heap) {
    if (heap->size <= 0) {
        printf("Heap is empty!\n");
        return INT_MIN;
    }

    if (heap->size == 1) {
        heap->size--;
        return heap->array[0];
    }

    int smallest = heap->array[0];

    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;
    heapifyDown(heap, 0);

    return smallest;
}

static bool isEmpty(const MinHeap *heap) {
    return heap->size == 0;
}

static void freeHeap(MinHeap *heap) {
    free(heap->array);
    free(heap);
}

long long totalCost(int *costs, int costsSize, int k, int candidates) {
    MinHeap *heap1 = createMinHeap(candidates);
    if (heap1 == NULL) {
        return -1;
    }

    MinHeap *heap2 = createMinHeap(candidates);
    if (heap2 == NULL) {
        freeHeap(heap1);
        return -1;
    }

    int left = 0;
    int right = costsSize - 1;

    while (left <= right && heap1->size < candidates) {
        push(heap1, costs[left++]);
    }

    while (left <= right && heap2->size < candidates) {
        push(heap2, costs[right--]);
    }

    long long total = 0;

    while (k-- > 0) {
        if (isEmpty(heap2) || (!isEmpty(heap1) && top(heap1) <= top(heap2))) {
            total += pop(heap1);
            if (left <= right) {
                push(heap1, costs[left++]);
            }
        } else if (isEmpty(heap1) || (!isEmpty(heap2) && top(heap1) > top(heap2))) {
            total += pop(heap2);
            if (left <= right) {
                push(heap2, costs[right--]);
            }
        }
    }

    freeHeap(heap2);
    freeHeap(heap1);

    return total;
}