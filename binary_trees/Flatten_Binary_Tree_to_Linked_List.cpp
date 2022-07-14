/*Given the root of a binary tree, flatten the tree into a "linked list":
The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.

Example 1:
Input: root = [1,2,5,3,4,null,6]
Output: [1,null,2,null,3,null,4,null,5,null,6]

Example 2:
Input: root = []
Output: []

Example 3:
Input: root = [0]
Output: [0]*/

//Using O(n) space
    void preorder(TreeNode* root, vector<TreeNode*> &preorder_vector) {
        if (root != nullptr) {
            preorder_vector.push_back(root);
            preorder(root->left,preorder_vector);
            preorder(root->right,preorder_vector);
        }
    }
    
    void flatten(TreeNode* root) {
        if (root == nullptr || (!root->left && !root->right)) return;
        vector<TreeNode*> preorder_vector;
        preorder(root, preorder_vector);
        preorder_vector[0]->left = nullptr;
        for (int i=0;i<preorder_vector.size()-1;i++) {
            preorder_vector[i]->right = preorder_vector[i+1];
            preorder_vector[i+1]->left = nullptr;
        }
    }
