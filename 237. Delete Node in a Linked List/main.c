#include <stddef.h>

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
void deleteNode(struct ListNode *node) {
    while (node->next != NULL) {
        node->val = node->next->val;
        if (node->next->next == NULL) {
            struct ListNode *temp = node->next;
            node->next = NULL;
            free(temp);
            return;
        }
        node = node->next;
    }
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode *node) {
    node->val = node->next->val;
    struct ListNode *temp = node->next;
    node->next = node->next->next;

    free(temp);
}