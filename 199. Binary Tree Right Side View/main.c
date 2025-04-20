#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

#define ARRAY_SIZE 100

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
int *rightSideView(struct TreeNode *root, int *returnSize) {
    *returnSize = 0;
    if (root == NULL) {
        return NULL;
    }

    int *result = (int *)calloc(ARRAY_SIZE, sizeof(int));
    if (result == NULL) {
        return NULL;
    }

    struct TreeNode *array[ARRAY_SIZE] = {NULL};
    int head = 0;
    int tail = 1;
    array[0] = root;

    while (head < tail) {
        int next = tail;

        for (int i = head; i < next; i++) {
            if (array[i]->left != NULL) {
                array[tail++] = array[i]->left;
            }

            if (array[i]->right != NULL) {
                array[tail++] = array[i]->right;
            }
        }

        result[(*returnSize)++] = array[next - 1]->val;
        head = next;
    }

    return result;
}