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
struct TreeNode *deleteNode(struct TreeNode *root, int key) {
    if (root == NULL) {
        return NULL;
    }

    if (root->val > key) {
        root->left = deleteNode(root->left, key);
    } else if (root->val < key) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }

        if (root->left == NULL || root->right == NULL) {
            struct TreeNode *node = (root->left != NULL) ? root->left : root->right;

            free(root);
            return node;
        }

        struct TreeNode *node = root->left;

        while (node->right != NULL) {
            node = node->right;
        }

        root->val = node->val;
        root->left = deleteNode(root->left, node->val);
    }

    return root;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode *deleteNode(struct TreeNode *root, int key) {
    if (root == NULL) {
        return NULL;
    }

    if (root->val > key) {
        root->left = deleteNode(root->left, key);
    } else if (root->val < key) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }

        if (root->left == NULL || root->right == NULL) {
            struct TreeNode *node = (root->left != NULL) ? root->left : root->right;

            free(root);
            return node;
        }

        struct TreeNode *node = root->right;

        while (node->left != NULL) {
            node = node->left;
        }

        root->val = node->val;
        root->right = deleteNode(root->right, node->val);
    }

    return root;
}