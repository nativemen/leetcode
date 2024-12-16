#include <cstddef>

struct ListNode {
    int val;
    ListNode *next;
    ListNode()
        : val(0)
        , next(nullptr) {}
    ListNode(int x)
        : val(x)
        , next(nullptr) {}
    ListNode(int x, ListNode *next)
        : val(x)
        , next(next) {}
};

/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode *middleNode(ListNode *head) {
        if ((head == NULL) || (head->next == NULL)) {
            return head;
        }

        ListNode *middle = head;
        ListNode *end = head;
        while (end != NULL) {
            if (end->next == NULL) {
                break;
            }

            end = end->next->next;
            middle = middle->next;
        }

        return middle;
    }
};

class Solution {
public:
    ListNode *middleNode(ListNode *head) {
        ListNode *middle = head;
        ListNode *end = head;
        while (end != NULL && end->next != NULL) {
            middle = middle->next;
            end = end->next->next;
        }

        return middle;
    }
};