/*
Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

 

Example 1:

Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
Example 2:

Input: triangle = [[-10]]
Output: -10
 

Constraints:

1 <= triangle.length <= 200
triangle[0].length == 1
triangle[i].length == triangle[i - 1].length + 1
-104 <= triangle[i][j] <= 104
 

Follow up: Could you do this using only O(n) extra space, where n is the total number of rows in the triangle?
*/


class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<vector<int>> dp(m, vector<int>(m, 0));

        dp[0][0] = triangle[0][0];

        for (int i = 1; i < m; i++) {
            int n = triangle[i].size();
            for (int j = 0; j < n; j++) {
                if (j == 0) 
                    dp[i][j] = triangle[i][j] + dp[i-1][j];  // Only one option from above
                else if (j == i) 
                    dp[i][j] = triangle[i][j] + dp[i-1][j-1];  // Only one option from left diagonal
                else 
                    dp[i][j] = triangle[i][j] + min(dp[i-1][j], dp[i-1][j-1]);  // Take minimum
            }
        }

        return *min_element(dp[m-1].begin(), dp[m-1].end());
    }
};
