/*An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.
You are also given three integers sr, sc, and newColor. You should perform a flood fill on the image starting from the pixel image[sr][sc].
To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with newColor.
Return the modified image after performing the flood fill.

Example 1:
Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, newColor = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation: From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected to the starting pixel.*/

    bool isvalid(int x, int y, int m, int n ) {
        return  ((x < m && x >= 0) && (y < n && y >= 0));
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        queue<pair<int,int>> bfsq;
        int dx[4] = {-1,0,1,0};
        int dy[4] = {0,-1,0,1};
        int m = image.size();
        int n = image[0].size();
        int visited[m][n];
        
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                visited[i][j] = 0;
            }
        }
        
        int orig_color = image[sr][sc];
        bfsq.push({sr,sc});
        image[sr][sc] = newColor;
        while (bfsq.empty() == false) {
            int x = bfsq.front().first;
            int y = bfsq.front().second;
            bfsq.pop();
            for (int i=0;i<4;i++) {
                if (isvalid(x+dx[i],y+dy[i],m,n) && (image[x+dx[i]][y+dy[i]] == orig_color) && (visited[x+dx[i]][y+dy[i]] == 0)) {
                    image[x+dx[i]][y+dy[i]] = newColor;
                    visited[x+dx[i]][y+dy[i]] = 1;
                    bfsq.push({x+dx[i],y+dy[i]});
                }
            }
        }
        return image;
    }
