/*
You are given a string that represents the prefix form of a valid mathematical expression. Convert it to its postfix form.

Example:

Input: 
*-A/BC-/AKL
Output: 
ABC/-AK/L-*
Explanation: 
The above output is its valid postfix form.
Your Task:

Complete the function preToPost(string pre_exp), which takes a prefix string as input and returns its postfix form.

 

Expected Time Complexity: O(N).

Expected Auxiliary Space: O(N).

Constraints:

3<=pre_exp.length()<=100
*/

// User function Template for C++

class Solution {
  public:
    string preToPost(string pre_exp) {
        stack<string> st;
        string s = pre_exp;
        int n = s.size();
        
        for(int i = n-1; i>=0; i--)
        {
            if((s[i]>='a'&& s[i]<='z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '1' && s[i] <= '9'))
            {
                st.push(string(1,s[i]));
            }
            else
            {
                string a = st.top();
                st.pop();
                string b = st.top();
                st.pop();
                auto str = a + b + s[i];
                st.push(str);
            }
        }
        return st.top();
    }
};
