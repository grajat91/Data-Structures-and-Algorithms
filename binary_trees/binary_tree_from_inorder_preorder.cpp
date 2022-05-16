/*Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

Example 1:
Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
*/

    int preindex = 0;
    TreeNode* buildTree_util(vector<int>& preorder, vector<int>& inorder, int begin, int end) {
        if (begin > end) return nullptr;
        int pivot;
        TreeNode* root = new TreeNode(preorder[preindex++]);
        for (int i=begin;i<=end;i++) {
            if (inorder[i] == root->val) {
                pivot = i;
                break;
            }
        }
        
        root->left = buildTree_util(preorder, inorder, begin, pivot-1);
        root->right = buildTree_util(preorder, inorder, pivot+1, end);
        return root;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root = buildTree_util(preorder, inorder, 0, preorder.size()-1);
        return root;
    }
