#include <limits.h>
#include <stdbool.h>
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
bool hasCycle(struct ListNode *head) {
    struct ListNode *slow = head;
    struct ListNode *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true;
        }
    }

    return false;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    while (head != NULL) {
        if (head->val == INT_MAX) {
            return true;
        }

        head->val = INT_MAX;
        head = head->next;
    }

    return false;
}

#define ARRAY_SIZE 10000

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    struct ListNode **array = (struct ListNode **)calloc(ARRAY_SIZE, sizeof(struct ListNode *));
    if (array == NULL) {
        return false;
    }

    while (head != NULL) {
        size_t i = 0;
        while (array[i] != NULL) {
            if (head == array[i]) {
                free(array);
                return true;
            }
            i++;
        }

        array[i] = head;
        head = head->next;
    }

    free(array);
    return false;
}