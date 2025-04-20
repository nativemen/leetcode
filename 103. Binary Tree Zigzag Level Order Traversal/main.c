#include <stdbool.h>
#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

#define ARRAY_SIZE 2000

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
int **zigzagLevelOrder(struct TreeNode *root, int *returnSize, int **returnColumnSizes) {
    *returnSize = 0;
    if (root == NULL) {
        return NULL;
    }

    int **result = (int **)calloc(ARRAY_SIZE, sizeof(int *));
    *returnColumnSizes = (int *)calloc(ARRAY_SIZE, sizeof(int));
    struct TreeNode *array[ARRAY_SIZE] = {NULL};
    array[0] = root;
    int head = 0;
    int tail = 1;
    bool leftToRight = true;

    while (head < tail) {
        int next = tail;
        int size = next - head;
        int count = 0;
        (*returnColumnSizes)[*returnSize] = size;
        result[*returnSize] = (int *)calloc(size, sizeof(int));

        for (int i = head; i < next; i++) {
            int index = leftToRight ? count : size - 1 - count;
            result[*returnSize][index] = array[i]->val;
            count++;

            if (array[i]->left != NULL) {
                array[tail++] = array[i]->left;
            }

            if (array[i]->right != NULL) {
                array[tail++] = array[i]->right;
            }
        }

        *returnSize += 1;
        leftToRight = !leftToRight;
        head = next;
    }

    return result;
}