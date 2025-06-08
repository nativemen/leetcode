#include <stdbool.h>
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

#define ARRAY_SIZE 20000

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *oddEvenList(struct ListNode *head) {
    if (head == NULL) {
        return NULL;
    }

    struct ListNode *current = head;
    struct ListNode *oddListArray[ARRAY_SIZE] = {NULL};
    struct ListNode *evenListArray[ARRAY_SIZE] = {NULL};
    int oddCount = 0;
    int evenCount = 0;
    int count = 0;

    while (current != NULL) {
        if (count % 2 == 0) {
            oddListArray[oddCount++] = current;
        } else {
            evenListArray[evenCount++] = current;
        }

        count++;
        current = current->next;
    }

    for (int i = 0; i < oddCount - 1; i++) {
        oddListArray[i]->next = oddListArray[i + 1];
    }

    oddListArray[oddCount - 1]->next = evenListArray[0];

    for (int i = 0; i < evenCount - 1; i++) {
        evenListArray[i]->next = evenListArray[i + 1];
    }

    if (evenCount > 0) {
        evenListArray[evenCount - 1]->next = NULL;
    }

    return oddListArray[0];
}

#define ARRAY_SIZE 20000

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *oddEvenList(struct ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct ListNode *current = head;
    struct ListNode *oddListArray[ARRAY_SIZE] = {NULL};
    struct ListNode *evenListArray[ARRAY_SIZE] = {NULL};
    int oddCount = 0;
    int evenCount = 0;
    int count = 0;

    while (current != NULL) {
        if (count % 2 == 0) {
            oddListArray[oddCount++] = current;
        } else {
            evenListArray[evenCount++] = current;
        }

        count++;
        current = current->next;
    }

    for (int i = 0; i < oddCount - 1; i++) {
        oddListArray[i]->next = oddListArray[i + 1];
    }

    oddListArray[oddCount - 1]->next = evenListArray[0];

    for (int i = 0; i < evenCount - 1; i++) {
        evenListArray[i]->next = evenListArray[i + 1];
    }

    evenListArray[evenCount - 1]->next = NULL;

    return oddListArray[0];
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *oddEvenList(struct ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct ListNode *odd = head;
    struct ListNode *even = head->next;
    struct ListNode *evenHead = even;

    while (even != NULL && even->next != NULL) {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }

    odd->next = evenHead;

    return head;
}