#include <algorithm>
#include <vector>

using std::vector;

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
    bool isPalindrome(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        if (fast != nullptr) {
            slow = slow->next;
        }

        ListNode *prev = nullptr;
        ListNode *cur = slow;
        while (cur != nullptr) {
            ListNode *temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }

        while (prev != nullptr) {
            if (prev->val != head->val) {
                return false;
            }

            prev = prev->next;
            head = head->next;
        }

        return true;
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
    bool isPalindrome(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = nullptr;

        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            ListNode *temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }

        if (fast != nullptr) {
            slow = slow->next;
        }

        while (prev != nullptr) {
            if (prev->val != slow->val) {
                return false;
            }

            prev = prev->next;
            slow = slow->next;
        }

        return true;
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
    bool isPalindrome(ListNode *head) {
        vector<int> vec;

        while (head != nullptr) {
            vec.push_back(head->val);
            head = head->next;
        }

        size_t size = vec.size();
        for (size_t i = 0; i < size / 2; i++) {
            if (vec[i] != vec[size - 1 - i]) {
                return false;
            }
        }

        return true;
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
    bool isPalindrome(ListNode *head) {
        vector<int> vec;

        while (head != nullptr) {
            vec.push_back(head->val);
            head = head->next;
        }

        size_t left = 0;
        size_t right = vec.size() - 1;
        while (left < right) {
            if (vec[left] != vec[right]) {
                return false;
            }
            left++;
            right--;
        }

        return true;
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
    ListNode *findSecondList(ListNode *list) {
        ListNode *slow = list;
        ListNode *fast = list;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        if (fast != nullptr) {
            slow = slow->next;
        }

        return slow;
    }

    ListNode *reverseList(ListNode *list) {
        ListNode *prev = nullptr;
        ListNode *cur = list;
        while (cur != nullptr) {
            ListNode *temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }

        return prev;
    }

    bool compareLists(ListNode *firstList, ListNode *secondList) {
        while (secondList != nullptr) {
            if (secondList->val != firstList->val) {
                return false;
            }

            secondList = secondList->next;
            firstList = firstList->next;
        }

        return true;
    }

    bool isPalindrome(ListNode *head) {
        ListNode *secondList = findSecondList(head);
        ListNode *secondHead = reverseList(secondList);

        return compareLists(head, secondHead);
    }
};