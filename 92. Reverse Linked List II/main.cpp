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

#define ARRAY_SIZE 500

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
    ListNode *reverseBetween(ListNode *head, int left, int right) {
        int index = 0;
        int values[ARRAY_SIZE] = {0};
        ListNode *node = head;

        while (node != nullptr) {
            values[index] = node->val;
            index++;
            node = node->next;
        }

        for (int i = left - 1; i < (left + right) / 2; i++) {
            int temp = values[i];
            values[i] = values[left + right - 2 - i];
            values[left + right - 2 - i] = temp;
        }

        node = head;
        index = 0;
        while (node != nullptr) {
            node->val = values[index];
            index++;
            node = node->next;
        }

        return head;
    }
};

static ListNode *reverse(ListNode *leftNode, ListNode *rightNode) {
    ListNode *prev = nullptr;
    ListNode *current = leftNode;
    ListNode *next = nullptr;

    while (current != rightNode) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    current->next = prev;

    return current;
}

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
    ListNode *reverseBetween(ListNode *head, int left, int right) {
        ListNode *leftPrev = nullptr;
        ListNode *node = head;
        for (int i = 1; i < left; i++) {
            leftPrev = node;
            node = node->next;
        }

        ListNode *leftNode = node;
        for (int i = left; i < right; i++) {
            node = node->next;
        }

        ListNode *rightNode = node;
        ListNode *rightNext = node->next;
        if (leftPrev == nullptr) {
            head = reverse(leftNode, rightNode);
        } else {
            leftPrev->next = reverse(leftNode, rightNode);
        }

        leftNode->next = rightNext;

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
    ListNode *reverseBetween(ListNode *head, int left, int right) {
        vector<ListNode *> list;
        ListNode *node = head;

        while (node != nullptr) {
            list.push_back(node);
            node = node->next;
        }

        for (int i = left - 1; i < (left + right) / 2; i++) {
            ListNode *temp = list[i];
            list[i] = list[left + right - 2 - i];
            list[left + right - 2 - i] = temp;
        }

        int size = list.size();
        for (int i = 0; i < size - 1; i++) {
            list[i]->next = list[i + 1];
        }

        list[size - 1]->next = nullptr;

        return list[0];
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
    ListNode *reverseBetween(ListNode *head, int left, int right) {
        ListNode dummy = ListNode{0, head};
        ListNode *leftPrev = nullptr;
        ListNode *leftNode = &dummy;

        for (int i = 0; i < left; i++) {
            leftPrev = leftNode;
            leftNode = leftNode->next;
        }

        ListNode *prev = nullptr;
        ListNode *current = leftNode;
        ListNode *next = nullptr;
        for (int i = left - 1; i < right; i++) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        leftPrev->next = prev;
        leftNode->next = current;

        return dummy.next;
    }
};