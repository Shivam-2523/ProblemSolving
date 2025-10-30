/*
Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

 

Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
Example 2:

Input: s = "a"
Output: [["a"]]
 

Constraints:

1 <= s.length <= 16
s contains only lowercase English letters.
*/

class Solution {
public:
    bool isPalindrome(string s)
    {
        int l = 0, r = s.size()-1;
        while(l<r)
            if(s[l++]!=s[r--]) return false;

        return true;
    }
    
    void dfs(int start, string& s, vector<string>& path, vector<vector<string>>& res) {
        if (start == s.size()) {
            res.push_back(path);
            return;
        }
        for (int end = start; end < s.size(); ++end) {
            if (isPalindrome(s.substr(start, end - start + 1))) {
                // Add current palindrome substring to path
                path.push_back(s.substr(start, end - start + 1));
                dfs(end + 1, s, path, res);
                path.pop_back(); // backtrack
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> v;
        
        dfs(0,s,v,ans);

        return ans;
    }
};
