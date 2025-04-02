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
    ListNode *rotateRight(ListNode *head, int k) {
        if (!head || !head->next || k == 0) {
            return head;
        }

        int count = 1;
        ListNode *node = head;

        while (node->next) {
            node = node->next;
            count++;
        }

        node->next = head;
        int offset = count - (k % count);
        node = head;

        for (int i = 1; i < offset; i++) {
            node = node->next;
        }

        head = node->next;
        node->next = nullptr;

        return head;
    }
};