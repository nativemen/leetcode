#include <stdio.h>

struct Node {
    int val;
    struct Node *next;
    struct Node *random;
};

#define ARRAY_SIZE 1001

/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */
struct Node *copyRandomList(struct Node *head) {
    if (head == NULL) {
        return NULL;
    }

    struct Node **array = (struct Node **)calloc(ARRAY_SIZE, sizeof(struct Node *));
    struct Node *node = head;
    size_t count = 0;

    while (node != NULL) {
        array[count] = (struct Node *)malloc(sizeof(struct Node));
        array[count]->val = node->val;
        array[count]->random = NULL;
        count++;
        node = node->next;
    }
    array[count - 1]->next = NULL;

    node = head;
    size_t current = 0;
    while (node != NULL) {
        array[current]->next = array[current + 1];
        if (node->random != NULL) {
            size_t index = 0;
            struct Node *p = head;
            while (node->random != p) {
                p = p->next;
                index++;
            }
            array[current]->random = array[index];
        }

        current++;
        node = node->next;
    }

    return array[0];
}
/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */
struct Node *copyRandomList(struct Node *head) {
    if (head == NULL) {
        return NULL;
    }

    struct Node *node = head;

    while (node != NULL) {
        struct Node *copy = (struct Node *)malloc(sizeof(struct Node));
        copy->val = node->val;
        copy->next = node->next;
        copy->random = NULL;
        node->next = copy;
        node = copy->next;
    }

    node = head;

    while (node != NULL) {
        if (node->random != NULL) {
            node->next->random = node->random->next;
        }
        node = node->next->next;
    }

    node = head;
    struct Node *newHead = head->next;

    while (node != NULL) {
        struct Node *copy = node->next;
        node->next = copy->next;
        if (copy->next != NULL) {
            copy->next = copy->next->next;
        }
        node = node->next;
    }

    return newHead;
}


/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */
struct Node *copyRandomList(struct Node *head) {
    if (head == NULL) {
        return NULL;
    }

    struct Node *node = head;

    while (node != NULL) {
        struct Node *copy = (struct Node *)malloc(sizeof(struct Node));
        copy->val = node->val;
        copy->next = node->next;
        copy->random = NULL;
        node->next = copy;
        node = copy->next;
    }

    node = head;

    while (node != NULL) {
        if (node->random != NULL) {
            node->next->random = node->random->next;
        }
        node = node->next->next;
    }

    struct Node **current = &head;

    while (*current != NULL) {
        *current = (*current)->next;
        current = &(*current)->next;
    }

    return head;
}