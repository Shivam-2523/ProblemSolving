/*
Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. If there are multiple valid strings, return any of them.

A string s is a subsequence of string t if deleting some number of characters from t (possibly 0) results in the string s.

 

Example 1:

Input: str1 = "abac", str2 = "cab"
Output: "cabac"
Explanation: 
str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
The answer provided is the shortest such string that satisfies these properties.
Example 2:

Input: str1 = "aaaaaaaa", str2 = "aaaaaaaa"
Output: "aaaaaaaa"
 

Constraints:

1 <= str1.length, str2.length <= 1000
str1 and str2 consist of lowercase English letters.
*/

class Solution {
public:
    string lcs(string & text1, string & text2)
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

        // Reconstruct the LCS
        string lcs = "";
        int i = m, j = n;
        // Trace back from dp[m][n]
        while(i > 0 && j > 0) {
            if(text1[i-1] == text2[j-1]) {
                lcs += text1[i-1]; // matched character is part of LCS
                i--; j--;
            } else if (dp[i-1][j] > dp[i][j-1]) {
                i--;
            } else {
                j--;
            }
        }

        reverse(lcs.begin(), lcs.end()); // Because we traced from end, reverse at the end.
        return lcs;
    }
    string shortestCommonSupersequence(string str1, string str2) {
        string val = lcs(str1,str2);
        int m = str1.size(), n = str2.size();
        int i = 0, j = 0;
        string ans = "";

        for(char c : val){
            // Add characters from str1 up to the LCS character
            while(i < m && str1[i] != c){
                ans += str1[i++];
            }
            // Add characters from str2 up to the LCS character
            while(j < n && str2[j] != c){
                ans += str2[j++];
            }
            // Add the LCS character itself
            ans += c;
            i++;
            j++;
        }
        // Add remaining characters from str1 and str2
        ans += str1.substr(i);
        ans += str2.substr(j);
        return ans;
    }
};
/*
Traverse str1 and str2 and for each character in the LCS, append everything in str1/str2 before that character (if any), then the LCS character.
After traversing both strings, append any remaining characters in str1 and str2.
*/