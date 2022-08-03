/*Given the root of a binary tree, return the bottom-up level order traversal of its nodes' values. (i.e., from left to right, level by level from leaf to root).

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[15,7],[9,20],[3]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []*/

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> bfsq;
        vector<int>level;
        vector<vector<int>> result;
        if (root == nullptr) return result;
        bfsq.push(root);
        while (!bfsq.empty()) {
            int count = bfsq.size();
            for (int i=0;i<count;i++) {
                TreeNode* q_top = bfsq.front();
                bfsq.pop();
                level.push_back(q_top->val);
                if (q_top->left) bfsq.push(q_top->left);
                if (q_top->right) bfsq.push(q_top->right);
            }
            result.push_back(level);
            level.clear();
        }
        reverse(result.begin(),result.end());
        return result;
    }
