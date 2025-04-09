#include <algorithm>
#include <vector>

using namespace std;

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
    void reverse(vector<int> &values, int left, int right) {
        while (left < right) {
            swap(values[left++], values[right--]);
        }
    }

public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        vector<int> values;
        ListNode *node = head;

        while (node) {
            values.push_back(node->val);
            node = node->next;
        }

        int size = values.size();

        for (int i = 0; i + k <= size; i += k) {
            reverse(values, i, i + k - 1);
        }

        node = head;
        for (int i = 0; i < size; i++) {
            node->val = values[i];
            node = node->next;
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
    ListNode **reverseList(ListNode **head, int k) {
        int count = 0;
        ListNode *current = *head;
        ListNode *prev = NULL;
        ListNode *next = NULL;

        while (current) {
            next = current->next;
            current->next = prev;
            prev = current;
            count++;
            if (count >= k) {
                break;
            }
            current = next;
        }

        ListNode *tail = *head;
        tail->next = next;
        *head = current;

        return &tail->next;
    }

public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        int count = 0;
        ListNode *node = head;

        while (node) {
            count++;
            node = node->next;
        }

        ListNode **current = &head;

        while (*current) {
            if (count < k) {
                break;
            }

            current = reverseList(current, k);
            count -= k;
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
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (!head || k <= 1) {
            return head;
        }

        ListNode *node = head;

        for (int i = 0; i < k; i++) {
            if (!node) {
                return head;
            }
            node = node->next;
        }

        ListNode *current = head;
        ListNode *prev = NULL;
        ListNode *next = NULL;
        int count = 0;

        while (current && count < k) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
            count++;
        }

        if (next) {
            head->next = reverseKGroup(next, k);
        }

        return prev;
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
    ListNode *getKth(ListNode *node, int k) {
        while (node && k > 0) {
            node = node->next;
            k--;
        }

        return node;
    }

public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode dummy = {0, head};
        ListNode *groupPrev = &dummy;

        while (true) {
            ListNode *kth = getKth(groupPrev, k);
            if (!kth) {
                break;
            }

            ListNode *groupNext = kth->next;
            ListNode *prev = kth->next;
            ListNode *current = groupPrev->next;

            while (current != groupNext) {
                ListNode *next = current->next;
                current->next = prev;
                prev = current;
                current = next;
            }

            ListNode *temp = groupPrev->next;
            groupPrev->next = kth;
            groupPrev = temp;
        }

        return dummy.next;
    }
};
