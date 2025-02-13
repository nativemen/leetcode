#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

static bool helper(struct TreeNode *root, long long min, long long max) {
    if (root == NULL) {
        return true;
    }

    if ((long long)root->val >= max || (long long)root->val <= min) {
        return false;
    }

    return helper(root->left, min, (long long)root->val) && helper(root->right, (long long)root->val, max);
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isValidBST(struct TreeNode *root) {
    return helper(root, LLONG_MIN, LLONG_MAX);
}

#define ARRAY_SIZE 10000

static void toArray(struct TreeNode **array, struct TreeNode *node, size_t *index) {
    if (node == NULL) {
        return;
    }

    toArray(array, node->left, index);
    array[*index] = node;
    *index += 1;
    toArray(array, node->right, index);
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isValidBST(struct TreeNode *root) {
    if (root == NULL) {
        return true;
    }

    struct TreeNode **array = (struct TreeNode **)calloc(ARRAY_SIZE, sizeof(struct TreeNode *));
    if (array == NULL) {
        return false;
    }

    size_t i = 0;
    toArray(array, root, &i);
    for (i = 1; i < ARRAY_SIZE; i++) {
        if (array[i] == NULL) {
            break;
        }

        if (array[i - 1]->val >= array[i]->val) {
            free(array);
            return false;
        }
    }

    free(array);
    return true;
}