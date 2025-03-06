#include <stdio.h>

static inline int max(int a, int b) {
    return (a > b) ? a : b;
}

static void robHelper(struct TreeNode *root, int *with_root, int *without_root) {
    if (root == NULL) {
        *with_root = 0;
        *without_root = 0;
        return;
    }

    int left_with_root = 0;
    int left_without_root = 0;
    robHelper(root->left, &left_with_root, &left_without_root);
    int right_with_root = 0;
    int right_without_root = 0;
    robHelper(root->right, &right_with_root, &right_without_root);

    *with_root = root->val + left_without_root + right_without_root;
    *without_root = max(left_with_root, left_without_root) + max(right_with_root, right_without_root);
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int rob(struct TreeNode *root) {
    int with_root = 0;
    int without_root = 0;

    robHelper(root, &with_root, &without_root);
    return max(with_root, without_root);
}