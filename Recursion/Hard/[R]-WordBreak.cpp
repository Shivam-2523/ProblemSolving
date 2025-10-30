/*
Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

 

Example 1:

Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false
 

Constraints:

1 <= s.length <= 300
1 <= wordDict.length <= 1000
1 <= wordDict[i].length <= 20
s and wordDict[i] consist of only lowercase English letters.
All the strings of wordDict are unique.
*/

class Solution {
public:
    void helper(int start, string & curr, string & s, unordered_set<string> & wordDict, bool & flag)
    {
        if(flag) return;
        if(start == s.size())
        {
            //if we have reached till the end of the string then we are sure that all the combinations
            //in this flow were found in the dictionary
            flag = true;
            return;
        }

        for(int end = start; end<s.size(); ++end)
        {
            //If word till now is present then check for combinations in the remaining word
            if(wordDict.count(s.substr(start, end - start + 1)))
            {
                curr = s.substr(start, end - start + 1);
                helper(end+1,curr,s,wordDict,flag);
                curr = s.substr(0, curr.size() - (end - start + 1)); //backtrack
            }
        }
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        string curr = "";
        bool flag = false;
        helper(0,curr,s,dict,flag);
        return flag;
    }
};