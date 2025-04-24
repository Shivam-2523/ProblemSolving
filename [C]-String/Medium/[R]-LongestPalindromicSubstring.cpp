/*
Given a string s, return the longest 
palindromic
 
substring
 in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
 

Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters.
*/

string longestPalindrome(string s) {
    int n = s.length();
    if (n <= 1) return s;

    // Create a DP table initialized to false
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    int start = 0; // To store the starting index of the longest palindrome
    int max_len = 1; // At least one character is a palindrome

    // All substrings of length 1 are palindromes
    for (int i = 0; i < n; ++i) {
        dp[i][i] = true;
    }

    // Check for substrings of length 2
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = true;
            start = i;
            max_len = 2;
        }
    }

    // Check for substrings of length greater than 2
    for (int length = 3; length <= n; ++length) {
        for (int i = 0; i <= n - length; ++i) {
            int j = i + length - 1;
            if (s[i] == s[j] && dp[i + 1][j - 1]) {
                dp[i][j] = true;
                start = i;
                max_len = length;
            }
        }
    }

    return s.substr(start, max_len);
}
