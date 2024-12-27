#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

#define ARRAY_SIZE 5001

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *reverseList(struct ListNode *head) {
    int index = 0;
    int values[ARRAY_SIZE] = {0};
    struct ListNode *node = head;
    while (node != NULL) {
        values[index] = node->val;
        index++;
        node = node->next;
    }

    node = head;
    for (int i = index - 1; i >= 0; i--) {
        node->val = values[i];
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
struct ListNode *reverseList(struct ListNode *head) {
    struct ListNode *prev = NULL;
    struct ListNode *current = head;
    struct ListNode *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}