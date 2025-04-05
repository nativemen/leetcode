#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

#define ARRAY_SIZE 50000

static int compare(const void *a, const void *b) {
    return *(const int *)a - *(const int *)b;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *sortList(struct ListNode *head) {
    if (head == NULL) {
        return NULL;
    }

    int array[ARRAY_SIZE] = {0};
    int count = 0;

    struct ListNode *node = head;

    while (node != NULL) {
        array[count++] = node->val;
        node = node->next;
    }

    qsort(array, count, sizeof(int), compare);

    node = head;
    int index = 0;

    while (node != NULL) {
        node->val = array[index++];
        node = node->next;
    }

    return head;
}