/*Description
Given a binary search tree (See Definition) and a node in it, find the in-order successor of that node in the BST.
If the given node has no in-order successor in the tree, return null.
It's guaranteed p is one node in the given tree. (You can directly compare the memory address to find p)
Example

Example 1:

Input: {1,#,2}, node with value 1
Output: 2
Explanation:
  1
   \
    2
Example 2:

Input: {2,1,3}, node with value 1
Output: 2
Explanation: 
    2
   / \
  1   3*/

    TreeNode *successor(TreeNode *root) {
        root = root->right;
        while (root != NULL && root->left != NULL) {
            root = root->left;
        }
        return root;
    }
    TreeNode *prev = NULL;
    TreeNode * inorderSuccessor(TreeNode * root, TreeNode * p) {
        if (root == NULL) return NULL;
        if (root->val > p->val) {
            prev = root;
            return inorderSuccessor(root->left, p);
        } else if(root->val < p->val) {
            return inorderSuccessor(root->right,p);
        } else {
            if (root->right == NULL && prev) return prev;
            else return successor(root);
        }
        return NULL;
    }
