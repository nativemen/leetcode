#include <stdbool.h>
#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

static int calcSum(struct TreeNode *root, long long targetSum, bool started) {
    if (root == NULL) {
        return 0;
    }

    int sum = 0;

    if (targetSum == (long long)root->val) {
        sum++;
    }

    if (!started) {
        sum += calcSum(root->left, targetSum, started);
        sum += calcSum(root->right, targetSum, started);
    }

    sum += calcSum(root->left, targetSum - (long long)root->val, true);
    sum += calcSum(root->right, targetSum - (long long)root->val, true);

    return sum;
}
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int pathSum(struct TreeNode *root, int targetSum) {
    return calcSum(root, (long long)targetSum, false);
}

#define QUEUE_SIZE 1000

static int dfs(struct TreeNode *root, int targetSum, int *q, int *head, int *tail) {
    if (root == NULL) {
        return 0;
    }

    q[(*tail)++] = root->val;

    long long sum = 0;
    int count = 0;

    for (int i = *tail - 1; i >= *head; i--) {
        sum += q[i];
        if (sum == (long long)targetSum) {
            count++;
        }
    }

    count += dfs(root->left, targetSum, q, head, tail);
    count += dfs(root->right, targetSum, q, head, tail);

    *tail -= 1;

    return count;
}
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int pathSum(struct TreeNode *root, int targetSum) {
    int q[QUEUE_SIZE];
    int head = 0;
    int tail = 0;

    return dfs(root, targetSum, q, &head, &tail);
}