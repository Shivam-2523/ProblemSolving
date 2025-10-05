/*
Given two strings, one is a text string, text, and the other is a pattern string, pattern. Find and print the indices of all the occurrences of the pattern string within the text string. Use 0-based indexing for the indices, and ensure that the indices are in ascending order. If the pattern does not occur in the text, return an empty list.



Implement this solution using the Knuth-Morris-Pratt (KMP) algorithm for efficient pattern matching.


Examples:
Input: text = "abracadabra", pattern = "abra"



Output: 0 7



Expalanation : The pattern "abra" appears at the 0st and 7th positions in the text "abracadabra".

Input: text = "abcabcabc", pattern = "abc"



Output: 0 3 6



Expalanation : The pattern "abc" appears at the 0st, 3th, and 6th positions in the text "abcabcabc".
*/

class Solution{
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
        
        vector <int> search(string pat, string txt) {
            int m = pat.size();
            int n = txt.size();
            vector<int> res;
            
            // Preprocess the pattern to get LPS array
            vector<int> lps = computeLPS(pat);
            
            int i = 0; // index for txt
            int j = 0; // index for pat
            
            while (i < n) {
                if (pat[j] == txt[i]) {
                    i++;
                    j++;
                }
                if (j == m) {
                    // Found one occurrence, store starting index
                    res.push_back(i - j);
                    // Try to find the next occurrence
                    j = lps[j - 1];
                } else if (i < n && pat[j] != txt[i]) {
                    // Mismatch after j matches
                    if (j != 0) {
                        j = lps[j - 1];
                    }
                    else {
                        i++;
                    }
                }
            }
            return res;
        }
};