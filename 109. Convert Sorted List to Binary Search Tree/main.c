#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

#define ARRAY_SIZE 20000

static struct TreeNode *createTree(int *nums, int numsSize) {
    if (numsSize == 0) {
        return NULL;
    }

    int mid = numsSize / 2;
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    if (node == NULL) {
        return NULL;
    }

    node->val = nums[mid];
    node->left = createTree(nums, mid);
    node->right = createTree(nums + mid + 1, numsSize - 1 - mid);

    return node;
}
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode *sortedListToBST(struct ListNode *head) {
    int *array = (int *)calloc(ARRAY_SIZE, sizeof(int));
    if (array == NULL) {
        return NULL;
    }

    int count = 0;
    while (head != NULL) {
        array[count] = head->val;
        head = head->next;
        count++;
    }

    return createTree(array, count);
}

#define ARRAY_SIZE 20000

static struct TreeNode *createTree(int *nums, int left, int right) {
    if (left > right) {
        return NULL;
    }

    int mid = (left + right + 1) / 2;
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    if (node == NULL) {
        return NULL;
    }

    node->val = nums[mid];
    node->left = createTree(nums, left, mid - 1);
    node->right = createTree(nums, mid + 1, right);

    return node;
}
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode *sortedListToBST(struct ListNode *head) {
    int *array = (int *)calloc(ARRAY_SIZE, sizeof(int));
    if (array == NULL) {
        return NULL;
    }

    int count = 0;
    while (head != NULL) {
        array[count] = head->val;
        head = head->next;
        count++;
    }

    return createTree(array, 0, count - 1);
}

static struct ListNode *findListMiddle(struct ListNode *head, struct ListNode *tail) {
    struct ListNode *slow = head;
    struct ListNode *fast = head;

    while (fast != tail && fast->next != tail) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

static struct TreeNode *helper(struct ListNode *head, struct ListNode *tail) {
    if (head == tail) {
        return NULL;
    }

    struct ListNode *mid = findListMiddle(head, tail);
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    if (node == NULL) {
        return NULL;
    }

    node->val = mid->val;
    node->left = helper(head, mid);
    node->right = helper(mid->next, tail);

    return node;
}
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode *sortedListToBST(struct ListNode *head) {
    return helper(head, NULL);
}

static struct ListNode *splitListAtMiddle(struct ListNode *head) {
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    struct ListNode *prev = NULL;

    while (fast != NULL && fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    if (prev != NULL) {
        prev->next = NULL;
    }

    return slow;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode *sortedListToBST(struct ListNode *head) {
    if (head == NULL) {
        return NULL;
    }

    struct ListNode *mid = splitListAtMiddle(head);
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    if (node == NULL) {
        return NULL;
    }
    node->val = mid->val;
    node->left = NULL;
    node->right = NULL;
    if (head == mid) {
        return node;
    }

    node->left = sortedListToBST(head);
    node->right = sortedListToBST(mid->next);

    return node;
}