#include "uthash.h"
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

typedef struct {
    int key;
    int value;
    UT_hash_handle hh;
} HashEntry;

static struct TreeNode *build(int *preorder, int *preorderIndex, int *inorder, int start, int end, HashEntry **map) {
    if (start > end) {
        return NULL;
    }

    int current = preorder[*preorderIndex];
    *preorderIndex += 1;
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->val = current;
    HashEntry *entry = NULL;
    HASH_FIND_INT(*map, &current, entry);
    int idx = entry->value;
    node->left = build(preorder, preorderIndex, inorder, start, idx - 1, map);
    node->right = build(preorder, preorderIndex, inorder, idx + 1, end, map);

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
struct TreeNode *buildTree(int *preorder, int preorderSize, int *inorder, int inorderSize) {
    HashEntry *map = NULL;

    for (int i = 0; i < inorderSize; i++) {
        HashEntry *entry = (HashEntry *)malloc(sizeof(HashEntry));
        entry->key = inorder[i];
        entry->value = i;
        HASH_ADD_INT(map, key, entry);
    }

    int preorderIndex = 0;

    return build(preorder, &preorderIndex, inorder, 0, inorderSize - 1, &map);
}