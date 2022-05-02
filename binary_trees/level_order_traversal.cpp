/*Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]*/

vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) return result;
        vector<int> row;
        queue<TreeNode*> lotq;
        lotq.push(root);
        //TreeNode* curr = root;
        while(lotq.empty() == false) {
            int count = lotq.size();
            for (int i=0;i<count;i++) {
                TreeNode *curr = lotq.front();
                lotq.pop();
                row.push_back(curr->val);
                if (i==count-1) {
                    result.push_back(row);
                    row.clear();
                }
                if (curr->left != nullptr) {
                    lotq.push(curr->left);
                }
                if (curr->right != nullptr) {
                    lotq.push(curr->right);
                }
            }
        }
        return result;
}
