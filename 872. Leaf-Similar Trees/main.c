#include <stdbool.h>
#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

#define ARRAY_SIZE 200

static void dfs(struct TreeNode *root, int *leaves, int *count) {
    if (root == NULL) {
        return;
    }

    if (root->left == NULL && root->right == NULL) {
        leaves[(*count)++] = root->val;
        return;
    }

    dfs(root->left, leaves, count);
    dfs(root->right, leaves, count);
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool leafSimilar(struct TreeNode *root1, struct TreeNode *root2) {
    int leaves1[ARRAY_SIZE];
    int leaves2[ARRAY_SIZE];
    int count1 = 0;
    int count2 = 0;

    dfs(root1, leaves1, &count1);
    dfs(root2, leaves2, &count2);

    if (count1 != count2 || memcmp(leaves1, leaves2, count1 * sizeof(int)) != 0) {
        return false;
    }

    return true;
}