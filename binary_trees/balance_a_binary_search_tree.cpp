/*Given the root of a binary search tree, return a balanced binary search tree with the same node values. If there is more than one answer, return any of them.

A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.

 

Example 1:


Input: root = [1,null,2,null,3,null,4,null,null]
Output: [2,1,3,null,null,null,4]
Explanation: This is not the only correct answer, [3,1,4,null,2] is also correct.
Example 2:


Input: root = [2,1,3]
Output: [2,1,3]
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
1 <= Node.val <= 105
*/

    void inorder_arr(TreeNode* root,vector<int> &inorder) {
        if (root == nullptr) return;
        inorder_arr(root->left,inorder);
        inorder.push_back(root->val);
        inorder_arr(root->right,inorder);
    }
    TreeNode* bst_from_arr(vector<int> inorder, int left, int right) {
        if (left > right) return nullptr;
        int mid = (left+right)/2;
        TreeNode* root = new TreeNode(inorder[mid]);
        root->left = bst_from_arr(inorder,left,mid-1);
        root->right = bst_from_arr(inorder,mid+1,right);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorder;
        inorder_arr(root,inorder);
        return bst_from_arr(inorder,0,inorder.size()-1);
    }
