/*
Given a string s. In one step you can insert any character at any index of the string.

Return the minimum number of steps to make s palindrome.

A Palindrome String is one that reads the same backward as well as forward.

 

Example 1:

Input: s = "zzazz"
Output: 0
Explanation: The string "zzazz" is already palindrome we do not need any insertions.
Example 2:

Input: s = "mbadm"
Output: 2
Explanation: String can be "mbdadbm" or "mdbabdm".
Example 3:

Input: s = "leetcode"
Output: 5
Explanation: Inserting 5 characters the string becomes "leetcodocteel".
 

Constraints:

1 <= s.length <= 500
s consists of lowercase English letters.
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
                if(text1[i-1] == text2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }

        return dp[m][n];
    }
    int minInsertions(string s) {
        string r = s;
        reverse(s.begin(),s.end());
        return s.size() - lcs(s,r);
    }
};