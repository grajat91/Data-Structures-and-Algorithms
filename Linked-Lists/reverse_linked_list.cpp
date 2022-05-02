/*Given the head of a singly linked list, reverse the list, and return the reversed list.
  
Example 1:
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]*/

ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* ahead = head->next;
        
        while(curr != nullptr) {
            curr->next = prev;
            prev = curr;
            curr = ahead;
            if (curr != nullptr) ahead = curr->next;
        }
        
        return prev;
}
