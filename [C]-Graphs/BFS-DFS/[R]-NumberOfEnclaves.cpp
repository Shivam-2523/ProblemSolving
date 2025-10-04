/*
You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

 

Example 1:


Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
Output: 3
Explanation: There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.
Example 2:


Input: grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
Output: 0
Explanation: All 1s are either on the boundary or can reach the boundary.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 500
grid[i][j] is either 0 or 1.
*/


class Solution {
public:
    vector<vector<int>> dirs{{-1,0},{1,0},{0,-1},{0,1}};
    
    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& vis) {
        int m = grid.size(), n = grid[0].size();
        vis[i][j] = true;
        for(auto& d : dirs) {
            int ni = i + d[0], nj = j + d[1];
            if(ni>=0 && ni<m && nj>=0 && nj<n && grid[ni][nj]==1 && !vis[ni][nj])
                dfs(ni, nj, grid, vis);
        }
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        
        // Mark boundary-connected lands
        for(int i=0; i<m; ++i) {
            if(grid[i][0]==1 && !vis[i][0]) dfs(i,0,grid,vis);
            if(grid[i][n-1]==1 && !vis[i][n-1]) dfs(i,n-1,grid,vis);
        }
        for(int j=0; j<n; ++j) {
            if(grid[0][j]==1 && !vis[0][j]) dfs(0,j,grid,vis);
            if(grid[m-1][j]==1 && !vis[m-1][j]) dfs(m-1,j,grid,vis);
        }
        
        int count = 0;
        for(int i=0; i<m; ++i)
            for(int j=0; j<n; ++j)
                if(grid[i][j]==1 && !vis[i][j])
                    count++;
        return count;
    }
};