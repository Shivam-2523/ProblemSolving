/*
Given a string s of lowercase alphabets, count all possible substrings (not necessarily distinct) that have exactly k distinct characters. 

Examples :

Input: s = "aba", k = 2
Output: 3
Explanation: The substrings are: "ab", "ba" and "aba".
Input: s = "abaaca", k = 1
Output: 7
Explanation: The substrings are: "a", "b", "a", "aa", "a", "c", "a".
Input: s = "cdad", k = 4
Output: 0
Constraints:
1 ≤ s.size() ≤ 106
1 ≤ k ≤ 26
*/


class Solution {
public:
    int countSubstr(string& s, int k) {
       
        return atMostKDistinct(s, k) - atMostKDistinct(s, k - 1);
        
    }
    
    int atMostKDistinct(const string& s, int k) {
        unordered_map<char, int> freq;
        int start = 0, result = 0;
        
        for (int end = 0; end < s.size(); end++) {
            freq[s[end]]++;
            
            // If the number of distinct characters exceeds k, shrink the window
            while (freq.size() > k) {
                freq[s[start]]--;
                if (freq[s[start]] == 0) {
                    freq.erase(s[start]);
                }
                start++;
            }
            
            // All substrings ending at 'end' and starting from 'start' to 'end' are valid
            result += (end - start + 1);
        }
        
        return result;
    }
};