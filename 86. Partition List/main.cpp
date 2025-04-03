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

/**
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
    ListNode *partition(ListNode *head, int x) {
        ListNode dummy1;
        ListNode dummy2;
        ListNode *first = &dummy1;
        ListNode *second = &dummy2;

        while (head) {
            if (head->val < x) {
                first->next = head;
                first = first->next;
            } else {
                second->next = head;
                second = second->next;
            }

            head = head->next;
        }

        first->next = dummy2.next;
        second->next = nullptr;

        return dummy1.next;
    }
};

/**
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
    ListNode *partition(ListNode *head, int x) {
        ListNode dummy1;
        ListNode dummy2;
        ListNode *first = &dummy1;
        ListNode *second = &dummy2;
        dummy1.next = head;

        while (first->next) {
            if (first->next->val < x) {
                first = first->next;
            } else {
                second->next = first->next;
                second = second->next;
                first->next = first->next->next;
            }
        }

        first->next = dummy2.next;
        second->next = nullptr;

        return dummy1.next;
    }
};

/**
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
    ListNode *partition(ListNode *head, int x) {
        ListNode *newHead = nullptr;
        ListNode **first = &newHead;
        ListNode **second = &head;

        while (*second) {
            if ((*second)->val < x) {
                *first = *second;
                *second = (*second)->next;
                first = &(*first)->next;
            } else {
                second = &(*second)->next;
            }
        }

        *first = head;

        return newHead;
    }
};