/*
Given a boolean 2D matrix grid of size n * m. You have to find the number of distinct islands where a group of connected 1s (horizontally or vertically) forms an island. Two islands are considered to be distinct if and only if one island is not equal to another (not rotated or reflected).

Example 1:

Input:
grid[][] = [[1, 1, 0, 0, 0],
            [1, 1, 0, 0, 0],
            [0, 0, 0, 1, 1],
            [0, 0, 0, 1, 1]]
Output: 1
Explanation:
grid[][] = [[1, 1, 0, 0, 0], 
            [1, 1, 0, 0, 0], 
            [0, 0, 0, 1, 1], 
            [0, 0, 0, 1, 1]]
Same colored islands are equal. We have 2 equal islands, so we have only 1 distinct island.

Example 2:

Input:
grid[][] = [[1, 1, 0, 1, 1],
            [1, 0, 0, 0, 0],
            [0, 0, 0, 0, 1],
            [1, 1, 0, 1, 1]]
Output: 3
Explanation:
grid[][] = [[1, 1, 0, 1, 1], 
            [1, 0, 0, 0, 0], 
            [0, 0, 0, 0, 1], 
            [1, 1, 0, 1, 1]]
Same colored islands are equal.
We have 4 islands, but 2 of them
are equal, So we have 3 distinct islands.

Your Task: You don't need to read or print anything. Your task is to complete the function countDistinctIslands() which takes the grid as an input parameter and returns the total number of distinct islands.

Constraints:
1 ≤ n, m ≤ 500
grid[i][j] == 0 or grid[i][j] == 1
*/

// User function Template for C++

class Solution {
  public:
    void findIsland(vector<vector<int>>& grid, vector<vector<bool>> & vis, int i, int j, int br, int bc, vector<pair<int,int>> & island)
    {
        vis[i][j] = true;
        vector<pair<int,int>> v {{-1,0},{1,0},{0,1},{0,-1}};
        
        island.push_back({i-br,j-bc});
        
        for(auto a: v)
        {
            auto r = i + a.first;
            auto c = j + a.second;
            
            if(r>=0 && r<grid.size() && c>=0 && c<grid[0].size() && grid[r][c] == 1 && !vis[r][c])
            {
                findIsland(grid,vis,r,c,br,bc,island);
            }
        }
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<bool>> vis (row,vector<bool>(col,false));
        set<vector<pair<int,int>>> islands;
        for(int i = 0; i<row; ++i)
        {
            for(int j = 0; j<col; ++j)
            {
                if(grid[i][j] == 1 && !vis[i][j])
                {
                    auto island = vector<pair<int,int>>{};
                    findIsland(grid,vis,i,j,i,j,island);
                    islands.insert(island);
                }
            }
        }
        
        return islands.size();
    }
};
