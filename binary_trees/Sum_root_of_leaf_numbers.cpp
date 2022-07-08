/*You are given the root of a binary tree containing digits from 0 to 9 only.
Each root-to-leaf path in the tree represents a number.
For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
Return the total sum of all root-to-leaf numbers. Test cases are generated so that the answer will fit in a 32-bit integer.
A leaf node is a node with no children.

Example 1:
Input: root = [1,2,3]
Output: 25
Explanation:
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.
Therefore, sum = 12 + 13 = 25.

Example 2:
Input: root = [4,9,0,5,1]
Output: 1026
Explanation:
The root-to-leaf path 4->9->5 represents the number 495.
The root-to-leaf path 4->9->1 represents the number 491.
The root-to-leaf path 4->0 represents the number 40.
Therefore, sum = 495 + 491 + 40 = 1026.*/

//BFS based solution
    int sumNumbers(TreeNode* root) {
        if (root == nullptr) return 0;
        if (root->left == nullptr && root->right == nullptr) return root->val;
        vector<int> tree_vect;
        queue<pair<TreeNode*, int>> bfsq;
        bfsq.push({root,root->val});
        
        while (!bfsq.empty()) {
            int count = bfsq.size();
            for (int i=0;i<count;i++) {
                TreeNode* x = bfsq.front().first;
                int y = bfsq.front().second;
                bfsq.pop();
                if (x->left && x->right) {
                    bfsq.push({x->left,10*y+x->left->val});
                    bfsq.push({x->right,10*y+x->right->val});
                } else if (x->left && !x->right) {
                    bfsq.push({x->left,10*y+x->left->val});
                } else if (!x->left && x->right) {
                    bfsq.push({x->right,10*y+x->right->val});
                } else {
                    tree_vect.push_back(y);
                }
                
            }
        }
        return accumulate(tree_vect.begin(),tree_vect.end(),0);
    }

//DFS based solution
    int sumNumbers_util(TreeNode* root, int curr) {
        if (!root) return 0;
        curr = curr*10 + root->val;
        if (!root->left && !root->right) return curr;
        return sumNumbers_util(root->left, curr) + sumNumbers_util(root->right, curr);
    }
    int sumNumbers(TreeNode* root) {
        return sumNumbers_util(root,0);
    }
