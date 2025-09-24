/*
You are given a string s representing an infix expression. Convert this infix expression to a prefix expression.

Infix expression: The expression of the form a op b. When an operator is in between every pair of operands.
Prefix expression: The expression of the form op a b. When an operator comes before its two operands.

Note: The precedence order is as follows: (^) has the highest precedence and is evaluated from right to left. (* and /) come next with left to right associativity, and (+ and -) have the lowest precedence with left to right associativity.

Examples:

Input: s = "a*(b+c)/d"
Output: /*a+bcd
Explaination: The infix expression is a*(b+c)/d. First, inside the brackets, b + c becomes +bc. Now the expression looks like a*(+bc)/d. Next, multiply a with (+bc), so it becomes *a+bc. Finally, divide this result by d, so it becomes /*a+bcd.
Input: s = "(a-b/c)*(a/k-l)"
Output: *-a/bc-/akl
Explaination: The infix expression is (a-b/c)*(a/k-l). First, inside the brackets, b/c becomes /bc and a/k becomes /ak.Now the expression looks like (a-/bc) * (/ak-l).Next, handle the subtractions: a-/bc becomes -a/bc, and /ak-l becomes -/akl. Finally, multiply the two results: (-a/bc * -/akl) becomes *-a/bc-/akl.
Constraints:
3 ≤ s.length() ≤ 5*103
s[i] can be an operand (a–z, A–Z, 0–9), an operator (+, -, *, /, ^) or a parenthesis ((, ))
*/

class Solution {
  public:
    // Helper: returns precedence of operators
    int precedence(char op) {
        if(op == '^') return 3;
        if(op == '*' || op == '/') return 2;
        if(op == '+' || op == '-') return 1;
        return 0;
    }
    
    bool isOperator(char c) {
        return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
    }
    
    string infixToPostfix(string& s) {
        stack<int> st;
        string ans = "";
        for (int i = 0; i < s.size(); i++)
        {
        	if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '1' && s[i] <= '9'))
        	{
        		ans += s[i];
        	}
        	else if (s[i] == '(')
        	{
        		st.push('(');
        	}
        	else if (s[i] == ')')
        	{
        		while (st.top() != '(')
        		{
        			ans += st.top();
        			st.pop();
        		}
        		st.pop();
        	}
        	else
        	{
        		while (!st.empty() && precedence(s[i]) < precedence(st.top()))
        		{
        			ans += st.top();
        			st.pop();
        		}
        		st.push(s[i]);
        	}
        }
        while (!st.empty())
        {
        	ans += st.top();
        	st.pop();
        }
        return ans;
    }
    
    string infixToPrefix(string &s) {
        reverse(s.begin(),s.end());
        for(auto & i: s)
        {
            if(i == '(') i = ')';
            if(i == ')') i = '(';
        }
        auto ans = infixToPostfix(s);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
