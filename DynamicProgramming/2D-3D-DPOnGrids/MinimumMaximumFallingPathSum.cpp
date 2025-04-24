/*
Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

 

Example 1:


Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
Output: 13
Explanation: There are two falling paths with a minimum sum as shown.
Example 2:


Input: matrix = [[-19,57],[-40,-5]]
Output: -59
Explanation: The falling path with a minimum sum is shown.
 

Constraints:

n == matrix.length == matrix[i].length
1 <= n <= 100
-100 <= matrix[i][j] <= 100
*/


class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();

        vector<vector<int>> dp (m, vector<int> (m,0));
        for(int i = 0; i<m; i++)
            dp[0][i] = matrix[0][i];
        
        for(int i = 1; i<m; i++)
        {
            for(int j = 0; j<m; j++)
            {
                if(j == 0)
                    dp[i][j] = matrix[i][j] + min(dp[i-1][j],dp[i-1][j+1]);
                else if (j == m-1)
                    dp[i][j] = matrix[i][j] + min(dp[i-1][j],dp[i-1][j-1]);
                else
                    dp[i][j] = matrix[i][j] + min(min(dp[i-1][j],dp[i-1][j+1]),dp[i-1][j-1]);
            }
        }
        return *min_element(dp[m-1].begin(), dp[m-1].end());
    }
};