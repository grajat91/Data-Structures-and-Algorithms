/*Given the root of a complete binary tree, return the number of the nodes in the tree.
According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
Design an algorithm that runs in less than O(n) time complexity.

Example 1:
Input: root = [1,2,3,4,5,6]
Output: 6*/

    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        int left_height = 0;
        int right_height = 0;
        TreeNode* root_left = root;
        TreeNode* root_right = root;
        while (root_left) {
            left_height++;
            root_left = root_left->left;
        }
        while (root_right) {
            right_height++;
            root_right = root_right->right;
        }
        if (left_height == right_height) return pow(2,left_height)-1;
        return 1+countNodes(root->left) + countNodes(root->right);
    }
