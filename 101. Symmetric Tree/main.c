#include <stdbool.h>
#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

#define ARRAY_SIZE 2000
#define NULL_VAL (1 << 8)

static void toArray(int *array, struct TreeNode *node, size_t *index, int layer) {
    if (node == NULL) {
        array[*index] = NULL_VAL + layer;
        *index += 1;
        return;
    }

    toArray(array, node->left, index, layer + 1);
    array[*index] = node->val;
    *index += 1;
    toArray(array, node->right, index, layer + 1);
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSymmetric(struct TreeNode *root) {
    int *array = (int *)calloc(ARRAY_SIZE, sizeof(int));
    if (array == NULL) {
        return false;
    }

    size_t count = 0;
    toArray(array, root, &count, 1);

    for (size_t i = 0; i < count / 2; i++) {
        if (array[i] != array[count - 1 - i]) {
            free(array);
            return false;
        }
    }

    free(array);
    return true;
}

static bool isMirror(struct TreeNode *left, struct TreeNode *right) {
    if (left == NULL || right == NULL) {
        return left == right;
    }

    if (left->val != right->val) {
        return false;
    }

    return isMirror(left->left, right->right) && isMirror(left->right, right->left);
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSymmetric(struct TreeNode *root) {
    if (root == NULL) {
        return true;
    }

    return isMirror(root->left, root->right);
}