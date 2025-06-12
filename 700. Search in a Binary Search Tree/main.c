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
struct TreeNode *searchBST(struct TreeNode *root, int val) {
    if (root == NULL) {
        return NULL;
    }

    if (root->val == val) {
        return root;
    }

    if (root->val > val) {
        return searchBST(root->left, val);
    }

    return searchBST(root->right, val);
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode *searchBST(struct TreeNode *root, int val) {
    while (root != NULL) {
        if (root->val == val) {
            break;
        } else if (root->val > val) {
            root = root->left;
        } else {
            root = root->right;
        }
    }

    return root;
}