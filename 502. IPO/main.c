#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct {
    int capital;
    int profit;
} Ipo;

static int compare(const void *a, const void *b) {
    return ((Ipo *)a)->capital - ((Ipo *)b)->capital;
}

typedef struct {
    int *arr;
    int capacity;
    int size;
} MaxHeap;

static MaxHeap *createMaxHeap(int capacity) {
    MaxHeap *heap = (MaxHeap *)malloc(sizeof(MaxHeap));
    heap->arr = (int *)malloc(capacity * sizeof(int));
    heap->capacity = capacity;
    heap->size = 0;
    return heap;
}

static void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

static void heapifyDown(MaxHeap *heap, int idx) {
    int largest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < heap->size && heap->arr[left] > heap->arr[largest])
        largest = left;

    if (right < heap->size && heap->arr[right] > heap->arr[largest])
        largest = right;

    if (largest != idx) {
        swap(&heap->arr[idx], &heap->arr[largest]);
        heapifyDown(heap, largest);
    }
}

static void heapifyUp(MaxHeap *heap, int idx) {
    while (idx > 0 && heap->arr[(idx - 1) / 2] < heap->arr[idx]) {
        swap(&heap->arr[idx], &heap->arr[(idx - 1) / 2]);
        idx = (idx - 1) / 2;
    }
}

static bool push(MaxHeap *heap, int value) {
    if (heap->size >= heap->capacity) {
        printf("Heap overflow\n");
        return false;
    }

    heap->arr[heap->size] = value;
    heap->size++;
    heapifyUp(heap, heap->size - 1);
    return true;
}

static int top(MaxHeap *heap) {
    if (heap->size <= 0) {
        printf("Heap is empty\n");
        return INT_MIN;
    }
    return heap->arr[0];
}

static int pop(MaxHeap *heap) {
    if (heap->size <= 0) {
        printf("Heap underflow\n");
        return INT_MIN;
    }

    if (heap->size == 1) {
        heap->size--;
        return heap->arr[0];
    }

    int root = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;
    heapifyDown(heap, 0);

    return root;
}

static bool isEmpty(MaxHeap *heap) {
    return heap->size == 0;
}

static void freeHeap(MaxHeap *heap) {
    free(heap->arr);
    free(heap);
}

int findMaximizedCapital(int k, int w, int *profits, int profitsSize, int *capital, int capitalSize) {
    if (k <= 0 || profits == NULL || profitsSize <= 0 || capital == NULL || capitalSize <= 0) {
        return w;
    }

    Ipo ipo[capitalSize];

    for (int i = 0; i < capitalSize; i++) {
        ipo[i].capital = capital[i];
        ipo[i].profit = profits[i];
    }

    qsort(ipo, capitalSize, sizeof(Ipo), compare);

    MaxHeap *maxHeap = createMaxHeap(capitalSize);
    int i = 0;

    while (k-- > 0) {
        while (i < capitalSize && ipo[i].capital <= w) {
            push(maxHeap, ipo[i].profit);
            i++;
        }

        if (isEmpty(maxHeap)) {
            break;
        }

        w += pop(maxHeap);
    }

    freeHeap(maxHeap);

    return w;
}