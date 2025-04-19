#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

static void inorder(struct TreeNode *root, int *minDifference, int *prevValue) {
    if (root == NULL) {
        return;
    }

    inorder(root->left, minDifference, prevValue);

    if (*prevValue >= 0) {
        if (*minDifference > abs(root->val - *prevValue)) {
            *minDifference = abs(root->val - *prevValue);
        }
    }

    *prevValue = root->val;

    inorder(root->right, minDifference, prevValue);
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int getMinimumDifference(struct TreeNode *root) {
    int minDifference = INT_MAX;
    int prevValue = -1;

    inorder(root, &minDifference, &prevValue);

    return minDifference;
}

#define ARRAY_SIZE 10000

static void dfs(struct TreeNode *node, int *values, int *count) {
    if (node == NULL) {
        return;
    }

    dfs(node->left, values, count);
    values[(*count)++] = node->val;
    dfs(node->right, values, count);
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int getMinimumDifference(struct TreeNode *root) {
    int values[ARRAY_SIZE];
    int count = 0;

    dfs(root, values, &count);

    int minDifference = INT_MAX;

    for (int i = 1; i < count; i++) {
        if (minDifference > values[i] - values[i - 1]) {
            minDifference = values[i] - values[i - 1];
        }
    }

    return minDifference;
}