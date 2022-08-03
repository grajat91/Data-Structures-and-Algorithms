/*Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.
Given target value is a floating point.
You are guaranteed to have only one unique value in the BST that is closest to the target.
Example
Example1

Input: root = {5,4,9,2,#,8,10} and target = 6.124780
Output: 5
Explanation：
Binary tree {5,4,9,2,#,8,10},  denote the following structure:
        5
       / \
     4    9
    /    / \
   2    8  10
Example2

Input: root = {3,2,4,1} and target = 4.142857
Output: 4
Explanation：
Binary tree {3,2,4,1},  denote the following structure:
     3
    / \
  2    4
 /
1*/

    double absdiff = INT_MAX;
    int result;
    void closestValue_util(TreeNode *root, double target) {
        if (root == nullptr) return;
        if (abs(root->val-target) < absdiff) {
            absdiff = abs(root->val-target);
            result = root->val;
        }
        if (target < root->val) closestValue_util(root->left, target);
        if (target > root->val) closestValue_util(root->right, target);
    }
    int closestValue(TreeNode *root, double target) {
        closestValue_util(root,target);
        cout<<absdiff<<endl;
        return result;
    }
