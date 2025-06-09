#include <stdbool.h>
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

#define ARRAY_SIZE 100000

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int pairSum(struct ListNode *head) {
    int array[ARRAY_SIZE];
    int count = 0;
    struct ListNode *node = head;

    while (node != NULL) {
        array[count++] = node->val;
        node = node->next;
    }

    int left = 0;
    int right = count - 1;
    int maxSum = 0;

    while (left < right) {
        int sum = array[left] + array[right];

        if (sum > maxSum) {
            maxSum = sum;
        }

        left++;
        right--;
    }

    return maxSum;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int pairSum(struct ListNode *head) {
    int count = 0;
    struct ListNode *slow = head;
    struct ListNode *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        count++;
    }

    struct ListNode *prev = NULL;
    struct ListNode *next = NULL;

    while (slow != NULL) {
        next = slow->next;
        slow->next = prev;
        prev = slow;
        slow = next;
    }

    int maxSum = 0;
    struct ListNode *node1 = head;
    struct ListNode *node2 = prev;

    for (int i = 0; i < count; i++) {
        int sum = node1->val + node2->val;

        if (sum > maxSum) {
            maxSum = sum;
        }

        node1 = node1->next;
        node2 = node2->next;
    }

    return maxSum;
}


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int pairSum(struct ListNode *head) {
    struct ListNode *slow = head;
    struct ListNode *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct ListNode *prev = NULL;
    struct ListNode *next = NULL;

    while (slow != NULL) {
        next = slow->next;
        slow->next = prev;
        prev = slow;
        slow = next;
    }

    struct ListNode *node1 = head;
    struct ListNode *node2 = prev;
    int maxSum = 0;

    while (node2 != NULL) {
        int sum = node1->val + node2->val;

        if (sum > maxSum) {
            maxSum = sum;
        }

        node1 = node1->next;
        node2 = node2->next;
    }

    return maxSum;
}