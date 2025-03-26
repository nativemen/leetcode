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
struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
    int carry = 0;
    int count1 = 0;
    int count2 = 0;
    struct ListNode **head1 = &l1;
    struct ListNode **head2 = &l2;

    while (*head1 != NULL || *head2 != NULL) {
        int num1 = (*head1 != NULL) ? (*head1)->val : 0;
        int num2 = (*head2 != NULL) ? (*head2)->val : 0;
        int sum = num1 + num2 + carry;

        carry = sum / 10;
        if (*head1 != NULL) {
            (*head1)->val = sum % 10;
            count1++;
            head1 = &(*head1)->next;
        }
        if (*head2 != NULL) {
            (*head2)->val = sum % 10;
            count2++;
            head2 = &(*head2)->next;
        }
    }

    if (carry != 0) {
        struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
        node->val = carry;
        node->next = NULL;
        if (count1 > count2) {
            *head1 = node;
        } else {
            *head2 = node;
        }
    }

    return (count1 > count2) ? l1 : l2;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
    int carry = 0;
    struct ListNode dummyHead;
    dummyHead.val = 0;
    dummyHead.next = NULL;
    struct ListNode *currentNode = &dummyHead;

    while (l1 != NULL || l2 != NULL || carry != 0) {
        int num1 = (l1 != NULL) ? l1->val : 0;
        int num2 = (l2 != NULL) ? l2->val : 0;
        int sum = num1 + num2 + carry;
        carry = sum / 10;

        currentNode->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        currentNode = currentNode->next;
        currentNode->val = sum % 10;
        currentNode->next = NULL;

        if (l1 != NULL) {
            l1 = l1->next;
        }

        if (l2 != NULL) {
            l2 = l2->next;
        }
    }

    return dummyHead.next;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
    int carry = 0;
    struct ListNode dummyHead;
    dummyHead.val = 0;
    dummyHead.next = NULL;
    struct ListNode *currentNode = &dummyHead;

    while (l1 != NULL || l2 != NULL || carry != 0) {
        int sum = carry;

        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 10;
        currentNode->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        currentNode = currentNode->next;
        currentNode->val = sum % 10;
        currentNode->next = NULL;
    }

    return dummyHead.next;
}