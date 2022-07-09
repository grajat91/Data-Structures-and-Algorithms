/*There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean. The Pacific Ocean touches the island's left and top edges, and the Atlantic Ocean touches the island's right and bottom edges.
The island is partitioned into a grid of square cells. You are given an m x n integer matrix heights where heights[r][c] represents the height above sea level of the cell at coordinate (r, c).
The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, south, east, and west if the neighboring cell's height is less than or equal to the current cell's height. Water can flow from any cell adjacent to an ocean into the ocean.
Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that rain water can flow from cell (ri, ci) to both the Pacific and Atlantic oceans.

Example 1:
Input: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
Output: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]

Example 2:
Input: heights = [[2,1],[1,2]]
Output: [[0,0],[0,1],[1,0],[1,1]]*/

class Solution {
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    bool isvalid (int x, int y, int m, int n) {
        return ((x>=0 && x<m) && (y>=0 && y< n));
    }
    
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& ocean, int x, int y, int prev, int m, int n) {
        if (isvalid(x,y,m,n) && !ocean[x][y]) {
            if (heights[x][y] >= prev) {
                ocean[x][y] = true;
                for (int k=0;k<4;k++) {
                    dfs(heights,ocean,x+dx[k],y+dy[k],heights[x][y],m,n);
                }
            }
        }
        return;
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> result;
        if (heights.size() == 0 || heights[0].size() == 0) return result;
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> pacific(m,vector<bool>(n,false));
        vector<vector<bool>> atlantic(m,vector<bool>(n,false));
        
        //DFS
        for (int i=0;i<n;i++) {
            dfs(heights,pacific,0,i,INT_MIN,m,n);
            dfs(heights,atlantic,m-1,i,INT_MIN,m,n);
        }
        for (int i=0;i<m;i++) {
            dfs(heights,pacific,i,0,INT_MIN,m,n);
            dfs(heights,atlantic,i,n-1,INT_MIN,m,n);
        }
        //END DFS
        
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (atlantic[i][j] && pacific[i][j]) result.push_back({i,j});
            }
        }
        return result;
    }
};
