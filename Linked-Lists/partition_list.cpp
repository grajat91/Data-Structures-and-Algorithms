/*
Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
You should preserve the original relative order of the nodes in each of the two partitions.
Example 1:


Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]
Example 2:

Input: head = [2,1], x = 2
Output: [1,2]
*/

    ListNode* partition(ListNode* head, int x) {
        ListNode* ls = nullptr;
        ListNode* le = nullptr;
        ListNode* gs = nullptr;
        ListNode* ge = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            if (curr->val < x) {
                if (!ls) {
                    ls = curr;
                    le = ls;
                } else {
                    le->next = curr;
                    le = le->next;
                }
            } else {
                if (!gs) {
                    gs = curr;
                    ge = gs;
                } else {
                    ge->next = curr;
                    ge = ge->next;
                }
            }
            curr = curr->next;
        }
        if (!ls || !gs) return head;
        le->next = gs;
        ge->next = nullptr;
        return ls;
    }
