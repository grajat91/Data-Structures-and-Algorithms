/*You are given the heads of two sorted linked lists list1 and list2.
Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.
Return the head of the merged linked list.

Example 1:
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
*/

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list2 == nullptr) return list1;
        if (list1 == nullptr) return list2;
        
        ListNode *head = nullptr;
        ListNode *tail = nullptr;
        if (list1->val<=list2->val) {
            head = tail = list1;
            list1 = list1->next;
        } else {
            head = tail = list2;
            list2 = list2->next;
        }
        
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                tail->next = list1;
                tail = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                tail = list2;
                list2 = list2->next;
            }
        }
        
        if(list1 == nullptr) {
            tail->next = list2;
            tail = list2;
        }
        if(list2 == nullptr) {
            tail->next = list1;
            tail = list1;
        }
        return head;
    }
