/*Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]

Example 2:
Input: root = [1]
Output: [[1]]

Example 3:
Input: root = []
Output: []*/

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) return result;
        queue<TreeNode*> bfsq;
        stack<int> s;
        bfsq.push(root);
        bool reverse = false;
        while (!bfsq.empty()) {
            int count = bfsq.size();
            vector<int> row;
            row.clear();
            for (int i=0;i<count;i++) {
                TreeNode* front = bfsq.front();
                bfsq.pop();
                if (!reverse) {
                    row.push_back(front->val);
                } else {
                    s.push(front->val);
                }
                if (front->left) bfsq.push(front->left);
                if (front->right) bfsq.push(front->right);
            }
            if (!reverse) {
                result.push_back(row);
                //reverse = true;
            }
            if (reverse) {
                while(!s.empty()) {
                    row.push_back(s.top());
                    s.pop();
                }
                result.push_back(row);
                //reverse = false;
            }
            reverse = !reverse;
        }
        return result;
    }
