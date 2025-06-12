#include <stdbool.h>
#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

static int max(int a, int b) {
    return (a > b) ? a : b;
}

static void zigZag(struct TreeNode *root, bool isRight, int steps, int *maxCount) {
    if (root == NULL) {
        return;
    }

    *maxCount = max(*maxCount, steps);

    if (isRight) {
        zigZag(root->left, true, 1, maxCount);
        zigZag(root->right, false, steps + 1, maxCount);
    } else {
        zigZag(root->left, true, steps + 1, maxCount);
        zigZag(root->right, false, 1, maxCount);
    }
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int longestZigZag(struct TreeNode *root) {
    int maxCount = 0;

    zigZag(root, true, 0, &maxCount);
    zigZag(root, false, 0, &maxCount);

    return maxCount;
}

static void zigLeft(struct TreeNode *root, int steps, int *maxCount);

static void zigRight(struct TreeNode *root, int steps, int *maxCount) {
    if (root == NULL) {
        return;
    }

    if (steps > *maxCount) {
        *maxCount = steps;
    }

    zigLeft(root->left, steps + 1, maxCount);
    zigRight(root->right, 1, maxCount);
}

static void zigLeft(struct TreeNode *root, int steps, int *maxCount) {
    if (root == NULL) {
        return;
    }

    if (steps > *maxCount) {
        *maxCount = steps;
    }

    zigRight(root->right, steps + 1, maxCount);
    zigLeft(root->left, 1, maxCount);
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int longestZigZag(struct TreeNode *root) {
    if (root == NULL) {
        return 0;
    }

    int maxCount = 0;

    zigRight(root->right, 1, &maxCount);
    zigLeft(root->left, 1, &maxCount);

    return maxCount;
}

static void zigZag(struct TreeNode *root, int left, int right, int *maxCount) {
    if (root == NULL) {
        return;
    }

    int maxVal = (left > right) ? left : right;

    if (*maxCount < maxVal) {
        *maxCount = maxVal;
    }

    zigZag(root->left, right + 1, 0, maxCount);
    zigZag(root->right, 0, left + 1, maxCount);
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int longestZigZag(struct TreeNode *root) {
    if (root == NULL) {
        return 0;
    }

    int maxCount = 0;

    zigZag(root->right, 0, 1, &maxCount);
    zigZag(root->left, 1, 0, &maxCount);

    return maxCount;
}