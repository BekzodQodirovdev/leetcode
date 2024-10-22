/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* dummy_head = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy_head->val = 0;
    dummy_head->next = NULL;

    struct ListNode* current = dummy_head;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry) {
        int val1 = (l1 != NULL) ? l1->val : 0; 
        int val2 = (l2 != NULL) ? l2->val : 0; 

        int total = val1 + val2 + carry;
        carry = total / 10; 
        current->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        current->next->val = total % 10;
        current->next->next = NULL;

        current = current->next;
        if (l1 != NULL) l1 = l1->next; 
        if (l2 != NULL) l2 = l2->next;
    }

    struct ListNode* result = dummy_head->next;
    free(dummy_head);
    return result;
}

// 100% 