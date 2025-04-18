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
struct TreeNode *buildTree(int *inorder, int inorderSize, int *postorder, int postorderSize) {
    if (inorderSize == 0 || postorderSize == 0) {
        return NULL;
    }

    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->val = postorder[postorderSize - 1];
    int i = 0;

    for (; i < inorderSize; i++) {
        if (inorder[i] == node->val) {
            break;
        }
    }

    node->left = buildTree(inorder, i, postorder, i);
    node->right = buildTree(inorder + i + 1, inorderSize - 1 - i, postorder + i, postorderSize - 1 - i);

    return node;
}

typedef struct {
    int key;
    int value;
    UT_hash_handle hh;
} HashEntry;

static struct TreeNode *build(int *inorder, int start, int end, int *postorder, int *postorderIndex, HashEntry **map) {
    if (start > end) {
        return NULL;
    }

    int current = postorder[(*postorderIndex)--];
    HashEntry *entry = NULL;

    HASH_FIND_INT(*map, &current, entry);

    int index = entry->value;
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));

    node->val = current;
    node->right = build(inorder, index + 1, end, postorder, postorderIndex, map);
    node->left = build(inorder, start, index - 1, postorder, postorderIndex, map);

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
struct TreeNode *buildTree(int *inorder, int inorderSize, int *postorder, int postorderSize) {
    HashEntry *map = NULL;

    for (int i = 0; i < inorderSize; i++) {
        HashEntry *entry = (HashEntry *)malloc(sizeof(HashEntry));
        entry->key = inorder[i];
        entry->value = i;
        HASH_ADD_INT(map, key, entry);
    }

    int postorderIndex = postorderSize - 1;

    return build(inorder, 0, inorderSize - 1, postorder, &postorderIndex, &map);
}