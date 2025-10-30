/*
You are given a stack st[]. You have to reverse the stack.

Examples:

Input: st[] = [1, 2, 3, 4]
Output: [1, 2, 3, 4]
Explanation: After reversing, the elements of stack are in opposite order.

Input: st[] = [3, 2, 1]
Output: [3, 2, 1]
Explanation: After reversing, the elements of stack are in opposite order.

Constraints:
1 ≤ st.size() ≤ 100
0 ≤ stack element ≤ 100
*/



class Solution {
  public:
    void helper(stack<int> & s, int val)
    {
        if(s.empty())
        {
            s.push(val);
            return;
        }
        
        auto a = s.top();
        s.pop();
        helper(s,val);
        s.push(a);
    }
    void reverse(stack<int> &St) {
        // code here
        if(St.empty()) 
            return;
        
        auto a = St.top();
        St.pop();
        reverse(St);
        helper(St,a);
    }
};