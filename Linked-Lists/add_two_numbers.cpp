/*You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example 1:

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.*/

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;

        ListNode* curr1 = l1;
        ListNode* curr2 = l2;
        int size_ll1 = 0;
        int size_ll2 = 0;
        while(curr1 != nullptr) {
            size_ll1++;
            curr1=curr1->next;
        }
        while(curr2 != nullptr) {
            size_ll2++;
            curr2=curr2->next;
        }
        ListNode *curr;
        if (size_ll2 >= size_ll1) curr = l2;
        else curr = l1;
        
        curr1 = l1;
        curr2 = l2;
        ListNode *head = curr;
        ListNode *prev = nullptr;
        int carry = 0;
        int sum;
        while (curr1 != nullptr || curr2 != nullptr) {
            if (curr1 == nullptr) {
                sum = (curr2->val + carry)%10;
                carry = (curr2->val + carry)/10;
            }
            if (curr2 == nullptr) {
                sum = (curr1->val + carry)%10;
                carry = (curr1->val + carry)/10;
            } if (curr1 != nullptr && curr2 != nullptr) {
                sum = (curr1->val + curr2->val + carry)%10;
                carry = (curr1->val + curr2->val + carry)/10;
            }
            curr->val = sum;
            prev = curr;
            curr = curr->next;
            if (curr1 != nullptr) curr1 = curr1->next;
            if (curr2 != nullptr) curr2 = curr2->next;
            
        }
        if (carry != 0) {
            ListNode* temp = new ListNode(carry);
            prev->next = temp;
        }
        
        return head;
    }
