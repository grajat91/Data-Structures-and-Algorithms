/*Given a binary tree, determine if it is height-balanced.
For this problem, a height-balanced binary tree is defined as:
a binary tree in which the left and right subtrees of every node differ in height by no more than 1.

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: true*/

    int isBalancedUtil(TreeNode* root) {
        if (root == nullptr) return true;
        int lh = isBalancedUtil(root->left);
        if (lh == -1) return -1;
        int rh = isBalancedUtil(root->right);
        if (rh == -1) return -1;
        if (abs(lh - rh) > 1) return -1;
        else return (1+max(lh,rh));
    }
    
    bool isBalanced(TreeNode* root) {
        int res = isBalancedUtil(root);
        if (res == -1) return false;
        else return true;
    }
