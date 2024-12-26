#include <cstddef>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x)
        : val(x)
        , next(NULL) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode *node) {
        while (node->next != NULL) {
            node->val = node->next->val;
            if (node->next->next == NULL) {
                ListNode *temp = node->next;
                node->next = NULL;

                delete temp;
                return;
            }
            node = node->next;
        }
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode *node) {
        node->val = node->next->val;
        ListNode *temp = node->next;
        node->next = node->next->next;

        delete temp;
    }
};