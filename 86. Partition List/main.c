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
struct ListNode *partition(struct ListNode *head, int x) {
    struct ListNode *newHead = NULL;
    struct ListNode **first = &newHead;
    struct ListNode **second = &head;

    while (*second != NULL) {
        if ((*second)->val < x) {
            *first = *second;
            *second = (*second)->next;
            first = &(*first)->next;
        } else {
            second = &(*second)->next;
        }
    }

    *first = head;

    return newHead;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *partition(struct ListNode *head, int x) {
    struct ListNode dummy1;
    struct ListNode dummy2;
    struct ListNode *first = &dummy1;
    struct ListNode *second = &dummy2;

    while (head != NULL) {
        if (head->val < x) {
            first->next = head;
            first = first->next;
        } else {
            second->next = head;
            second = second->next;
        }
        head = head->next;
    }

    second->next = NULL;
    first->next = dummy2.next;

    return dummy1.next;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *partition(struct ListNode *head, int x) {
    struct ListNode dummy1;
    struct ListNode dummy2;
    struct ListNode *first = &dummy1;
    struct ListNode *second = &dummy2;
    dummy1.next = head;

    while (first->next != NULL) {
        if (first->next->val < x) {
            first = first->next;
        } else {
            second->next = first->next;
            first->next = first->next->next;
            second = second->next;
        }
    }

    second->next = NULL;
    first->next = dummy2.next;

    return dummy1.next;
}