#include <stdio.h>

struct Node {
    int val;
    struct Node *left;
    struct Node *right;
    struct Node *next;
};

#define ARRAY_SIZE 4096

/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *left;
 *     struct Node *right;
 *     struct Node *next;
 * };
 */

struct Node *connect(struct Node *root) {
    if (root == NULL) {
        return NULL;
    }

    struct Node *array[ARRAY_SIZE] = {NULL};
    int head = 0;
    int tail = 1;
    array[0] = root;

    while (head < tail) {
        int next = tail;

        for (int i = head; i < next; i++) {
            if (array[i]->left != NULL) {
                array[tail++] = array[i]->left;
            }

            if (array[i]->right != NULL) {
                array[tail++] = array[i]->right;
            }

            if (i < next - 1) {
                array[i]->next = array[i + 1];
            }
        }

        array[next - 1]->next = NULL;
        head = next;
    }

    return root;
}

static struct Node *getNext(struct Node *node) {
    while (node != NULL) {
        if (node->left != NULL) {
            return node->left;
        }

        if (node->right != NULL) {
            return node->right;
        }

        node = node->next;
    }

    return NULL;
}

/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *left;
 *     struct Node *right;
 *     struct Node *next;
 * };
 */
struct Node *connect(struct Node *root) {
    if (root == NULL) {
        return NULL;
    }

    if (root->left != NULL) {
        if (root->right != NULL) {
            root->left->next = root->right;
        } else {
            root->left->next = getNext(root->next);
        }
    }

    if (root->right != NULL) {
        root->right->next = getNext(root->next);
    }

    connect(root->right);
    connect(root->left);

    return root;
}

/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *left;
 *     struct Node *right;
 *     struct Node *next;
 * };
 */
struct Node *connect(struct Node *root) {
    if (root == NULL) {
        return NULL;
    }

    struct Node *node = root;

    while (node != NULL) {
        struct Node *leftestNode = NULL;
        struct Node *nextNode = NULL;

        while (node != NULL) {
            if (node->left != NULL) {
                if (leftestNode == NULL) {
                    nextNode = node->left;
                    leftestNode = nextNode;
                } else {
                    nextNode->next = node->left;
                    nextNode = nextNode->next;
                }
            }

            if (node->right != NULL) {
                if (leftestNode == NULL) {
                    nextNode = node->right;
                    leftestNode = nextNode;
                } else {
                    nextNode->next = node->right;
                    nextNode = nextNode->next;
                }
            }

            node = node->next;
        }

        node = leftestNode;
    }

    return root;
}