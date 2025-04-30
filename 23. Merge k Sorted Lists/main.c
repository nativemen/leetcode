#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

static struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2) {
    if (list1 == NULL) {
        return list2;
    }

    if (list2 == NULL) {
        return list1;
    }

    if (list1->val < list2->val) {
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    } else {
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *mergeKLists(struct ListNode **lists, int listsSize) {
    if (listsSize < 1) {
        return NULL;
    }

    if (listsSize == 1) {
        return lists[0];
    }

    lists[1] = mergeTwoLists(lists[0], lists[1]);

    return mergeKLists(lists + 1, listsSize - 1);
}

#define ARRAY_SIZE 10000

static int compare(const void *a, const void *b) {
    const struct ListNode *node1 = *(const struct ListNode **)a;
    const struct ListNode *node2 = *(const struct ListNode **)b;

    return node1->val - node2->val;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *mergeKLists(struct ListNode **lists, int listsSize) {
    struct ListNode *array[ARRAY_SIZE] = {NULL};
    int count = 0;

    for (int i = 0; i < listsSize; i++) {
        struct ListNode *node = lists[i];
        while (node != NULL) {
            array[count++] = node;
            node = node->next;
        }
    }

    qsort(array, count, sizeof(struct ListNode *), compare);

    for (int i = 0; i < count - 1; i++) {
        array[i]->next = array[i + 1];
    }

    if (count > 0) {
        array[count - 1]->next = NULL;
    }

    return array[0];
}

static struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2) {
    struct ListNode dummy;
    struct ListNode *current = &dummy;

    while (list1 != NULL && list2 != NULL) {
        if (list1->val < list2->val) {
            current->next = list1;
            list1 = list1->next;
        } else {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }

    current->next = (list1 != NULL) ? list1 : list2;

    return dummy.next;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *mergeKLists(struct ListNode **lists, int listsSize) {
    if (listsSize < 1) {
        return NULL;
    }

    if (listsSize == 1) {
        return lists[0];
    }

    lists[1] = mergeTwoLists(lists[0], lists[1]);

    return mergeKLists(lists + 1, listsSize - 1);
}

static struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2) {
    struct ListNode dummy;
    struct ListNode *current = &dummy;

    while (list1 != NULL && list2 != NULL) {
        if (list1->val < list2->val) {
            current->next = list1;
            list1 = list1->next;
        } else {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }

    current->next = (list1 != NULL) ? list1 : list2;

    return dummy.next;
}

static struct ListNode *mergeKListsHelper(struct ListNode **lists, int left, int right) {
    if (left > right) {
        return NULL;
    }

    if (left == right) {
        return lists[left];
    }

    int mid = (left + right) / 2;
    struct ListNode *leftList = mergeKListsHelper(lists, left, mid);
    struct ListNode *rightList = mergeKListsHelper(lists, mid + 1, right);

    return mergeTwoLists(leftList, rightList);
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *mergeKLists(struct ListNode **lists, int listsSize) {
    return mergeKListsHelper(lists, 0, listsSize - 1);
}
