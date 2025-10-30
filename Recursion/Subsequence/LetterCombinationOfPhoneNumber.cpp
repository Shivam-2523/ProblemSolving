/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.


 

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = ""
Output: []
Example 3:

Input: digits = "2"
Output: ["a","b","c"]
 

Constraints:

0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].
*/

class Solution {
public:
    int getter (char i)
    {
        if(i>='2' && i<='7')
            return (((i-'0')-2) * 3) + 'a';
        if(i == '8')
            return 116;
        else
            return 119;
    }
    void helper(string s, int index, vector<string>& ans, string & temp)
    {
        if(index == s.size())
        {
            ans.push_back(temp);
            return;
        }
        int c = getter(s[index]);
        cout<<c<<endl;
        string s1 = temp+(char)(c);
        helper(s,index+1,ans,s1);

        string s2 = temp+(char)(c+1);
        helper(s,index+1,ans,s2);

        string s3 = temp+(char)(c+2);
        helper(s,index+1,ans,s3);

        if(s[index] == '7' || s[index] == '9')
        {
            string s4 = temp+(char)(c+3);
            helper(s,index+1,ans,s4);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string temp = "";
        if(digits.size() == 0)
            return {};
        helper(digits,0,ans, temp);
        return ans;
    }
};

