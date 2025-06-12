#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

#define QUEUE_SIZE 10000

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxLevelSum(struct TreeNode *root) {
    if (root == NULL) {
        return 0;
    }

    struct TreeNode *q[QUEUE_SIZE];
    int front = 0;
    int rear = 0;
    int maxSum = INT_MIN;
    int level = 1;
    int targetLevel = 1;

    q[rear++] = root;

    while (front < rear) {
        int next = rear;
        int sum = 0;

        for (int i = front; i < next; i++) {
            sum += q[i]->val;

            if (q[i]->left != NULL) {
                q[rear++] = q[i]->left;
            }

            if (q[i]->right != NULL) {
                q[rear++] = q[i]->right;
            }
        }

        if (maxSum < sum) {
            maxSum = sum;
            targetLevel = level;
        }

        front = next;
        level++;
    }

    return targetLevel;
}