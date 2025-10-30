/*
Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

 

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
 

Constraints:

m == s.length
n == t.length
1 <= m, n <= 105
s and t consist of uppercase and lowercase English letters.
 

Follow up: Could you find an algorithm that runs in O(m + n) time?
*/

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";

        vector<int> need(128, 0);
        for (char ch : t) need[ch]++;

        int required = 0;
        for (int freq : need) if (freq > 0) required++;

        vector<int> window(128, 0);
        int l = 0, r = 0, formed = 0;
        int minLen = INT_MAX, start = 0;

        while (r < s.size()) {
            char ch = s[r];
            window[ch]++;

            if (need[ch] > 0 && window[ch] == need[ch])
                formed++;

            while (formed == required) {
                // Update minimum window
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    start = l;
                }

                // Try to shrink
                char leftChar = s[l];
                window[leftChar]--;
                if (need[leftChar] > 0 && window[leftChar] < need[leftChar])
                    formed--;

                l++;
            }

            r++;
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};