#include <stdio.h>

#define MAX_LAYER_NUM 2000

static int fillArray(int **array, struct TreeNode *root, int **returnColumnSizes, int layer) {
    if (root == NULL) {
        return layer;
    }

    array[layer][(*returnColumnSizes)[layer]] = root->val;
    (*returnColumnSizes)[layer]++;
    int left = fillArray(array, root->left, returnColumnSizes, layer + 1);
    int right = fillArray(array, root->right, returnColumnSizes, layer + 1);

    return (left > right) ? left : right;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **levelOrder(struct TreeNode *root, int *returnSize, int **returnColumnSizes) {
    if (root == NULL) {
        goto exit1;
    }

    int **array = (int **)calloc(MAX_LAYER_NUM, sizeof(int *));
    if (array == NULL) {
        goto exit1;
    }

    *returnColumnSizes = (int *)calloc(MAX_LAYER_NUM, sizeof(int));
    if (returnColumnSizes == NULL) {
        goto exit2;
    }

    size_t count = 1;
    for (size_t i = 0; i < MAX_LAYER_NUM; i++) {
        array[i] = (int *)calloc(count, sizeof(int));
        if (array[i] == NULL) {
            goto exit3;
        }

        (*returnColumnSizes)[i] = 0;
        count <<= 1;
        if (count > MAX_LAYER_NUM - i) {
            count = MAX_LAYER_NUM - i;
        }
    }

    *returnSize = fillArray(array, root, returnColumnSizes, 0);

    return array;

exit3:
    for (size_t i = 0; i < MAX_LAYER_NUM; i++) {
        if (array[i] != NULL) {
            free(array[i]);
            array[i] = NULL;
        }
    }

    free(*returnColumnSizes);
exit2:
    free(array);
exit1:
    *returnSize = 0;
    *returnColumnSizes = NULL;
    return NULL;
}

#define QUEUE_SIZE 1001

typedef struct _Queue {
    struct TreeNode *queue[QUEUE_SIZE];
    size_t front;
    int count;
} Queue;

static void init_queue(Queue *q) {
    if (q == NULL) {
        return;
    }

    for (size_t i = 0; i < QUEUE_SIZE; i++) {
        q->queue[i] = NULL;
    }
    q->front = 0;
    q->count = 0;
}

static struct TreeNode *pop_queue(Queue *q) {
    if (q->count == 0) {
        return NULL;
    }

    int index = q->front;
    q->front = (q->front + 1) % QUEUE_SIZE;
    q->count--;
    return q->queue[index];
}

static void push_queue(Queue *q, struct TreeNode *node) {
    if (node == NULL) {
        return;
    }

    q->queue[(q->front + q->count) % QUEUE_SIZE] = node;
    q->count++;
}

static inline size_t max(size_t a, size_t b) {
    return (a > b) ? a : b;
}

static size_t find_tree_depth(struct TreeNode *root) {
    if (root == NULL) {
        return 0;
    }

    return 1 + max(find_tree_depth(root->left), find_tree_depth(root->right));
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **levelOrder(struct TreeNode *root, int *returnSize, int **returnColumnSizes) {
    if (root == NULL) {
        goto exit1;
    }

    size_t depth = find_tree_depth(root);
    int **array = (int **)calloc(depth, sizeof(int *));
    if (array == NULL) {
        goto exit1;
    }

    *returnColumnSizes = (int *)calloc(depth, sizeof(int));
    if (returnColumnSizes == NULL) {
        goto exit2;
    }

    Queue *q = (Queue *)malloc(sizeof(Queue));
    if (q == NULL) {
        goto exit3;
    }

    init_queue(q);
    push_queue(q, root);

    size_t layer = 0;
    while (q->count > 0) {
        array[layer] = (int *)calloc(q->count, sizeof(int));
        if (array[layer] == NULL) {
            goto exit4;
        }

        (*returnColumnSizes)[layer] = q->count;
        size_t cur_layer_count = q->count;
        for (size_t i = 0; i < cur_layer_count; i++) {
            struct TreeNode *node = pop_queue(q);
            array[layer][i] = node->val;
            push_queue(q, node->left);
            push_queue(q, node->right);
        }
        layer++;
    }

    *returnSize = depth;
    return array;
exit4:
    for (size_t i = 0; i < depth; i++) {
        if (array[layer] != NULL) {
            free(array[layer]);
            array[layer] = NULL;
        }
    }
exit3:
    free(*returnColumnSizes);
exit2:
    free(array);
exit1:
    *returnSize = 0;
    *returnColumnSizes = NULL;
    return NULL;
}