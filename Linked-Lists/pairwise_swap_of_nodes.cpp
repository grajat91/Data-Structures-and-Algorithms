/*Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

Example 1:


Input: head = [1,2,3,4]
Output: [2,1,4,3]
Example 2:

Input: head = []
Output: []
Example 3:

Input: head = [1]
Output: [1]*/

    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* prev1 = nullptr;
        ListNode* ahead = curr->next;
        ListNode* new_head;
        int size = 1;
        while (curr != nullptr) {
            if(size%2 == 0) {
                curr->next = prev;
                prev->next = ahead;
                if (prev1 != nullptr) prev1->next = curr;
                prev1  = prev;
                prev = curr;
                if (size == 2) new_head = prev;
                curr = ahead;
                prev1->next = curr;
                if (curr != nullptr) ahead = curr->next;
                size++;
            } else {
                //prev1 = prev;
                prev = curr;
                curr = ahead;
                if (curr != nullptr) ahead = curr->next;
                size++;
            }
        }
        return new_head;
    }
