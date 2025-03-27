#include <stdbool.h>
#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool hasPathSum(struct TreeNode *root, int targetSum) {
    if (root == NULL) {
        return false;
    } else if (root->left == NULL && root->right == NULL) {
        return root->val == targetSum;
    } else if (root->left == NULL) {
        return hasPathSum(root->right, targetSum - root->val);
    } else if (root->right == NULL) {
        return hasPathSum(root->left, targetSum - root->val);
    } else {
        return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
    }
}

static bool helper(struct TreeNode *root, int targetSum, int currentSum) {
    if (root == NULL) {
        return false;
    }

    currentSum += root->val;

    if (root->left == NULL && root->right == NULL) {
        return targetSum == currentSum;
    }

    return helper(root->left, targetSum, currentSum) || helper(root->right, targetSum, currentSum);
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool hasPathSum(struct TreeNode *root, int targetSum) {
    return helper(root, targetSum, 0);
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool hasPathSum(struct TreeNode *root, int targetSum) {
    if (root == NULL) {
        return false;
    }

    targetSum -= root->val;

    if (root->left == NULL && root->right == NULL) {
        return targetSum == 0;
    }

    return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
}