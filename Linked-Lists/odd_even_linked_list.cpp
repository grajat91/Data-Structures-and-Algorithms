/*Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.
The first node is considered odd, and the second node is even, and so on.
Note that the relative order inside both the even and odd groups should remain as it was in the input.
You must solve the problem in O(1) extra space complexity and O(n) time complexity.

Example 1:
Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]

Example 2:
Input: head = [2,1,3,5,6,4,7]
Output: [2,3,6,7,1,5,4]*/
*/
class Solution {
public:
    //O(N) space
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr) return head;
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* last;
        queue<ListNode*> evenq;
        int size = 1;
        while (curr->next != nullptr) {
            prev = curr;
            curr = curr->next;
            size++;
            if (size %2 == 0) evenq.push(curr);
        }
        if (size%2 == 0) last = prev;
        else last = curr;
        curr = head;
        while (curr->next != nullptr) {
            curr->next = curr->next->next;
            curr = curr->next;
            if (curr->next == nullptr || curr->next->next == nullptr) break; 
        }
        
        while (!evenq.empty()) {
            ListNode* top = evenq.front();
            evenq.pop();
            last->next = top;
            last = last->next;
        }
        
        last->next = nullptr;
        return head;
    }
    
    //O(1) space
        ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr) return head;
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* last;
        ListNode* last_even = nullptr;
        ListNode* even;
        int size = 1;
        while (curr->next != nullptr) {
            prev = curr;
            curr = curr->next;
            size++;
        }
        if (size%2 == 0) {
            last = prev;
            last_even = curr;
        }
        else last = curr;
        prev = last;
        curr = head;
        while (curr != prev) {
            even = curr->next; 
            last->next = even;
            last = last->next;
            curr->next = curr->next->next;
            curr = curr->next;
        }
        last->next = last_even;
        
        return head;
    }
};
