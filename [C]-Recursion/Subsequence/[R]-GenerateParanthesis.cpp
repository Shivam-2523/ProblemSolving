/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
 

Constraints:

1 <= n <= 8
*/

class Solution {
public:
    void helper(string s, vector<string> & ans, int i, int num)
    {
        if(i == num)
        {
            ans.push_back(s);
            return;
        }

        helper(s+'(',ans,i+1,num);
        if(s.size()>0 || s[s.size()-1] == '0')
            helper(s+'1',ans,i+1,num);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper("",ans,0,n);
        return ans;
    }
};