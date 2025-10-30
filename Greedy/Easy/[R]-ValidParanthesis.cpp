/*
Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.

The following rules define a valid string:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "(*)"
Output: true
Example 3:

Input: s = "(*))"
Output: true
 

Constraints:

1 <= s.length <= 100
s[i] is '(', ')' or '*'.
*/


class Solution {
public:
    bool checkValidString(string s) {
        int low = 0, high = 0;

        for(char c : s) {
            if(c == '(') {
                low++;
                high++;
            }
            else if(c == ')') {
                low--;
                high--;
            }
            else { // c == '*'
                low--;  // assume '*' as ')'
                high++; // or assume '*' as '('
            }

            if(high < 0) 
                return false; // too many ')'

            if(low < 0) 
                low = 0; // we can't have less than 0 open brackets
        }

        return low == 0;
    }
};