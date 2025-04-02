#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *rotateRight(struct ListNode *head, int k) {
    if (head == NULL || k == 0) {
        return head;
    }

    struct ListNode *current = head;
    int count = 0;

    while (current != NULL) {
        current = current->next;
        count++;
    }

    if (k % count == 0) {
        return head;
    }

    int offset = count - (k % count);
    struct ListNode **node = &head;

    while (offset > 0) {
        node = &(*node)->next;
        offset--;
    }

    struct ListNode *newHead = *node;
    *node = NULL;
    current = newHead;

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = head;

    return newHead;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *rotateRight(struct ListNode *head, int k) {
    if (head == NULL || head->next == NULL || k == 0) {
        return head;
    }

    struct ListNode *node = head;
    int count = 1;

    while (node->next != NULL) {
        node = node->next;
        count++;
    }

    node->next = head;
    node = head;
    int offset = count - (k % count);

    for (int i = 1; i < offset; i++) {
        node = node->next;
    }

    head = node->next;
    node->next = NULL;

    return head;
}