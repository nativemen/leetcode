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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode **head1 = &l1;
        ListNode **head2 = &l2;
        int carry = 0;
        int count1 = 0;
        int count2 = 0;

        while (*head1 != nullptr || *head2 != nullptr) {
            int num1 = (*head1 != nullptr) ? (*head1)->val : 0;
            int num2 = (*head2 != nullptr) ? (*head2)->val : 0;
            int sum = num1 + num2 + carry;

            carry = sum / 10;
            if (*head1 != nullptr) {
                count1++;
                (*head1)->val = sum % 10;
                head1 = &(*head1)->next;
            }

            if (*head2 != nullptr) {
                count2++;
                (*head2)->val = sum % 10;
                head2 = &(*head2)->next;
            }
        }

        if (count1 > count2) {
            if (carry != 0) {
                *head1 = new ListNode(carry);
            }
            return l1;
        } else {
            if (carry != 0) {
                *head2 = new ListNode(carry);
            }
            return l2;
        }
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode dummyNode;
        ListNode *currentNode = &dummyNode;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int num1 = (l1 != nullptr) ? l1->val : 0;
            int num2 = (l2 != nullptr) ? l2->val : 0;
            int sum = num1 + num2 + carry;

            carry = sum / 10;
            currentNode->next = new ListNode(sum % 10);
            currentNode = currentNode->next;

            if (l1 != nullptr) {
                l1 = l1->next;
            }

            if (l2 != nullptr) {
                l2 = l2->next;
            }
        }

        return dummyNode.next;
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode dummyNode;
        ListNode *currentNode = &dummyNode;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry;

            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;
            currentNode->next = new ListNode(sum % 10);
            currentNode = currentNode->next;
        }

        return dummyNode.next;
    }
};