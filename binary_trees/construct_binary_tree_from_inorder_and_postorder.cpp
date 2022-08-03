/*Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

Example 1:


Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: inorder = [-1], postorder = [-1]
Output: [-1]*/

    unordered_map<int,int> inorder_index_map;
    TreeNode* buildTree_util(vector<int>& inorder, vector<int>& postorder, int begin, int end, int &postindex) {
        if (begin>end) return nullptr;
        int pivot;
        TreeNode* root = new TreeNode(postorder[postindex]);
        postindex--;
        pivot = inorder_index_map[root->val];
        root->right = buildTree_util(inorder,postorder,pivot+1,end,postindex);
        root->left = buildTree_util(inorder,postorder,begin,pivot-1, postindex);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        for (int i=0;i<inorder.size();i++) {
            inorder_index_map[inorder[i]] = i;
        }
        
        int postindex = postorder.size()-1;
        TreeNode* root = buildTree_util(inorder,postorder,0,postorder.size()-1,postindex);
        return root;
    }
