#include <malloc.h>
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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *node = head;
        int count = 0;
        while (node != nullptr) {
            node = node->next;
            count++;
        }

        if (count < n) {
            return nullptr;
        }

        int order = count - n;
        if (order == 0) {
            return head->next;
        }

        ListNode *prev = nullptr;
        ListNode *current = head;
        for (int i = 0; i < order; i++) {
            prev = current;
            current = current->next;
        }

        prev->next = current->next;

        return head;
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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *fast = head;
        while (n > 0 && fast != nullptr) {
            fast = fast->next;
            n--;
        }

        if (n > 0) {
            return nullptr;
        }

        if (fast == nullptr) {
            return head->next;
        }

        ListNode **slow = &head;
        while (fast != nullptr) {
            slow = &(*slow)->next;
            fast = fast->next;
        }

        *slow = (*slow)->next;
        return head;
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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *fast = head;
        while (n > 0) {
            fast = fast->next;
            n--;
        }

        if (fast == nullptr) {
            return head->next;
        }

        ListNode **slow = &head;
        while (fast != nullptr) {
            slow = &(*slow)->next;
            fast = fast->next;
        }

        *slow = (*slow)->next;
        return head;
    }
};