/*You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

 

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []*/

    struct compare {
        bool operator()(const ListNode*curr1, const ListNode* curr2) {
            return curr1->val > curr2->val;
        }
    };

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        
        int k = lists.size();
        
        for (auto elem : lists) {
            if (elem) pq.push(elem);
        }
        if (pq.empty()) return nullptr;
        
        ListNode* newhead = pq.top();
        pq.pop();
        if (newhead->next) pq.push(newhead->next);
        ListNode* tail = newhead;
        while (!pq.empty()) {
            tail->next = pq.top();
            pq.pop();
            tail=tail->next;
            if (tail->next) pq.push(tail->next);
        }
        return newhead;
    }
};
