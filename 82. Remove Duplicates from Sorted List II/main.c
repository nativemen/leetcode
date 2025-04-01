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
struct ListNode *deleteDuplicates(struct ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct ListNode **prev = &head;
    struct ListNode *current = head->next;

    while (current != NULL) {
        if ((*prev)->val == current->val) {
            if (current->next == NULL) {
                *prev = NULL;
                current = NULL;
                continue;
            } else if (current->val != current->next->val) {
                *prev = current->next;
                current = current->next->next;
                continue;
            }
        } else {
            prev = &(*prev)->next;
        }

        current = current->next;
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
struct ListNode *deleteDuplicates(struct ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct ListNode **current = &head;

    while (*current != NULL) {
        if ((*current)->next != NULL && (*current)->val == (*current)->next->val) {
            int val = (*current)->val;
            while (*current != NULL && val == (*current)->val) {
                *current = (*current)->next;
            }
        } else {
            current = &(*current)->next;
        }
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
struct ListNode *deleteDuplicates(struct ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct ListNode dummy = {
            .val = 0,
            .next = head,
    };
    struct ListNode *current = head;
    struct ListNode *prev = &dummy;

    while (current != NULL) {
        if (current->next != NULL && current->val == current->next->val) {
            while (current->next != NULL && current->val == current->next->val) {
                current = current->next;
            }
            prev->next = current->next;
        } else {
            prev = current;
        }

        current = current->next;
    }

    return dummy.next;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *deleteDuplicates(struct ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    if (head->val != head->next->val) {
        head->next = deleteDuplicates(head->next);
        return head;
    }

    while (head->next != NULL && head->val == head->next->val) {
        head = head->next;
    }

    return deleteDuplicates(head->next);
}