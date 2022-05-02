/*Given the root of a binary tree, determine if it is a valid binary search tree (BST).
A valid BST is defined as follows:
The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 
Example 1:
Input: root = [2,1,3]
Output: true*/

bool isValidBSTUtil(TreeNode* root, long left_range, long right_range) {
        if (root == nullptr) return true;
        return ((root->val > left_range && root->val < right_range) && isValidBSTUtil(root->left, left_range, root->val) && isValidBSTUtil(root->right, root->val, right_range));
}
    
bool isValidBST(TreeNode* root) {
        if (root == nullptr) return true;
        if (root->left == nullptr && root->right == nullptr) return true;
        return isValidBSTUtil(root, LONG_MIN, LONG_MAX);
}
