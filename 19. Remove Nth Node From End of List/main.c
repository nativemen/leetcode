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
struct ListNode *removeNthFromEnd(struct ListNode *head, int n) {
    struct ListNode *tail = head;
    while (n > 0) {
        if (tail == NULL) {
            return NULL;
        }
        tail = tail->next;
        n--;
    }

    struct ListNode **node = &head;
    while (tail != NULL) {
        node = &(*node)->next;
        tail = tail->next;
    }

    struct ListNode *temp = *node;
    *node = (*node)->next;
    free(temp);
    return head;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *removeNthFromEnd(struct ListNode *head, int n) {
    struct ListNode *tail = head;
    while (n > 0) {
        tail = tail->next;
        n--;
    }

    struct ListNode **node = &head;
    while (tail != NULL) {
        node = &(*node)->next;
        tail = tail->next;
    }

    struct ListNode *temp = *node;
    *node = (*node)->next;
    free(temp);
    return head;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *removeNthFromEnd(struct ListNode *head, int n) {
    struct ListNode dummy = {0, head};
    dummy.next = head;

    struct ListNode *fast = &dummy;
    while (n >= 0) {
        if (fast == NULL) {
            return NULL;
        }
        fast = fast->next;
        n--;
    }

    struct ListNode *slow = &dummy;
    while (fast != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    slow->next = slow->next->next;
    return dummy.next;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *removeNthFromEnd(struct ListNode *head, int n) {
    struct ListNode dummy = {0, head};
    dummy.next = head;

    struct ListNode *fast = &dummy;
    while (n >= 0) {
        fast = fast->next;
        n--;
    }

    struct ListNode *slow = &dummy;
    while (fast != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    slow->next = slow->next->next;
    return dummy.next;
}