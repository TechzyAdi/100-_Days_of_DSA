/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* insertionSortList(struct ListNode* head) {
    if (!head) return NULL;

    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = NULL;

    struct ListNode* curr = head;

    while (curr != NULL) {
        struct ListNode* next = curr->next;

        // Find position in sorted list
        struct ListNode* prev = dummy;
        while (prev->next != NULL && prev->next->val < curr->val) {
            prev = prev->next;
        }

        // Insert current node
        curr->next = prev->next;
        prev->next = curr;

        curr = next;
    }

    return dummy->next;
}