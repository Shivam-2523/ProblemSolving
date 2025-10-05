/*
A string is called a happy prefix if is a non-empty prefix which is also a suffix (excluding itself).

Given a string s, return the longest happy prefix of s. Return an empty string "" if no such prefix exists.

 

Example 1:

Input: s = "level"
Output: "l"
Explanation: s contains 4 prefix excluding itself ("l", "le", "lev", "leve"), and suffix ("l", "el", "vel", "evel"). The largest prefix which is also suffix is given by "l".
Example 2:

Input: s = "ababab"
Output: "abab"
Explanation: "abab" is the largest prefix which is also suffix. They can overlap in the original string.
 

Constraints:

1 <= s.length <= 105
s contains only lowercase English letters.
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
    string longestPrefix(string s) {
        auto lps = computeLPS(s);
        int len = lps[s.size() - 1];
        return s.substr(0, len);
    }
};
