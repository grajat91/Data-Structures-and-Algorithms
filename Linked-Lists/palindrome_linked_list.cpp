/*Given the head of a singly linked list, return true if it is a palindrome.

Example 1:
Input: head = [1,2,2,1]
Output: true

Example 2:
Input: head = [1,2]
Output: false*/

    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return true; 
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* curr = head;
        int size = 0;
        while (curr != nullptr) {
            size++;
            curr = curr->next;
        }
        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        curr = head;
        ListNode *prev = nullptr;
        ListNode *ahead = head->next;
        while (curr != slow) {
            curr->next = prev;
            prev = curr;
            curr = ahead;
            ahead = curr->next;
        }
        if (size%2 == 0) ahead = curr;
        
        while (prev != nullptr && ahead != nullptr) {
            if (prev->val == ahead->val) {
                prev = prev->next;
                ahead = ahead->next;
            } else {
                return false;
            }
        }
        return true;
    }
