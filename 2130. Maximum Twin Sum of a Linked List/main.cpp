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
public:
    int pairSum(ListNode *head) {
        vector<int> array;

        ListNode *node = head;

        while (node) {
            array.push_back(node->val);
            node = node->next;
        }

        int left = 0;
        int right = array.size() - 1;
        int maxSum = 0;

        while (left < right) {
            int sum = array[left] + array[right];
            maxSum = max(maxSum, sum);

            left++;
            right--;
        }

        return maxSum;
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
    int pairSum(ListNode *head) {
        int count = 0;
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast && fast->next) {
            count++;
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *prev = NULL;
        ListNode *next = NULL;

        while (slow != NULL) {
            next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }

        ListNode *node1 = head;
        ListNode *node2 = prev;
        int maxSum = 0;

        for (int i = 0; i < count; i++) {
            int sum = node1->val + node2->val;

            maxSum = max(maxSum, sum);
            node1 = node1->next;
            node2 = node2->next;
        }

        return maxSum;
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
    int pairSum(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *prev = NULL;
        ListNode *next = NULL;

        while (slow != NULL) {
            next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }

        ListNode *node1 = head;
        ListNode *node2 = prev;
        int maxSum = 0;

        while (node2 != NULL) {
            int sum = node1->val + node2->val;

            maxSum = max(maxSum, sum);
            node1 = node1->next;
            node2 = node2->next;
        }

        return maxSum;
    }
};