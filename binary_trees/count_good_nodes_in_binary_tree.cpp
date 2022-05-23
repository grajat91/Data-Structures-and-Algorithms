/*Given a binary tree root, a node X in the tree is named good if in the path from root to X there are no nodes with a value greater than X.
Return the number of good nodes in the binary tree.

Example 1:
Input: root = [3,1,4,3,null,1,5]
Output: 4
Explanation: Nodes in blue are good.
Root Node (3) is always a good node.
Node 4 -> (3,4) is the maximum value in the path starting from the root.
Node 5 -> (3,4,5) is the maximum value in the path
Node 3 -> (3,1,3) is the maximum value in the path.*/

    void goodNodesUtil(TreeNode* root, int key, int &count) {
        if (root->left) {
            if(root->left->val >= key) {
                count++;
                goodNodesUtil(root->left, root->left->val, count);
            } else {
                goodNodesUtil(root->left,key, count);
            }
        }
        
        if (root->right) {
            if(root->right->val >= key) {
                count++;
                goodNodesUtil(root->right, root->right->val, count);
            } else {
                goodNodesUtil(root->right,key, count);
            }
        }
    }
    int goodNodes(TreeNode* root) {
        int count = 1;
        goodNodesUtil(root, root->val, count);
        return count;
    }
