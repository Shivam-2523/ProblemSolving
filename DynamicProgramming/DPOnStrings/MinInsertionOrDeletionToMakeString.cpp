/*
Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.

In one step, you can delete exactly one character in either string.

 

Example 1:

Input: word1 = "sea", word2 = "eat"
Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
Example 2:

Input: word1 = "leetcode", word2 = "etco"
Output: 4
 

Constraints:

1 <= word1.length, word2.length <= 500
word1 and word2 consist of only lowercase English letters.
*/

class Solution {
public:
    int lcs(string & text1, string & text2)
    {
        int m = text1.size();
        int n = text2.size();

        vector<vector<int>> dp(m+1,vector<int>(n+1,0));

        for(int i = 1; i<=m; ++i)
        {
            for(int j = 1; j<=n; ++j)
            {
                if(text1[i-1]==text2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }

        return dp[m][n];
    }
    int minDistance(string word1, string word2) {
        int val = lcs(word1,word2);
        int m = word1.size(), n = word2.size();

        if(m==n) return (m-val)*2;
        
        return (m-val)+(n-val);
    }
};