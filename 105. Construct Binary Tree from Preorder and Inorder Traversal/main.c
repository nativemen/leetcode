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
struct TreeNode *buildTree(int *preorder, int preorderSize, int *inorder, int inorderSize) {
    if (preorderSize == 0 || inorderSize == 0) {
        return NULL;
    }

    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->val = preorder[0];

    int mid = 0;

    for (int i = 0; i < inorderSize; i++) {
        if (inorder[i] == preorder[0]) {
            mid = i;
        }
    }

    node->left = buildTree(preorder + 1, mid, inorder, mid);
    node->right = buildTree(preorder + mid + 1, preorderSize - mid - 1, inorder + mid + 1, inorderSize - mid - 1);

    return node;
}