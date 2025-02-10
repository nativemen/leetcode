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
bool isPalindrome(struct ListNode *head) {
    struct ListNode *slow = head;
    struct ListNode *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    if (fast != NULL) {
        slow = slow->next;
    }

    struct ListNode *prev = NULL;
    struct ListNode *cur = slow;
    while (cur != NULL) {
        struct ListNode *temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
    }

    while (prev != NULL) {
        if (prev->val != head->val) {
            return false;
        }

        prev = prev->next;
        head = head->next;
    }

    return true;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode *head) {
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    struct ListNode *prev = NULL;

    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        struct ListNode *temp = slow->next;
        slow->next = prev;
        prev = slow;
        slow = temp;
    }

    if (fast != NULL) {
        slow = slow->next;
    }

    while (slow != NULL) {
        if (prev->val != slow->val) {
            return false;
        }

        prev = prev->next;
        slow = slow->next;
    }

    return true;
}

#define ARRAY_SIZE 100000

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode *head) {
    int *array = (int *)calloc(ARRAY_SIZE, sizeof(int));
    if (array == NULL) {
        return false;
    }

    size_t count = 0;
    while (head != NULL) {
        array[count] = head->val;
        head = head->next;
        count++;
    }

    for (size_t i = 0; i < count / 2; i++) {
        if (array[i] != array[count - 1 - i]) {
            return false;
        }
    }

    return true;
}

static struct ListNode *findSecondList(struct ListNode *list) {
    struct ListNode *slow = list;
    struct ListNode *fast = list;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    if (fast != NULL) {
        slow = slow->next;
    }

    return slow;
}

static struct ListNode *reverseList(struct ListNode *list) {
    struct ListNode *prev = NULL;
    struct ListNode *cur = list;
    while (cur != NULL) {
        struct ListNode *temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
    }

    return prev;
}

static bool compareList(struct ListNode *firstList, struct ListNode *secondList) {
    while (secondList != NULL) {
        if (secondList->val != firstList->val) {
            return false;
        }

        firstList = firstList->next;
        secondList = secondList->next;
    }

    return true;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode *head) {
    struct ListNode *secondList = findSecondList(head);
    struct ListNode *secondHead = reverseList(secondList);
    return compareList(head, secondHead);
}