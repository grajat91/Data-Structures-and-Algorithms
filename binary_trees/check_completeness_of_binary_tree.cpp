/*Given the root of a binary tree, determine if it is a complete binary tree.

In a complete binary tree, every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Example 1:

Input: root = [1,2,3,4,5,6]
Output: true
Explanation: Every level before the last is full (ie. levels with node-values {1} and {2, 3}), and all nodes in the last level ({4, 5, 6}) are as far left as possible.

Example 2:
Input: root = [1,2,3,4,5,null,7]
Output: false
Explanation: The node with value 7 isn't as far left as possible.
 

Constraints:

The number of nodes in the tree is in the range [1, 100].
1 <= Node.val <= 1000*/
//BFS based solution
    bool isCompleteTree(TreeNode* root) {
        if (!root) return true;
        queue<TreeNode*> bfsq;
        bool tree_end=false;
        bfsq.push(root);
        while (!bfsq.empty()) {
            TreeNode* front_elem = bfsq.front();
            bfsq.pop();
            if (!front_elem) tree_end = true;
            else {
                if (tree_end) return false;
                bfsq.push(front_elem->left);
                bfsq.push(front_elem->right);
            }
        }
        return true;
    }

//DFS based solution
    int isCompleteTree_util(TreeNode* root) {
        if (root == nullptr) return 0;
        int l = isCompleteTree_util(root->left);
        int r = isCompleteTree_util(root->right);
        if ((l&(l+1)) == 0 && (l/2<=r && r<=l)) return l+r+1;
        if ((r&(r+1)) == 0 && (r<=l && l<=(2*r+1))) return l+r+1;
        //if ((l & (l + 1)) == 0 && l / 2 <= r && r <= l) return l+r+1;
        //if ((r & (r + 1)) == 0 && r <= l && l <= r * 2 + 1) return l+r+1;
        return -1;
    }
    bool isCompleteTree(TreeNode* root) {
        return isCompleteTree_util(root)>=0;
    }
