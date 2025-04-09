#include <stdbool.h>
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

#define ARRAY_SIZE 5000

static void reverse(int *array, int left, int right) {
    while (left < right) {
        int temp = array[left];
        array[left++] = array[right];
        array[right--] = temp;
    }
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *reverseKGroup(struct ListNode *head, int k) {
    int array[ARRAY_SIZE] = {0};
    int count = 0;
    struct ListNode *node = head;

    while (node != NULL) {
        array[count++] = node->val;
        node = node->next;
    }

    for (int i = 0; i + k <= count; i += k) {
        reverse(array, i, i + k - 1);
    }

    node = head;
    for (int i = 0; i < count; i++) {
        node->val = array[i];
        node = node->next;
    }

    return head;
}

static struct ListNode **reverseList(struct ListNode **head, int k) {
    int count = 0;
    struct ListNode *node = *head;
    struct ListNode *tail = *head;
    struct ListNode *prev = NULL;
    struct ListNode *temp = NULL;

    while (node != NULL) {
        temp = node->next;
        node->next = prev;
        prev = node;
        count++;
        if (count >= k) {
            break;
        }
        node = temp;
    }

    tail->next = temp;
    *head = node;

    return &tail->next;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *reverseKGroup(struct ListNode *head, int k) {
    int count = 0;
    struct ListNode *node = head;

    while (node != NULL) {
        count++;
        node = node->next;
    }

    struct ListNode **current = &head;
    while (*current != NULL) {
        if (count < k) {
            break;
        }
        current = reverseList(current, k);
        count -= k;
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
struct ListNode *reverseKGroup(struct ListNode *head, int k) {
    if (head == NULL || k <= 1) {
        return head;
    }

    struct ListNode *node = head;
    for (int i = 0; i < k; i++) {
        if (node == NULL) {
            return head;
        }

        node = node->next;
    }

    struct ListNode *current = head;
    struct ListNode *next = NULL;
    struct ListNode *prev = NULL;
    int count = 0;

    while (current != NULL && count < k) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }

    if (next != NULL) {
        head->next = reverseKGroup(next, k);
    }

    return prev;
}

static struct ListNode *getKth(struct ListNode *node, int k) {
    while (node != NULL && k > 0) {
        node = node->next;
        k--;
    }

    return node;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *reverseKGroup(struct ListNode *head, int k) {
    struct ListNode dummy = {0, head};
    struct ListNode *groupPrev = &dummy;

    while (true) {
        struct ListNode *kth = getKth(groupPrev, k);
        if (kth == NULL) {
            break;
        }

        struct ListNode *groupNext = kth->next;
        struct ListNode *prev = kth->next;
        struct ListNode *current = groupPrev->next;

        while (current != groupNext) {
            struct ListNode *next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        struct ListNode *temp = groupPrev->next;
        groupPrev->next = kth;
        groupPrev = temp;
    }

    return dummy.next;
}