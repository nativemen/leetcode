#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

#define ARRAY_SIZE 10000

static void inorder(struct TreeNode *root, int *array, int *count) {
    if (root == NULL) {
        return;
    }

    inorder(root->left, array, count);
    array[(*count)++] = root->val;
    inorder(root->right, array, count);
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int kthSmallest(struct TreeNode *root, int k) {
    int array[ARRAY_SIZE];
    int count = 0;

    inorder(root, array, &count);

    if (k < 1 || k > count) {
        return -1;
    }

    return array[k - 1];
}

static void inorder(struct TreeNode *root, int *result, int *count, int k) {
    if (root == NULL || *count > k) {
        return;
    }

    inorder(root->left, result, count, k);
    if (*count == k) {
        *result = root->val;
        *count += 1;
        return;
    }
    *count += 1;
    inorder(root->right, result, count, k);
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int kthSmallest(struct TreeNode *root, int k) {
    int result = -1;
    int count = 1;

    inorder(root, &result, &count, k);

    return result;
}