/*A binary tree is named Even-Odd if it meets the following conditions:
The root of the binary tree is at level index 0, its children are at level index 1, their children are at level index 2, etc.
For every even-indexed level, all nodes at the level have odd integer values in strictly increasing order (from left to right).
For every odd-indexed level, all nodes at the level have even integer values in strictly decreasing order (from left to right).
Given the root of a binary tree, return true if the binary tree is Even-Odd, otherwise return false.

Example 1:
Input: root = [1,10,4,3,null,7,9,12,8,6,null,null,2]
Output: true
Explanation: The node values on each level are:
Level 0: [1]
Level 1: [10,4]
Level 2: [3,7,9]
Level 3: [12,8,6,2]
Since levels 0 and 2 are all odd and increasing and levels 1 and 3 are all even and decreasing, the tree is Even-Odd.*/

    bool isEvenOddTree(TreeNode* root) {
        
        queue<TreeNode*> lvtq;
        int level = 0;
        lvtq.push(root);
        while (lvtq.empty() == false) {
            int count = lvtq.size();
            for (int i=0;i<count;i++) {
                TreeNode* front_elem = lvtq.front();
                lvtq.pop();
                if (level % 2 == 0) {
                    if (front_elem->val % 2 == 0) return false;
                    if (count>1 && i < count-1) {
                        if ( front_elem->val >= lvtq.front()->val) return false;
                    }
                } else {
                    if (front_elem->val % 2 != 0) return false;
                    if (count>1 && i < count-1) {
                        if (front_elem->val <= lvtq.front()->val) return false;
                    }
                }
                if (front_elem->left != nullptr) lvtq.push(front_elem->left);
                if (front_elem->right != nullptr) lvtq.push(front_elem->right);
            }
            level++;
        }
        return true;
    }
