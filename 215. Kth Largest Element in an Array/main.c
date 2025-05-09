#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

static int compare(const void *a, const void *b) {
    return *(const int *)a - *(const int *)b;
}

int findKthLargest(int *nums, int numsSize, int k) {
    qsort(nums, numsSize, sizeof(int), compare);

    return nums[numsSize - k];
}

#define ARRAY_SIZE 20001
#define INDEX_OFFSET 10000

int findKthLargest(int *nums, int numsSize, int k) {
    int count[ARRAY_SIZE];
    memset(count, 0, ARRAY_SIZE * sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        count[nums[i] + INDEX_OFFSET]++;
    }

    for (int i = ARRAY_SIZE - 1; i >= 0; i--) {
        if (k <= count[i]) {
            return i - INDEX_OFFSET;
        }

        k -= count[i];
    }

    return 0 - INDEX_OFFSET;
}

static int quickSelect(int *nums, int numsSize, int k) {
    int pivot = nums[rand() % numsSize];
    int left[numsSize];
    int right[numsSize];
    int mid[numsSize];
    int l = 0;
    int r = 0;
    int m = 0;
    int i = 0;

    while (i < numsSize) {
        if (nums[i] < pivot) {
            left[l++] = nums[i++];
        } else if (nums[i] > pivot) {
            right[r++] = nums[i++];
        } else {
            mid[m++] = nums[i++];
        }
    }

    if (r >= k) {
        return quickSelect(right, r, k);
    } else if ((r + m) < k) {
        return quickSelect(left, l, k - r - m);
    } else {
        return pivot;
    }
}

int findKthLargest(int *nums, int numsSize, int k) {
    if (nums == NULL || numsSize <= 0 || k < 0 || k > numsSize) {
        return -1;
    }

    return quickSelect(nums, numsSize, k);
}

typedef struct {
    int *arr;
    int capacity;
    int size;
} MinHeap;

static MinHeap *createMinHeap(int capacity) {
    MinHeap *heap = (MinHeap *)malloc(sizeof(MinHeap));
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

static void heapifyDown(MinHeap *heap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < heap->size && heap->arr[left] < heap->arr[smallest])
        smallest = left;

    if (right < heap->size && heap->arr[right] < heap->arr[smallest])
        smallest = right;

    if (smallest != idx) {
        swap(&heap->arr[idx], &heap->arr[smallest]);
        heapifyDown(heap, smallest);
    }
}

static void heapifyUp(MinHeap *heap, int idx) {
    while (idx > 0 && heap->arr[(idx - 1) / 2] > heap->arr[idx]) {
        swap(&heap->arr[idx], &heap->arr[(idx - 1) / 2]);
        idx = (idx - 1) / 2;
    }
}

static bool push(MinHeap *heap, int value) {
    if (heap->size >= heap->capacity) {
        printf("Heap overflow\n");
        return false;
    }

    heap->arr[heap->size] = value;
    heap->size++;
    heapifyUp(heap, heap->size - 1);
    return true;
}

static int top(MinHeap *heap) {
    if (heap->size <= 0) {
        printf("Heap is empty\n");
        return INT_MIN;
    }
    return heap->arr[0];
}

static int pop(MinHeap *heap) {
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

static bool isEmpty(MinHeap *heap) {
    return heap->size == 0;
}

static void freeHeap(MinHeap *heap) {
    free(heap->arr);
    free(heap);
}

int findKthLargest(int *nums, int numsSize, int k) {
    MinHeap *minHeap = createMinHeap(k);

    for (int i = 0; i < k; i++) {
        push(minHeap, nums[i]);
    }

    for (int i = k; i < numsSize; i++) {
        if (nums[i] > top(minHeap)) {
            pop(minHeap);
            push(minHeap, nums[i]);
        }
    }

    return top(minHeap);
}