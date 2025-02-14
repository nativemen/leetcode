#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

static struct TreeNode *createNode(int val) {
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    if (node == NULL) {
        return NULL;
    }

    node->val = val;
    node->left = NULL;
    node->right = NULL;

    return node;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode *sortedArrayToBST(int *nums, int numsSize) {
    if (numsSize == 0) {
        return NULL;
    }

    int mid = numsSize / 2;
    struct TreeNode *node = createNode(nums[mid]);
    if (node == NULL) {
        return NULL;
    }

    node->left = sortedArrayToBST(nums, mid);
    node->right = sortedArrayToBST(nums + 1 + mid, numsSize - 1 - mid);
    return node;
}

static struct TreeNode *createTree(int *nums, int left, int right) {
    if (left > right) {
        return NULL;
    }

    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    if (node == NULL) {
        return NULL;
    }

    int mid = (left + right + 1) / 2;
    node->val = nums[mid];
    node->left = createTree(nums, left, mid - 1);
    node->right = createTree(nums, mid + 1, right);

    return node;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode *sortedArrayToBST(int *nums, int numsSize) {
    return createTree(nums, 0, numsSize - 1);
}