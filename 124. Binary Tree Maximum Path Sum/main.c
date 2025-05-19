#include <limits.h>
#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

static int max(int a, int b) {
    return (a > b) ? a : b;
}

static int dfs(struct TreeNode *root, int *maxSum) {
    if (root == NULL) {
        return 0;
    }

    int left = (root->left == NULL) ? 0 : dfs(root->left, maxSum);
    int right = (root->right == NULL) ? 0 : dfs(root->right, maxSum);
    int result = max(left + root->val, right + root->val);
    result = max(result, root->val);
    *maxSum = max(*maxSum, result);
    *maxSum = max(*maxSum, left + right + root->val);

    return result;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxPathSum(struct TreeNode *root) {
    int maxSum = INT_MIN;

    dfs(root, &maxSum);

    return maxSum;
}

static int max(int a, int b) {
    return (a > b) ? a : b;
}

static int dfs(struct TreeNode *root, int *maxSum) {
    if (root == NULL) {
        return 0;
    }

    int left = max(dfs(root->left, maxSum), 0);
    int right = max(dfs(root->right, maxSum), 0);
    int currentSum = left + right + root->val;

    *maxSum = max(*maxSum, currentSum);

    return root->val + max(left, right);
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxPathSum(struct TreeNode *root) {
    int maxSum = INT_MIN;

    dfs(root, &maxSum);

    return maxSum;
}