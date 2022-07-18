/*Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

Example 1:
Input: root = [1,2,2,3,4,4,3]
Output: true

Example 2:
Input: root = [1,2,2,null,3,null,3]
Output: false
*/

    bool isSymmetric_util(TreeNode* left, TreeNode* right) {
        if (!left && !right) return true;
        if (!left || !right) return false;
        return (left->val == right->val) && isSymmetric_util(left->left, right->right) && isSymmetric_util(left->right, right->left);
    }
    bool isSymmetric(TreeNode* root) {
        //if (root == nullptr) return true;
        return isSymmetric_util(root->left, root->right);
    }
