#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

#define ARRAY_SIZE 10000

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
double *averageOfLevels(struct TreeNode *root, int *returnSize) {
    *returnSize = 0;
    if (root == NULL) {
        return NULL;
    }

    double *array = (double *)calloc(ARRAY_SIZE, sizeof(double));
    if (array == NULL) {
        return NULL;
    }

    struct TreeNode *q[ARRAY_SIZE] = {NULL};
    q[0] = root;
    int head = 0;
    int tail = 1;

    while (head < tail) {
        int next = tail;
        int size = tail - head;

        for (int i = head; i < next; i++) {
            array[*returnSize] += q[i]->val;
            if (q[i]->left != NULL) {
                q[tail++] = q[i]->left;
            }

            if (q[i]->right != NULL) {
                q[tail++] = q[i]->right;
            }
        }

        array[*returnSize] /= size;
        *returnSize += 1;
        head = next;
    }

    return array;
}