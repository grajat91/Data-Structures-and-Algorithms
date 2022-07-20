/*Given two binary search trees root1 and root2, return a list containing all the integers from both trees sorted in ascending order.

Example 1:
Input: root1 = [2,1,4], root2 = [1,0,3]
Output: [0,1,1,2,3,4]

Example 2:
Input: root1 = [1,null,8], root2 = [8,1]
Output: [1,1,8,8]*/

//Method1: By constructing inorder arrays
    void inorder_util(TreeNode* root, vector<int> &inorder) {
        if (root != nullptr) {
            inorder_util(root->left, inorder);
            inorder.push_back(root->val);
            inorder_util(root->right, inorder);
        }
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> inorder1;
        vector<int> inorder2;
        vector<int> result;
        inorder_util(root1, inorder1);
        inorder_util(root2, inorder2);
        int i=0;
        int j=0;
        int m = inorder1.size();
        int n = inorder2.size();
        cout<<m<<" "<<n<<endl;
        while (i<m && j<n) {
            if (inorder1[i] < inorder2[j]) {
                result.push_back(inorder1[i]);
                i++;
            } else {
                result.push_back(inorder2[j]);
                j++;
            }
        }
        while (i<m) {
            result.push_back(inorder1[i]);
            i++;
        }
        while (j<n) {
            result.push_back(inorder2[j]);
            j++;
        }
        return result;
    }
