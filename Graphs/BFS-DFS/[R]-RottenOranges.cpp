/*
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

 

Example 1:


Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:

Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
Example 3:

Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 10
grid[i][j] is 0, 1, or 2.
*/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
      int row = grid.size();
      int col = grid[0].size();
      queue<pair<int,int>> q;
      int fresh = 0, time = 0;

      for(int i = 0; i<row; ++i)
      {
        for(int j = 0; j<col; ++j)
        {
            if(grid[i][j] == 2)
                q.push({i,j});
            else if (grid[i][j] == 1)
                fresh++;
        }
      }
      vector<vector<int>> v = {{-1,0},{0,-1},{1,0},{0,1}};
      while(!q.empty() && fresh > 0)
      {
        int size = q.size();
        for(int i = 0; i<size; i++)
        {
            auto [r,c] = q.front(); q.pop();
            for(auto i: v)
            {
                int adjRow = r + i[0], adjCol = c + i[1];
                if(adjRow >= 0 && adjRow < row && adjCol >= 0 && adjCol < col && grid[adjRow][adjCol]==1)
                {
                    q.push({adjRow,adjCol});
                    grid[adjRow][adjCol] = 2;
                    fresh--;
                }
            }
        }
        time++;
      }

      return fresh == 0 ? time : -1;
    }
};