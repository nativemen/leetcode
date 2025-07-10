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
    int left = (2 * idx) + 1;
    int right = (2 * idx) + 2;

    if (left < heap->size && heap->array[left] < heap->array[smallest]) {
        smallest = left;
    }

    if (right < heap->size && heap->array[right] < heap->array[smallest]) {
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

typedef struct {
    int num1;
    int num2;
} Nums;

static int compare(const void *a, const void *b) {
    const Nums *x = (const Nums *)a;
    const Nums *y = (const Nums *)b;

    return y->num2 - x->num2;
}

long long maxScore(int *nums1, int nums1Size, int *nums2, int nums2Size, int k) {
    Nums *nums = (Nums *)malloc(nums1Size * sizeof(Nums));
    if (nums == NULL) {
        return -1;
    }

    for (int i = 0; i < nums1Size; i++) {
        nums[i].num1 = nums1[i];
        nums[i].num2 = nums2[i];
    }

    qsort(nums, nums1Size, sizeof(Nums), compare);

    long long result = 0;
    long long sum = 0;
    MinHeap *heap = createMinHeap(k + 1);
    if (heap == NULL) {
        free(nums);
        return -1;
    }

    for (int i = 0; i < nums1Size; i++) {
        push(heap, nums[i].num1);
        sum += (long long)nums[i].num1;

        if (heap->size > k) {
            sum -= pop(heap);
        }

        if (heap->size == k) {
            long long value = sum * (long long)nums[i].num2;
            result = (result < value) ? value : result;
        }
    }

    free(heap);
    free(nums);

    return result;
}