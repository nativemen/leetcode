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
void flatten(struct TreeNode *root) {
    if (root == NULL) {
        return;
    }

    if (root->right != NULL) {
        flatten(root->right);
    }

    if (root->left != NULL) {
        flatten(root->left);
        struct TreeNode *node = root->left;

        while (node->right != NULL) {
            node = node->right;
        }

        node->right = root->right;
        root->right = root->left;
        root->left = NULL;
    }
}

static struct TreeNode *flat(struct TreeNode *node) {
    if (node == NULL) {
        return NULL;
    }

    struct TreeNode *right = node->right;
    node->right = flat(node->left);
    node->left = NULL;

    struct TreeNode *current = node;

    while (current->right != NULL) {
        current = current->right;
    }

    current->right = flat(right);

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
void flatten(struct TreeNode *root) {
    flat(root);
}