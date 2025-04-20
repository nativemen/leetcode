#include <stdbool.h>
#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

#define ARRAY_SIZE 100000

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct {
    struct TreeNode *array[ARRAY_SIZE];
    int count;
    int next;
} BSTIterator;

static void inorder(struct TreeNode *root, BSTIterator *iter) {
    if (root == NULL) {
        return;
    }

    inorder(root->left, iter);
    iter->array[iter->count++] = root;
    inorder(root->right, iter);
}

BSTIterator *bSTIteratorCreate(struct TreeNode *root) {
    BSTIterator *iter = (BSTIterator *)calloc(1, sizeof(BSTIterator));
    if (iter == NULL) {
        return NULL;
    }

    inorder(root, iter);

    return iter;
}

bool bSTIteratorHasNext(BSTIterator *obj) {
    return obj->next < obj->count;
}

int bSTIteratorNext(BSTIterator *obj) {
    if (!bSTIteratorHasNext(obj)) {
        return -1;
    }

    return obj->array[obj->next++]->val;
}

void bSTIteratorFree(BSTIterator *obj) {
    free(obj);
}

/**
 * Your BSTIterator struct will be instantiated and called as such:
 * BSTIterator* obj = bSTIteratorCreate(root);
 * int param_1 = bSTIteratorNext(obj);
 * bool param_2 = bSTIteratorHasNext(obj);
 * bSTIteratorFree(obj);
 */