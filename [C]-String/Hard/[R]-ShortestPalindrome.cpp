/*
You are given a string s. You can convert s to a palindrome by adding characters in front of it.

Return the shortest palindrome you can find by performing this transformation.

 

Example 1:

Input: s = "aacecaaa"
Output: "aaacecaaa"
Example 2:

Input: s = "abcd"
Output: "dcbabcd"
 

Constraints:

0 <= s.length <= 5 * 104
s consists of lowercase English letters only.
*/

class Solution {
public:
    // Utility function to make the LPS array
    vector<int> computeLPS(string pat) {
        int n = pat.size();
        vector<int> lps(n, 0);
        int len = 0; // length of the previous longest prefix suffix
        int i = 1;
        
        while (i < n) {
            if (pat[i] == pat[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                    // Do not increment i here
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(),rev.end());
        string temp = s + "#" + rev;
        auto ans = computeLPS(temp);
        return rev.substr(0, s.size() - ans.back()) + s;
    }
};

