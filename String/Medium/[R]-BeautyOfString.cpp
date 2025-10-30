/*The beauty of a string is the difference in frequencies between the most frequent and least frequent characters.

For example, the beauty of "abaacc" is 3 - 1 = 2.
Given a string s, return the sum of beauty of all of its substrings.

 

Example 1:

Input: s = "aabcb"
Output: 5
Explanation: The substrings with non-zero beauty are ["aab","aabc","aabcb","abcb","bcb"], each with beauty equal to 1.
Example 2:

Input: s = "aabcbaa"
Output: 17
 

Constraints:

1 <= s.length <= 500
s consists of only lowercase English letters.*/



class Solution {
public:
    int getMostFreq(int freq[]) {
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            ans = max(ans, freq[i]);
        }
        return ans;
    }

    int getLeastFreq(int freq[]) {
        int ans = INT_MAX;
        for (int i = 0; i < 26; i++) {
            if (freq[i] != 0) {
                ans = min(ans, freq[i]);
            }
        }
        return ans;
    }

    int beautySum(string s) {
        int n = s.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int freq[26]={0};
            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;
                int beauty = getMostFreq(freq) - getLeastFreq(freq);
                sum+=beauty;
            }
        }
        return sum;
    }
};