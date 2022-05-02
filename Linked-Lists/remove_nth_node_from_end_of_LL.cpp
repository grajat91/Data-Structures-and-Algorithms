/*Given the head of a linked list, remove the nth node from the end of the list and return its head.
  
Example 1:
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]*/

ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* ahead = head;
        ListNode* behind = head;
        ListNode* behindprev =nullptr;
        if (head -> next == nullptr && n==1) {
            delete head;
            return nullptr;
        } 
        for (int i=0;i<n;i++) {
            if (ahead != nullptr) {
                ahead = ahead -> next;
            }
        }
        while (ahead != nullptr) {
            ahead = ahead -> next;
            behindprev = behind;
            behind = behind -> next;
        }
        if (behind == head) {
            behind = head->next;
            delete(head);
            return behind;
        }
        behindprev -> next = behind->next;
        delete(behind);
        return head;
}
