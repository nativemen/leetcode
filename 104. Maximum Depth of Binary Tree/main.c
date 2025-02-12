#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

static int max(int a, int b) {
    return (a > b) ? a : b;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode *root) {
    if (root == NULL) {
        return 0;
    }

    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode *root) {
    if (root == NULL) {
        return 0;
    }

    int left = 1 + maxDepth(root->left);
    int right = 1 + maxDepth(root->right);
    return (left > right) ? left : right;
}