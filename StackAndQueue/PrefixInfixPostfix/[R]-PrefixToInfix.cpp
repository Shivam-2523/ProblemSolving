/*
You are given a string S of size N that represents the prefix form of a valid mathematical expression. The string S contains only lowercase and uppercase alphabets as operands and the operators are +, -, *, /, %, and ^.Convert it to its infix form.

Example 1:

Input: 
*-A/BC-/AKL
Output: 
((A-(B/C))*((A/K)-L))
Explanation: 
The above output is its valid infix form.
Your Task:

Your task is to complete the function string preToInfix(string pre_exp), which takes a prefix string as input and return its infix form.

Expected Time Complexity: O(N).

Expected Auxiliary Space: O(N).

Constraints:

3<=|S|<=104
*/

// User function Template for C++

class Solution {
  public:
    string preToInfix(string pre_exp) {
        // Write your code here
        string ans = "";
        stack<string> st;
        string s = pre_exp;
        
        for (int i = s.size() - 1; i >= 0; i--)
        {
        	if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '1' && s[i] <= '9'))
        	{
        		st.push(string(1, s[i]));
        	}
        	else
        	{
        		string op1 = st.top();
        		st.pop();
        		string op2 = st.top();
        		st.pop();
        		string temp = "(" + op1 + s[i] + op2 + ")";
        		st.push(temp);
        	}
        }
        ans += st.top();
        return ans;
    }
};
