/*Given the root of a binary tree, invert the tree, and return its root.
Example 1:

Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]*/

TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return root;
        TreeNode* temp = invertTree(root->left);
        root->left = invertTree(root->right);
        root->right = temp;
        return root;
}
