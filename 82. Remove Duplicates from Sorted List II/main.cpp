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
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode **prev = &head;
        ListNode *current = head->next;

        while (current) {
            if ((*prev)->val == current->val) {
                if (!current->next) {
                    *prev = nullptr;
                    current = nullptr;
                    continue;
                } else if (current->val != current->next->val) {
                    *prev = current->next;
                    current = current->next->next;
                    continue;
                }
            } else {
                prev = &(*prev)->next;
            }

            current = current->next;
        }

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
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode **current = &head;

        while (*current) {
            if ((*current)->next && (*current)->val == (*current)->next->val) {
                int val = (*current)->val;

                while (*current && val == (*current)->val) {
                    *current = (*current)->next;
                }
            } else {
                current = &(*current)->next;
            }
        }

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
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode *dummy = new ListNode(0, head);
        struct ListNode *current = head;
        struct ListNode *prev = dummy;

        while (current) {
            if (current->next && current->val == current->next->val) {
                while (current->next && current->val == current->next->val) {
                    current = current->next;
                }
                prev->next = current->next;
            } else {
                prev = current;
            }

            current = current->next;
        }

        return dummy->next;
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
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head || !head->next) {
            return head;
        }

        if (head->val != head->next->val) {
            head->next = deleteDuplicates(head->next);
            return head;
        }

        while (head->next && head->val == head->next->val) {
            head = head->next;
        }

        return deleteDuplicates(head->next);
    }
};