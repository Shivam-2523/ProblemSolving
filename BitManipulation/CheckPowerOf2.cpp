/*
Given an integer n, return true if it is a power of two. Otherwise, return false.

An integer n is a power of two, if there exists an integer x such that n == 2x.

 

Example 1:

Input: n = 1
Output: true
Explanation: 20 = 1
Example 2:

Input: n = 16
Output: true
Explanation: 24 = 16
Example 3:

Input: n = 3
Output: false
 

Constraints:

-231 <= n <= 231 - 1
 

Follow up: Could you solve it without loops/recursion?
*/


class Solution {
public:
    bool isPowerOfTwo(int n) {
        int count = 0;
        if(n<0)return false;
        for(int i = 0; i<32; i++)
        {
            if(((n>>i)&1) == 1)
                count++;
            if(count>1)
                break;
        }
        return (count==1);
    }
};