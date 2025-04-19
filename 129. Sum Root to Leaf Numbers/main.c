#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

static void dfs(struct TreeNode *node, int num, int *sum) {
    if (node == NULL) {
        return;
    }

    num = num * 10 + node->val;

    if (node->left == NULL && node->right == NULL) {
        *sum += num;
        return;
    }

    dfs(node->left, num, sum);
    dfs(node->right, num, sum);
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int sumNumbers(struct TreeNode *root) {
    int sum = 0;

    dfs(root, 0, &sum);

    return sum;
}

static int sum(struct TreeNode *node, int num) {
    if (node == NULL) {
        return 0;
    }

    num = num * 10 + node->val;

    if (node->left == NULL && node->right == NULL) {
        return num;
    }

    return sum(node->left, num) + sum(node->right, num);
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int sumNumbers(struct TreeNode *root) {
    return sum(root, 0);
}