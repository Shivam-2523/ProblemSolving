/*
You are given a string s representing an infix expression. Convert this infix expression to a postfix expression.

Infix expression: The expression of the form a op b. When an operator is in between every pair of operands.
Postfix expression: The expression of the form a b op. When an operator is followed for every pair of operands.
Note: The precedence order is as follows: (^) has the highest precedence and is evaluated from right to left, (* and /) come next with left to right associativity, and (+ and -) have the lowest precedence with left to right associativity.

Examples :

Input: s = "a*(b+c)/d"
Output: abc+*d/
Explanation: The expression is a*(b+c)/d. First, inside the brackets, b+c becomes bc+. Now the expression looks like a*(bc+)/d. Next, multiply a with (bc+), so it becomes abc+* . Finally, divide this result by d, so it becomes abc+*d/.
Input: s = "a+b*c+d"
Output: abc*+d+
Explanation: The expression a+b*c+d is converted by first doing b*c -> bc*, then adding a -> abc*+, and finally adding d -> abc*+d+.
Input: s = "(a+b)*(c+d)"
Output: ab+cd+*
Explanation: The expression (a+b)*(c+d) is converted by first doing (a+b) -> ab+, then doing (c+d) -> cd+, and finally the expression ab+*cd+ becomes ab+cd+*. 
Constraints:
1 ≤ s.length ≤ 5*103
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
        stack<char> st;
        string result;
        for(char c : s) {
            if(isalpha(c) || isdigit(c)) {
                result += c; // Operand: output directly
            } else if(c == '(') {
                st.push(c);
            } else if(c == ')') {
                while(!st.empty() && st.top() != '(') {
                    result += st.top();
                    st.pop();
                }
                if(!st.empty()) st.pop(); // pop '('
            } else if(isOperator(c)) {
                while(!st.empty() && precedence(st.top()) >= precedence(c)) {
                    if(st.top() == '^' && c == '^') break; // right-to-left associativity for ^
                    result += st.top();
                    st.pop();
                }
                st.push(c);
            }
        }
        // Pop remaining ops
        while(!st.empty()) {
            result += st.top();
            st.pop();
        }
        return result;
    }
};
