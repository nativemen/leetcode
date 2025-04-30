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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        if (!list1) {
            return list2;
        }

        if (!list2) {
            return list1;
        }

        if (list1->val < list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        } else {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }

public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.empty()) {
            return nullptr;
        }

        if (lists.size() == 1) {
            return lists[0];
        }

        lists[1] = mergeTwoLists(lists[0], lists[1]);
        lists.erase(lists.begin());
        return mergeKLists(lists);
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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        ListNode dummy;
        ListNode *current = &dummy;

        while (list1 && list2) {
            if (list1->val < list2->val) {
                current->next = list1;
                list1 = list1->next;
            } else {
                current->next = list2;
                list2 = list2->next;
            }
            current = current->next;
        }

        current->next = list1 ? list1 : list2;

        return dummy.next;
    }

public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.empty()) {
            return nullptr;
        }

        if (lists.size() == 1) {
            return lists[0];
        }

        lists[1] = mergeTwoLists(lists[0], lists[1]);
        lists.erase(lists.begin());
        return mergeKLists(lists);
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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        ListNode dummy;
        ListNode *current = &dummy;

        while (list1 && list2) {
            if (list1->val < list2->val) {
                current->next = list1;
                list1 = list1->next;
            } else {
                current->next = list2;
                list2 = list2->next;
            }
            current = current->next;
        }

        current->next = list1 ? list1 : list2;

        return dummy.next;
    }

    ListNode *mergeKListsHelper(vector<ListNode *> &lists, int left, int right) {
        if (left > right) {
            return NULL;
        }

        if (left == right) {
            return lists[left];
        }

        int mid = (left + right) / 2;
        ListNode *leftList = mergeKListsHelper(lists, left, mid);
        ListNode *rightList = mergeKListsHelper(lists, mid + 1, right);

        return mergeTwoLists(leftList, rightList);
    }

public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        return mergeKListsHelper(lists, 0, lists.size() - 1);
    }
};