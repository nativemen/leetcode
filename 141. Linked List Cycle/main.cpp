#include <unordered_map>
#include <unordered_set>
#include <climits>

using std::unordered_map;
using std::unordered_set;

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
    bool hasCycle(ListNode *head) {
        while (head != nullptr) {
            if (head->val == INT_MAX) {
                return true;
            }

            head->val = INT_MAX;
            head = head->next;
        }

        return false;
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
    bool hasCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return true;
            }
        }

        return false;
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
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode *> set;

        while (head != nullptr) {
            if (set.find(head) != set.end()) {
                return true;
            }

            set.insert(head);
            head = head->next;
        }

        return false;
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
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode *> map;

        while (head != nullptr) {
            if (map.contains(head)) {
                return true;
            }

            map.insert(head);
            head = head->next;
        }

        return false;
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
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode *, int> map;

        while (head != nullptr) {
            if (map.find(head) != map.end()) {
                return true;
            }

            map[head] = 1;
            head = head->next;
        }

        return false;
    }
};