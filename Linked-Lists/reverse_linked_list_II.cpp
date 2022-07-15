/*Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

Example 1:
Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]

Example 2:
Input: head = [5], left = 1, right = 1
Output: [5]*/

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode *prev = nullptr;
        ListNode *curr = head;
        ListNode *ahead = head->next;
        ListNode *left_prev = nullptr;
        ListNode *leftp = nullptr;
        ListNode *right_next = nullptr;
        ListNode *rightp = nullptr;
        int iter = 1;
        while (curr != nullptr) {
            if (iter>=left && iter<=right) {
                if (iter == left) {
                    if (left != 1) left_prev = prev;
                    
                    leftp = curr;
                }
                if (iter == right) {
                    right_next = ahead;
                    rightp = curr;
                }
                curr->next = prev;
                prev = curr;
                curr = ahead;
                if (curr != nullptr) ahead = curr->next;
            } else {
                prev = curr;
                curr=ahead;
                if (curr != nullptr) ahead = curr->next;
            }
            iter++;
        }
        leftp->next = right_next;
        if (left != 1) left_prev->next = rightp;
        
        return left==1?rightp:head;
        
    }
