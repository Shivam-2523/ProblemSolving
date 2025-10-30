/*
Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

 

Example 1:

Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".
Example 2:

Input: s = "cbbd"
Output: 2
Explanation: One possible longest palindromic subsequence is "bb".
 

Constraints:

1 <= s.length <= 1000
s consists only of lowercase English letters.
*/

class Solution {
public:
 int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();

        vector<vector<int>> dp (m+1, vector<int>(n+1,0));
        //LCS for text1 with size I and text2 of size J is represented by dp[i][j]
        for(int i = 1; i<=m; ++i)
        {
            for(int j = 1; j<=n; ++j)
            {
                if(text1[i-1] == text2[j-1])
                {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else
                {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
        return dp[m][n];
    }

    int longestPalindromeSubseq(string s) {
        auto rev = s;
        reverse(rev.begin(),rev.end());
        return longestCommonSubsequence(s,rev);
    }
};