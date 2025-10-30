/*
You are given two strings s1 and s2. Your task is to find the length of the longest common substring among the given strings.

Examples:

Input: s1 = "ABCDGH", s2 = "ACDGHR"
Output: 4
Explanation: The longest common substring is "CDGH" with a length of 4.
Input: s1 = "abc", s2 = "acb"
Output: 1
Explanation: The longest common substrings are "a", "b", "c" all having length 1.
Input: s1 = "YZ", s2 = "yz"
Output: 0
Constraints:
1 <= s1.size(), s2.size() <= 103
Both strings may contain upper and lower case alphabets.
*/

class Solution {
  public:
    int longestCommonSubstr(string& s1, string& s2) {
        int l1 = s1.size(), l2 = s2.size();
        vector<vector<int>> dp(l1+1, vector<int>(l2+1, 0));
        int result = 0;
        for(int i = 1; i <= l1; ++i) {
            for(int j = 1; j <= l2; ++j) {
                if(s1[i-1] == s2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                    result = max(result, dp[i][j]);
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        return result;
    }
};
/*
For LCS:
cpp
Run Code
Copy code
if(s1[i1-1]==s2[i2-1]) 
    dp[i1][i2] = 1 + dp[i1-1][i2-1];
else
    dp[i1][i2] = max(dp[i1-1][i2], dp[i1][i2-1]);
For Substring, the recurrence is different:
If characters match: the substring continues, so you add 1 to the result for the previous indices.
If not: you set to zero, because the substring is broken.
**You need to keep track of the maximum value seen in any cell of your DP table because the substring can end anywhere!
*/