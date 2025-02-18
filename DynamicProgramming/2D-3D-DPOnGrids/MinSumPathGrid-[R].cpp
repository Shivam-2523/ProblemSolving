/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

 

Example 1:


Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
Example 2:

Input: grid = [[1,2,3],[4,5,6]]
Output: 12
*/

class Solution {
public:
    int helper(int m, int n, vector<vector<int>> & dp, vector<vector<int>>& grid)
    {
        if(m == 0 && n == 0)
            return grid[0][0];
        if(m == 0)
            return grid[m][n] + helper(m,n-1,dp,grid);
        if(n == 0)
            return grid[m][n] + helper(m-1,n,dp,grid);

        if(dp[m][n]!=-1) return dp[m][n];

        return dp[m][n] = grid[m][n] + min(helper(m-1,n,dp,grid),helper(m,n-1,dp,grid));
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp (m,vector<int>(n,-1));
        return helper(m-1,n-1,dp,grid); 
    }
};
