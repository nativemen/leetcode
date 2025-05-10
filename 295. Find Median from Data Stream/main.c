#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

static void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

typedef struct {
    int *arr;
    int capability;
    int size;
} MaxHeap;

static MaxHeap *createMaxHeap(int capability) {
    MaxHeap *maxHeap = (MaxHeap *)malloc(sizeof(MaxHeap));
    if (maxHeap == NULL) {
        return NULL;
    }

    maxHeap->arr = (int *)malloc(capability * sizeof(int));
    if (maxHeap->arr == NULL) {
        free(maxHeap);
        return NULL;
    }

    maxHeap->capability = capability;
    maxHeap->size = 0;

    return maxHeap;
}

static void maxHeapHeapifyDown(MaxHeap *maxHeap, int idx) {
    int largest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < maxHeap->size && maxHeap->arr[left] > maxHeap->arr[largest]) {
        largest = left;
    }

    if (right < maxHeap->size && maxHeap->arr[right] > maxHeap->arr[largest]) {
        largest = right;
    }

    if (largest != idx) {
        swap(&maxHeap->arr[largest], &maxHeap->arr[idx]);
        maxHeapHeapifyDown(maxHeap, largest);
    }
}

static void maxHeapHeapifyUp(MaxHeap *maxHeap, int idx) {
    while (idx > 0 && maxHeap->arr[(idx - 1) / 2] < maxHeap->arr[idx]) {
        swap(&maxHeap->arr[(idx - 1) / 2], &maxHeap->arr[idx]);
        idx = (idx - 1) / 2;
    }
}

static bool maxHeapPush(MaxHeap *maxHeap, int num) {
    if (maxHeap->size >= maxHeap->capability) {
        printf("MaxHeap is overflow!\n");
        return false;
    }

    maxHeap->arr[maxHeap->size++] = num;
    maxHeapHeapifyUp(maxHeap, maxHeap->size - 1);

    return true;
}

static int maxHeapTop(const MaxHeap *maxHeap) {
    if (maxHeap->size <= 0) {
        printf("MaxHeap is empty!\n");
        return INT_MIN;
    }

    return maxHeap->arr[0];
}

static int maxHeapPop(MaxHeap *maxHeap) {
    if (maxHeap->size <= 0) {
        printf("MaxHeap is empty!\n");
        return INT_MIN;
    }

    if (maxHeap->size == 1) {
        maxHeap->size--;
        return maxHeap->arr[0];
    }

    int root = maxHeap->arr[0];
    maxHeap->arr[0] = maxHeap->arr[maxHeap->size - 1];
    maxHeap->size--;
    maxHeapHeapifyDown(maxHeap, 0);

    return root;
}

static bool isMaxHeapEmpty(const MaxHeap *maxHeap) {
    return maxHeap->size == 0;
}

static void freeMaxHeap(MaxHeap *maxHeap) {
    free(maxHeap->arr);
    free(maxHeap);
}

typedef struct {
    int *arr;
    int capability;
    int size;
} MinHeap;

static MinHeap *createMinHeap(int capability) {
    MinHeap *minheap = (MinHeap *)malloc(sizeof(MinHeap));
    if (minheap == NULL) {
        return NULL;
    }

    minheap->arr = (int *)malloc(capability * sizeof(int));
    if (minheap->arr == NULL) {
        free(minheap);
        return NULL;
    }

    minheap->capability = capability;
    minheap->size = 0;

    return minheap;
}

static void minHeapHeapifyDown(MinHeap *minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->arr[left] < minHeap->arr[smallest]) {
        smallest = left;
    }

    if (right < minHeap->size && minHeap->arr[right] < minHeap->arr[smallest]) {
        smallest = right;
    }

    if (smallest != idx) {
        swap(&minHeap->arr[smallest], &minHeap->arr[idx]);
        minHeapHeapifyDown(minHeap, smallest);
    }
}

static void minHeapHeapifyUp(MinHeap *minHeap, int idx) {
    while (idx > 0 && minHeap->arr[(idx - 1) / 2] > minHeap->arr[idx]) {
        swap(&minHeap->arr[(idx - 1) / 2], &minHeap->arr[idx]);
        idx = (idx - 1) / 2;
    }
}

static bool minHeapPush(MinHeap *minHeap, int num) {
    if (minHeap->size >= minHeap->capability) {
        printf("MinHeap is overflow!\n");
        return false;
    }

    minHeap->arr[minHeap->size++] = num;
    minHeapHeapifyUp(minHeap, minHeap->size - 1);

    return true;
}

static int minHeapTop(const MinHeap *minHeap) {
    if (minHeap->size <= 0) {
        printf("MinHeap is empty!\n");
        return INT_MAX;
    }

    return minHeap->arr[0];
}

static int minHeapPop(MinHeap *minHeap) {
    if (minHeap->size <= 0) {
        printf("MinHeap is empty!\n");
        return INT_MAX;
    }

    if (minHeap->size == 1) {
        minHeap->size--;
        return minHeap->arr[0];
    }

    int root = minHeap->arr[0];
    minHeap->arr[0] = minHeap->arr[minHeap->size - 1];
    minHeap->size--;
    minHeapHeapifyDown(minHeap, 0);

    return root;
}

static bool isMinHeapEmpty(const MinHeap *minHeap) {
    return minHeap->size == 0;
}

static void freeMinHeap(MinHeap *minHeap) {
    free(minHeap->arr);
    free(minHeap);
}

typedef struct {
    MaxHeap *maxHeap;
    MinHeap *minHeap;
} MedianFinder;

#define HEAP_CAPABILITY 25000

MedianFinder *medianFinderCreate() {
    MedianFinder *mf = (MedianFinder *)malloc(sizeof(MedianFinder));
    if (mf == NULL) {
        return NULL;
    }

    mf->maxHeap = createMaxHeap(HEAP_CAPABILITY);
    if (mf->maxHeap == NULL) {
        free(mf);
        return NULL;
    }

    mf->minHeap = createMinHeap(HEAP_CAPABILITY);
    if (mf->minHeap == NULL) {
        free(mf->maxHeap);
        free(mf);
        return NULL;
    }

    return mf;
}

void medianFinderAddNum(MedianFinder *obj, int num) {
    if (obj->maxHeap->size >= obj->maxHeap->capability && obj->minHeap->size >= obj->minHeap->capability) {
        printf("Heap overflow!\n");
        return;
    }

    if (isMaxHeapEmpty(obj->maxHeap) || num <= maxHeapTop(obj->maxHeap)) {
        maxHeapPush(obj->maxHeap, num);
    } else {
        minHeapPush(obj->minHeap, num);
    }

    while (obj->maxHeap->size > obj->minHeap->size + 1) {
        minHeapPush(obj->minHeap, maxHeapPop(obj->maxHeap));
    }

    while (obj->maxHeap->size < obj->minHeap->size) {
        maxHeapPush(obj->maxHeap, minHeapPop(obj->minHeap));
    }
}

double medianFinderFindMedian(MedianFinder *obj) {
    if (isMaxHeapEmpty(obj->maxHeap)) {
        return 0.0;
    }

    if (obj->maxHeap->size == obj->minHeap->size) {
        return ((double)maxHeapTop(obj->maxHeap) + (double)minHeapTop(obj->minHeap)) / 2.0;
    } else {
        return (double)maxHeapTop(obj->maxHeap);
    }
}

void medianFinderFree(MedianFinder *obj) {
    freeMaxHeap(obj->maxHeap);
    freeMinHeap(obj->minHeap);
    free(obj);
}

/**
 * Your MedianFinder struct will be instantiated and called as such:
 * MedianFinder* obj = medianFinderCreate();
 * medianFinderAddNum(obj, num);
 * double param_2 = medianFinderFindMedian(obj);
 * medianFinderFree(obj);
 */

typedef struct {
    int *arr;
    int capability;
    int size;
} Heap;

static void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

static Heap *createHeap(int capability) {
    Heap *heap = (Heap *)malloc(sizeof(Heap));
    if (heap == NULL) {
        return NULL;
    }

    heap->arr = (int *)malloc(capability * sizeof(int));
    if (heap->arr == NULL) {
        free(heap);
        return NULL;
    }

    heap->capability = capability;
    heap->size = 0;

    return heap;
}

static bool compare(int a, int b, bool isMaxHeap) {
    return isMaxHeap ? (a > b) : (a < b);
}

static void heapifyDown(Heap *heap, int idx, bool isMaxHeap) {
    int most = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < heap->size && compare(heap->arr[left], heap->arr[most], isMaxHeap)) {
        most = left;
    }

    if (right < heap->size && compare(heap->arr[right], heap->arr[most], isMaxHeap)) {
        most = right;
    }

    if (most != idx) {
        swap(&heap->arr[most], &heap->arr[idx]);
        heapifyDown(heap, most, isMaxHeap);
    }
}

static void heapifyUp(Heap *heap, int idx, bool isMaxHeap) {
    while (idx > 0 && compare(heap->arr[idx], heap->arr[(idx - 1) / 2], isMaxHeap)) {
        swap(&heap->arr[(idx - 1) / 2], &heap->arr[idx]);
        idx = (idx - 1) / 2;
    }
}

static bool push(Heap *heap, int num, bool isMaxHeap) {
    if (heap->size >= heap->capability) {
        printf("MaxHeap is overflow!\n");
        return false;
    }

    heap->arr[heap->size++] = num;
    heapifyUp(heap, heap->size - 1, isMaxHeap);

    return true;
}

static int top(const Heap *heap, bool isMaxHeap) {
    if (heap->size <= 0) {
        printf("Heap is empty!\n");
        return isMaxHeap ? INT_MIN : INT_MAX;
    }

    return heap->arr[0];
}

static int pop(Heap *heap, bool isMaxHeap) {
    if (heap->size <= 0) {
        printf("MaxHeap is empty!\n");
        return isMaxHeap ? INT_MIN : INT_MAX;
    }

    if (heap->size == 1) {
        heap->size--;
        return heap->arr[0];
    }

    int root = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;
    heapifyDown(heap, 0, isMaxHeap);

    return root;
}

static bool isEmpty(const Heap *heap) {
    return heap->size == 0;
}

static void freeHeap(Heap *heap) {
    free(heap->arr);
    free(heap);
}

typedef struct {
    Heap *maxHeap;
    Heap *minHeap;
} MedianFinder;

#define HEAP_CAPABILITY 25000

MedianFinder *medianFinderCreate() {
    MedianFinder *mf = (MedianFinder *)malloc(sizeof(MedianFinder));
    if (mf == NULL) {
        return NULL;
    }

    mf->maxHeap = createHeap(HEAP_CAPABILITY);
    if (mf->maxHeap == NULL) {
        free(mf);
        return NULL;
    }

    mf->minHeap = createHeap(HEAP_CAPABILITY);
    if (mf->minHeap == NULL) {
        free(mf->maxHeap);
        free(mf);
        return NULL;
    }

    return mf;
}

void medianFinderAddNum(MedianFinder *obj, int num) {
    if (obj->maxHeap->size >= obj->maxHeap->capability && obj->minHeap->size >= obj->minHeap->capability) {
        printf("Heap overflow!\n");
        return;
    }

    if (isEmpty(obj->maxHeap) || num <= top(obj->maxHeap, true)) {
        push(obj->maxHeap, num, true);
    } else {
        push(obj->minHeap, num, false);
    }

    while (obj->maxHeap->size > obj->minHeap->size + 1) {
        push(obj->minHeap, pop(obj->maxHeap, true), false);
    }

    while (obj->maxHeap->size < obj->minHeap->size) {
        push(obj->maxHeap, pop(obj->minHeap, false), true);
    }
}

double medianFinderFindMedian(MedianFinder *obj) {
    if (isEmpty(obj->maxHeap)) {
        return 0.0;
    }

    if (obj->maxHeap->size == obj->minHeap->size) {
        return ((double)top(obj->maxHeap, true) + (double)top(obj->minHeap, false)) / 2.0;
    } else {
        return (double)top(obj->maxHeap, true);
    }
}

void medianFinderFree(MedianFinder *obj) {
    freeHeap(obj->maxHeap);
    freeHeap(obj->minHeap);
    free(obj);
}

/**
 * Your MedianFinder struct will be instantiated and called as such:
 * MedianFinder* obj = medianFinderCreate();
 * medianFinderAddNum(obj, num);
 * double param_2 = medianFinderFindMedian(obj);
 * medianFinderFree(obj);
 */