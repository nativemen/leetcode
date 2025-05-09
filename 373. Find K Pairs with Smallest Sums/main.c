#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define ARRAY_SIZE 2

typedef struct {
    int sum;
    int num1;
    int num2;
} Data;

typedef struct {
    Data *arr;
    int capacity;
    int size;
} MaxHeap;

static MaxHeap *createMaxHeap(int capacity) {
    MaxHeap *heap = (MaxHeap *)malloc(sizeof(MaxHeap));
    heap->arr = (Data *)malloc(capacity * sizeof(Data));
    heap->capacity = capacity;
    heap->size = 0;
    return heap;
}

static void swap(Data *a, Data *b) {
    Data temp = *a;
    *a = *b;
    *b = temp;
}

static void heapifyDown(MaxHeap *heap, int idx) {
    int largest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < heap->size && heap->arr[left].sum > heap->arr[largest].sum)
        largest = left;

    if (right < heap->size && heap->arr[right].sum > heap->arr[largest].sum)
        largest = right;

    if (largest != idx) {
        swap(&heap->arr[idx], &heap->arr[largest]);
        heapifyDown(heap, largest);
    }
}

static void heapifyUp(MaxHeap *heap, int idx) {
    while (idx > 0 && heap->arr[(idx - 1) / 2].sum < heap->arr[idx].sum) {
        swap(&heap->arr[idx], &heap->arr[(idx - 1) / 2]);
        idx = (idx - 1) / 2;
    }
}

static bool push(MaxHeap *heap, int sum, int num1, int num2) {
    if (heap->size >= heap->capacity) {
        printf("Heap overflow\n");
        return false;
    }

    heap->arr[heap->size].sum = sum;
    heap->arr[heap->size].num1 = num1;
    heap->arr[heap->size].num2 = num2;
    heap->size++;
    heapifyUp(heap, heap->size - 1);
    return true;
}

static Data top(MaxHeap *heap) {
    if (heap->size <= 0) {
        printf("Heap is empty\n");
        Data empty = {INT_MIN, 0, 0};
        return empty;
    }
    return heap->arr[0];
}
static Data pop(MaxHeap *heap) {
    if (heap->size <= 0) {
        printf("Heap underflow\n");
        Data empty = {INT_MIN, 0, 0};
        return empty;
    }

    if (heap->size == 1) {
        heap->size--;
        return heap->arr[0];
    }

    Data root = heap->arr[0];
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

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **kSmallestPairs(
        int *nums1, int nums1Size, int *nums2, int nums2Size, int k, int *returnSize, int **returnColumnSizes) {
    *returnSize = 0;
    int **result = (int **)calloc(k, sizeof(int *));
    *returnColumnSizes = (int *)calloc(k, sizeof(int));
    for (int i = 0; i < k; i++) {
        result[i] = (int *)malloc(ARRAY_SIZE * sizeof(int));
        (*returnColumnSizes)[i] = ARRAY_SIZE;
    }
    *returnSize = k;

    MaxHeap *maxHeap = createMaxHeap(2 * k);
    for (int i = 0; i < nums1Size; i++) {
        for (int j = 0; j < nums2Size; j++) {
            int sum = nums1[i] + nums2[j];

            if (maxHeap->size >= k) {
                if (top(maxHeap).sum > sum) {
                    pop(maxHeap);
                } else {
                    break;
                }
            }
            push(maxHeap, sum, nums1[i], nums2[j]);
        }
    }

    int count = 0;
    while (!isEmpty(maxHeap) && count < k) {
        Data data = pop(maxHeap);
        result[count][0] = data.num1;
        result[count][1] = data.num2;
        count++;
    }

    return result;
}

#define ARRAY_SIZE 2

typedef struct {
    int sum;
    int index1;
    int index2;
} Data;

typedef struct {
    Data *arr;
    int capacity;
    int size;
} MaxHeap;

static MaxHeap *createMaxHeap(int capacity) {
    MaxHeap *heap = (MaxHeap *)malloc(sizeof(MaxHeap));
    heap->arr = (Data *)malloc(capacity * sizeof(Data));
    heap->capacity = capacity;
    heap->size = 0;
    return heap;
}

static void swap(Data *a, Data *b) {
    Data temp = *a;
    *a = *b;
    *b = temp;
}

static void heapifyDown(MaxHeap *heap, int idx) {
    int largest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < heap->size && heap->arr[left].sum > heap->arr[largest].sum)
        largest = left;

    if (right < heap->size && heap->arr[right].sum > heap->arr[largest].sum)
        largest = right;

    if (largest != idx) {
        swap(&heap->arr[idx], &heap->arr[largest]);
        heapifyDown(heap, largest);
    }
}

static void heapifyUp(MaxHeap *heap, int idx) {
    while (idx > 0 && heap->arr[(idx - 1) / 2].sum < heap->arr[idx].sum) {
        swap(&heap->arr[idx], &heap->arr[(idx - 1) / 2]);
        idx = (idx - 1) / 2;
    }
}

static bool push(MaxHeap *heap, int sum, int i, int j) {
    if (heap->size >= heap->capacity) {
        printf("Heap overflow\n");
        return false;
    }

    heap->arr[heap->size].sum = sum;
    heap->arr[heap->size].index1 = i;
    heap->arr[heap->size].index2 = j;
    heap->size++;
    heapifyUp(heap, heap->size - 1);
    return true;
}

static Data top(MaxHeap *heap) {
    if (heap->size <= 0) {
        printf("Heap is empty\n");
        Data empty = {INT_MIN, 0, 0};
        return empty;
    }
    return heap->arr[0];
}
static Data pop(MaxHeap *heap) {
    if (heap->size <= 0) {
        printf("Heap underflow\n");
        Data empty = {INT_MIN, 0, 0};
        return empty;
    }

    if (heap->size == 1) {
        heap->size--;
        return heap->arr[0];
    }

    Data root = heap->arr[0];
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

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **kSmallestPairs(
        int *nums1, int nums1Size, int *nums2, int nums2Size, int k, int *returnSize, int **returnColumnSizes) {
    *returnSize = 0;
    int **result = (int **)calloc(k, sizeof(int *));
    *returnColumnSizes = (int *)calloc(k, sizeof(int));
    for (int i = 0; i < k; i++) {
        result[i] = (int *)malloc(ARRAY_SIZE * sizeof(int));
        (*returnColumnSizes)[i] = ARRAY_SIZE;
    }
    *returnSize = k;

    MaxHeap *maxHeap = createMaxHeap(2 * k);
    for (int i = 0; i < nums1Size; i++) {
        push(maxHeap, -nums1[i] - nums2[0], i, 0);
    }

    int count = 0;
    while (count < k && !isEmpty(maxHeap)) {
        Data data = pop(maxHeap);
        result[count][0] = nums1[data.index1];
        result[count][1] = nums2[data.index2];
        count++;

        if (data.index2 + 1 < nums2Size) {
            push(maxHeap, -nums1[data.index1] - nums2[data.index2 + 1], data.index1, data.index2 + 1);
        }
    }

    return result;
}

#define ARRAY_SIZE 2

typedef struct {
    int sum;
    int index1;
    int index2;
} Data;

typedef struct {
    Data *arr;
    int capacity;
    int size;
} MinHeap;

static MinHeap *createMinHeap(int capacity) {
    MinHeap *heap = (MinHeap *)malloc(sizeof(MinHeap));
    heap->arr = (Data *)malloc(capacity * sizeof(Data));
    heap->capacity = capacity;
    heap->size = 0;
    return heap;
}

static void swap(Data *a, Data *b) {
    Data temp = *a;
    *a = *b;
    *b = temp;
}

static void heapifyDown(MinHeap *heap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < heap->size && heap->arr[left].sum < heap->arr[smallest].sum)
        smallest = left;

    if (right < heap->size && heap->arr[right].sum < heap->arr[smallest].sum)
        smallest = right;

    if (smallest != idx) {
        swap(&heap->arr[idx], &heap->arr[smallest]);
        heapifyDown(heap, smallest);
    }
}

static void heapifyUp(MinHeap *heap, int idx) {
    while (idx > 0 && heap->arr[(idx - 1) / 2].sum > heap->arr[idx].sum) {
        swap(&heap->arr[idx], &heap->arr[(idx - 1) / 2]);
        idx = (idx - 1) / 2;
    }
}

static bool push(MinHeap *heap, int sum, int i, int j) {
    if (heap->size >= heap->capacity) {
        printf("Heap overflow\n");
        return false;
    }

    heap->arr[heap->size].sum = sum;
    heap->arr[heap->size].index1 = i;
    heap->arr[heap->size].index2 = j;
    heap->size++;
    heapifyUp(heap, heap->size - 1);
    return true;
}

static Data top(MinHeap *heap) {
    if (heap->size <= 0) {
        printf("Heap is empty\n");
        Data empty = {INT_MAX, 0, 0};
        return empty;
    }
    return heap->arr[0];
}

static Data pop(MinHeap *heap) {
    if (heap->size <= 0) {
        printf("Heap underflow\n");
        Data empty = {INT_MAX, 0, 0};
        return empty;
    }

    if (heap->size == 1) {
        heap->size--;
        return heap->arr[0];
    }

    Data root = heap->arr[0];
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

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **kSmallestPairs(
        int *nums1, int nums1Size, int *nums2, int nums2Size, int k, int *returnSize, int **returnColumnSizes) {
    *returnSize = 0;
    int **result = (int **)calloc(k, sizeof(int *));
    *returnColumnSizes = (int *)calloc(k, sizeof(int));
    for (int i = 0; i < k; i++) {
        result[i] = (int *)malloc(ARRAY_SIZE * sizeof(int));
        (*returnColumnSizes)[i] = ARRAY_SIZE;
    }
    *returnSize = k;

    MinHeap *minHeap = createMinHeap(2 * k);
    for (int i = 0; i < nums1Size; i++) {
        push(minHeap, nums1[i] + nums2[0], i, 0);
    }

    int count = 0;
    while (count < k && !isEmpty(minHeap)) {
        Data data = pop(minHeap);
        result[count][0] = nums1[data.index1];
        result[count][1] = nums2[data.index2];
        count++;

        if (data.index2 + 1 < nums2Size) {
            push(minHeap, nums1[data.index1] + nums2[data.index2 + 1], data.index1, data.index2 + 1);
        }
    }

    return result;
}

#define ARRAY_SIZE 2

typedef struct {
    int sum;
    int index1;
    int index2;
} Data;

typedef struct {
    Data *arr;
    int capacity;
    int size;
} MinHeap;

static MinHeap *createMinHeap(int capacity) {
    MinHeap *heap = (MinHeap *)malloc(sizeof(MinHeap));
    heap->arr = (Data *)malloc(capacity * sizeof(Data));
    heap->capacity = capacity;
    heap->size = 0;
    return heap;
}

static void swap(Data *a, Data *b) {
    Data temp = *a;
    *a = *b;
    *b = temp;
}

static void heapifyDown(MinHeap *heap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < heap->size && heap->arr[left].sum < heap->arr[smallest].sum)
        smallest = left;

    if (right < heap->size && heap->arr[right].sum < heap->arr[smallest].sum)
        smallest = right;

    if (smallest != idx) {
        swap(&heap->arr[idx], &heap->arr[smallest]);
        heapifyDown(heap, smallest);
    }
}

static void heapifyUp(MinHeap *heap, int idx) {
    while (idx > 0 && heap->arr[(idx - 1) / 2].sum > heap->arr[idx].sum) {
        swap(&heap->arr[idx], &heap->arr[(idx - 1) / 2]);
        idx = (idx - 1) / 2;
    }
}

static bool push(MinHeap *heap, int sum, int i, int j) {
    if (heap->size >= heap->capacity) {
        printf("Heap overflow\n");
        return false;
    }

    heap->arr[heap->size].sum = sum;
    heap->arr[heap->size].index1 = i;
    heap->arr[heap->size].index2 = j;
    heap->size++;
    heapifyUp(heap, heap->size - 1);
    return true;
}

static Data top(MinHeap *heap) {
    if (heap->size <= 0) {
        printf("Heap is empty\n");
        Data empty = {INT_MAX, 0, 0};
        return empty;
    }
    return heap->arr[0];
}

static Data pop(MinHeap *heap) {
    if (heap->size <= 0) {
        printf("Heap underflow\n");
        Data empty = {INT_MAX, 0, 0};
        return empty;
    }

    if (heap->size == 1) {
        heap->size--;
        return heap->arr[0];
    }

    Data root = heap->arr[0];
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

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **kSmallestPairs(
        int *nums1, int nums1Size, int *nums2, int nums2Size, int k, int *returnSize, int **returnColumnSizes) {
    *returnSize = 0;
    int **result = (int **)calloc(k, sizeof(int *));
    *returnColumnSizes = (int *)calloc(k, sizeof(int));
    for (int i = 0; i < k; i++) {
        result[i] = (int *)malloc(ARRAY_SIZE * sizeof(int));
        (*returnColumnSizes)[i] = ARRAY_SIZE;
    }
    *returnSize = k;

    MinHeap *minHeap = createMinHeap(k);
    push(minHeap, nums1[0] + nums2[0], 0, 0);

    int count = 0;

    while (!isEmpty(minHeap) && count < k) {
        Data data = pop(minHeap);
        result[count][0] = nums1[data.index1];
        result[count][1] = nums2[data.index2];
        count++;

        if (data.index2 == 0 && data.index1 + 1 < nums1Size) {
            push(minHeap, nums1[data.index1 + 1] + nums2[data.index2], data.index1 + 1, data.index2);
        }

        if (data.index2 + 1 < nums2Size) {
            push(minHeap, nums1[data.index1] + nums2[data.index2 + 1], data.index1, data.index2 + 1);
        }
    }

    return result;
}