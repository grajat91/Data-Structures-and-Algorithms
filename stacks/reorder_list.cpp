/*You are given the head of a singly linked-list. The list can be represented as:
L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:
L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.

Example 1:
Input: head = [1,2,3,4]
Output: [1,4,2,3]*/

    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return;
        stack <ListNode*> node_stack;
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        while (slow != nullptr) {
            node_stack.push(slow);
            slow = slow->next;
        }
        
        ListNode* curr = head;
        ListNode* ahead;
        while (curr != nullptr && !node_stack.empty()) {
            ahead = curr->next;
            curr->next = node_stack.top();
            if (node_stack.size() > 1) {
                node_stack.top()->next = ahead;
                curr = ahead;
            } else {
                node_stack.top()->next = nullptr;
            }
            node_stack.pop();
        }  
    }
