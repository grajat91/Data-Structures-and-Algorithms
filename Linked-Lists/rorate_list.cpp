/*
Given the head of a linked list, rotate the list to the right by k places.

Example 1:
Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]

Example 2:

Input: head = [0,1,2], k = 4
Output: [2,0,1]
*/

    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k==0) return head;
        int n = 1;
        ListNode* curr = head;
        while (curr->next != nullptr) {
            n++;
            curr = curr->next;
        }
        k = k%n;
        k=n-k;
        curr->next = head;
        while (k) {
            curr = curr->next;
            k--;
        }
        head = curr->next;
        curr->next = nullptr;
        return head;
    }
