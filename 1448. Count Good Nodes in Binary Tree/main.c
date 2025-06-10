#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

static void dfs(struct TreeNode *root, int maxVal, int *count) {
    if (root == NULL) {
        return;
    }

    if (root->val >= maxVal) {
        *count += 1;
        maxVal = root->val;
    }

    dfs(root->left, maxVal, count);
    dfs(root->right, maxVal, count);
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int goodNodes(struct TreeNode *root) {
    int count = 0;

    dfs(root, INT_MIN, &count);

    return count;
}

static int dfs(struct TreeNode *root, int maxVal) {
    int good = 0;

    if (root == NULL) {
        return good;
    }

    if (root->val >= maxVal) {
        good = 1;
        maxVal = root->val;
    }

    return good + dfs(root->left, maxVal) + dfs(root->right, maxVal);
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int goodNodes(struct TreeNode *root) {
    return dfs(root, INT_MIN);
}