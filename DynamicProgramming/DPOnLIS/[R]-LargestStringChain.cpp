/*
You are given an array of words where each word consists of lowercase English letters.

wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without changing the order of the other characters to make it equal to wordB.

For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".
A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of word2, word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k == 1.

Return the length of the longest possible word chain with words chosen from the given list of words.

 

Example 1:

Input: words = ["a","b","ba","bca","bda","bdca"]
Output: 4
Explanation: One of the longest word chains is ["a","ba","bda","bdca"].
Example 2:

Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
Output: 5
Explanation: All the words can be put in a word chain ["xb", "xbc", "cxbc", "pcxbc", "pcxbcf"].
Example 3:

Input: words = ["abcd","dbqca"]
Output: 1
Explanation: The trivial word chain ["abcd"] is one of the longest word chains.
["abcd","dbqca"] is not a valid word chain because the ordering of the letters is changed.
 

Constraints:

1 <= words.length <= 1000
1 <= words[i].length <= 16
words[i] only consists of lowercase English letters.
*/

class Solution {
public:
    bool check(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();

        if(m-1!=n) return false;

        int  i = 0, j = 0;

        while(i<m && j<n)
        {
            if(text1[i] == text2[j])
            {
                j++;
            }

            i++;
        }
        return j == n;
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });
        int n = words.size();
        vector<int> dp(n,1);//length of longest string chain ending at index i
        int ans = 1;
        for(int i = 0; i<n; ++i)
        {
            for(int j = 0; j<i; ++j)
            {
                if(check(words[i],words[j]))
                {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
            ans = max(ans,dp[i]);
        }

        return ans;
    }
};

/*
class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& a, const string& b){
            return a.size() < b.size();
        });
        unordered_map<string, int> dp;
        int ans = 1;

        for(const string& word : words){
            dp[word] = 1;
            // Try all one character removals (predecessors)
            for(int i=0; i < word.size(); ++i){
                string pred = word.substr(0, i) + word.substr(i+1);
                if(dp.count(pred)) {
                    dp[word] = max(dp[word], dp[pred] + 1);
                }
            }
            ans = max(ans, dp[word]);
        }
        return ans;
    }
};*/