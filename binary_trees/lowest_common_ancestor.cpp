/*Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.
According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

Example 1:
Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
Output: 6
Explanation: The LCA of nodes 2 and 8 is 6.*/

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return NULL;
        if (root == p || root == q) return root;
        TreeNode* lca1 = lowestCommonAncestor(root->left,p,q);
        TreeNode* lca2 = lowestCommonAncestor(root->right,p,q);
        if (lca1 != NULL && lca2 != NULL) return root;
        if (lca1 != NULL) return lca1;
        else return lca2;
}
