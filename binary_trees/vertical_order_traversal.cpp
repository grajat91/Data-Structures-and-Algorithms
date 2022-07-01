/*Given a binary tree, return the vertical order traversal of its nodes' values. (ie, from top to bottom, column by column).
If two nodes are in the same row and column, the order should be from left to right.
For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).

Example1

Inpurt:  {3,9,20,#,#,15,7}
Output: [[9],[3,15],[20],[7]]
Explanation:
   3
  /\
 /  \
 9  20
    /\
   /  \
  15   7
Example2

Input: {3,9,8,4,0,1,7}
Output: [[4],[9],[3,0,1],[8],[7]]
Explanation:
     3
    /\
   /  \
   9   8
  /\  /\
 /  \/  \
 4  01   7*/

    vector<vector<int>> verticalOrder(TreeNode *root) {
        vector<vector<int>> result;
        if (root == NULL) return result;
        map<int,vector<int>> horizontal_distance;
        queue<pair<TreeNode*, int>> bfsq;
        bfsq.push({root,0});
        
        while (!bfsq.empty()) {
            int qsize = bfsq.size();
            for (int i=0; i<qsize; i++) {
                TreeNode *front_elem = bfsq.front().first;
                int hd = bfsq.front().second;
                horizontal_distance[hd].push_back(front_elem->val);
                bfsq.pop();
                if (front_elem->left) bfsq.push({front_elem->left,hd-1});
                if (front_elem->right) bfsq.push({front_elem->right,hd+1});
            }
        }
        for (auto it : horizontal_distance) result.push_back(it.second);
        return result;
    }
