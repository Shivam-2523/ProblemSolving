/*
You are given a string that represents the postfix form of a valid mathematical expression. Convert it to its infix form.

Example:

Input:
ab*c+ 
Output: 
((a*b)+c)
Explanation: 
The above output is its valid infix form.
Your Task:

Complete the function string postToInfix(string post_exp), which takes a postfix string as input and returns its infix form.

 

Expected Time Complexity: O(N).

Expected Auxiliary Space: O(N).

Constraints:

3<=post_exp.length()<=104
*/

// User function Template for C++

class Solution {
  public:
    string postToInfix(string exp) {
        // Write your code here
        stack<string> st;
        string s = exp;
        int n = s.size();
        
        for(int i = 0; i<n; i++)
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
                auto str = "(" + b + s[i] + a + ")";
                st.push(str);
            }
        }
        return st.top();
    }
};
