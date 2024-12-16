struct ListNode {
    int val;
    struct ListNode *next;
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *middleNode(struct ListNode *head) {
    struct ListNode *middle = head;
    struct ListNode *end = head;
    while (end != NULL && end->next != NULL) {
        middle = middle->next;
        end = end->next->next;
    }

    return middle;
}