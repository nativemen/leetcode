#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

#define ARRAY_SIZE 500

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *reverseBetween(struct ListNode *head, int left, int right) {
    int index = 0;
    int values[ARRAY_SIZE] = {0};
    struct ListNode *node = head;

    while (node != NULL) {
        values[index] = node->val;
        index++;
        node = node->next;
    }

    for (int i = left - 1; i < (left + right) / 2; i++) {
        int temp = values[i];
        values[i] = values[right + left - 2 - i];
        values[right + left - 2 - i] = temp;
    }

    node = head;
    index = 0;
    while (node != NULL) {
        node->val = values[index];
        index++;
        node = node->next;
    }

    return head;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *reverseBetween(struct ListNode *head, int left, int right) {
    struct ListNode dummy = {0, head};
    int index = 0;
    struct ListNode *node = &dummy;

    while (index < left - 1) {
        node = node->next;
        index++;
    }

    struct ListNode *left_before = node;
    struct ListNode *prev = NULL;
    struct ListNode *current = node->next;
    struct ListNode *left_begin = current;
    struct ListNode *next = NULL;
    while (index < right && current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        index++;
    }

    left_before->next = prev;
    left_begin->next = current;

    return dummy.next;
}

static struct ListNode *reverse(struct ListNode *leftNode, struct ListNode *rightNode) {
    struct ListNode *prev = NULL;
    struct ListNode *current = leftNode;
    struct ListNode *next = NULL;

    while (current != rightNode) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    current->next = prev;

    return current;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *reverseBetween(struct ListNode *head, int left, int right) {
    if (head == NULL || left == right) {
        return head;
    }

    struct ListNode *leftPrev = NULL;
    struct ListNode *node = head;
    for (int i = 1; i < left; i++) {
        leftPrev = node;
        node = node->next;
    }

    struct ListNode *leftNode = node;
    for (int i = left; i < right; i++) {
        node = node->next;
    }

    struct ListNode *rightNode = node;
    struct ListNode *rightNext = node->next;
    if (leftPrev == NULL) {
        head = reverse(leftNode, rightNode);
    } else {
        leftPrev->next = reverse(leftNode, rightNode);
    }
    leftNode->next = rightNext;

    return head;
}