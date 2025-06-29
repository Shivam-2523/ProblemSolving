/*
Given an infix expression in the form of string s. Convert this infix expression to a postfix expression.

Infix expression: The expression of the form a op b. When an operator is in between every pair of operands.
Postfix expression: The expression of the form a b op. When an operator is followed for every pair of operands.
Note: The order of precedence is: ^ greater than * equals to / greater than + equals to -. Ignore the right associativity of ^.

Examples :

Input: s = "a+b*(c^d-e)^(f+g*h)-i"
Output: abcd^e-fgh*+^*+i-
Explanation: After converting the infix expression into postfix expression, the resultant expression will be abcd^e-fgh*+^*+i-
Input: s = "A*(B+C)/D"
Output: ABC+*D/
Explanation: After converting the infix expression into postfix expression, the resultant expression will be ABC+*D/
Input: s = "(a+b)*(c+d)"
Output: ab+cd+*
*/

class Solution {
  public:
  //Function to return precedence of operators
    int prec(char c) {
      if (c == '^')
        return 3;
      else if (c == '/' || c == '*')
        return 2;
      else if (c == '+' || c == '-')
        return 1;
      else
        return -1;
    }

    string infixToPostfix(string& s) {

      stack < char > st; //For stack operations, we are using C++ built in stack
      string result;
    
      for (int i = 0; i < s.length(); i++) {
        char c = s[i];
    
        // If the scanned character is
        // an operand, add it to output string.
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
          result += c;
    
        // If the scanned character is an
        // ‘(‘, push it to the stack.
        else if (c == '(')
          st.push('(');
    
        // If the scanned character is an ‘)’,
        // pop and to output string from the stack
        // until an ‘(‘ is encountered.
        else if (c == ')') {
          while (st.top() != '(') {
            result += st.top();
            st.pop();
          }
          st.pop();
        }
    
        //If an operator is scanned
        else {
          while (!st.empty() && prec(s[i]) <= prec(st.top())) {
            result += st.top();
            st.pop();
          }
          st.push(c);
        }
      }
    
      // Pop all the remaining elements from the stack
      while (!st.empty()) {
        result += st.top();
        st.pop();
      }
    
      return result;
    }
};
