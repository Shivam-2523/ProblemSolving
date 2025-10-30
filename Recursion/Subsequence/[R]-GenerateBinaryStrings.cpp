/*
Given an integer N , Print all binary strings of size N which do not contain consecutive 1s.

A binary string is that string which contains only 0 and 1.

Example 1:

Input:
N = 3
Output:
000 , 001 , 010 , 100 , 101
Explanation:
None of the above strings contain consecutive 1s. "110" is not an answer as it has '1's occuring consecutively. 
Your Task:

You don't need to read input or print anything. Your task is to complete the function generateBinaryStrings() which takes an integer N as input and returns a list of all valid binary strings in lexicographically increasing order.

Expected Time Complexity: O(2N)
Expected Auxiliary Space: O(N)

Constraints:
1 <= N <= 20
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

        helper(s+'0',ans,i+1,num);
        if(s.size()==0 || s[s.size()-1] == '0')
            helper(s+'1',ans,i+1,num);
    }
    
    vector<string> generateBinaryStrings(int num) {
        // Write your code
        vector<string> ans;
        helper("",ans,0,num);
        return ans;
    }
};


