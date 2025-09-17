/*
Given a stack of integers st[]. Sort the stack in ascending order (smallest element at the bottom and largest at the top).

Examples:

Input: st[] = [1, 2, 3]
Output: [3, 2, 1]
Explanation: The stack is already sorted in ascending order.

Input: st[] = [41, 3, 32, 2, 11]
Output: [41, 32, 11, 3, 2]
Explanation: After sorting, the smallest element (2) is at the bottom and the largest element (41) is at the top.

Constraints:
1 ≤ st.size() ≤ 103
0 ≤ stack element ≤ 103
*/

/*The structure of the class is
class SortedStack{
public:
    stack<int> s;
    void sort();
};
*/

/* The below method sorts the stack s
you are required to complete the below method */

void helper(stack<int> & s, int x)
{
    if (s.empty() || x > s.top()) {
        s.push(x);
        return;
    }
    int temp = s.top();
    s.pop();
    helper(s, x);
    s.push(temp);
}

void sorting(stack<int> & s)
{
    if(!s.empty())
    {
        int a  = s.top();
        s.pop();
        sorting(s);
        helper(s,a);
    }
}
void SortedStack ::sort() {
    sorting(s);
}
