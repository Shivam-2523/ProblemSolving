/*
Given a non-negative number n . The problem is to set the rightmost unset bit in the binary representation of n.

Examples :

Input: n = 6
Output: 7
Explanation: The binary representation of 6 is 110. After setting right most bit it becomes 111 which is 7.
Input: n = 15
Output: 31
Explanation: The binary representation of 15 is 01111. After setting right most bit it becomes 11111 which is 31.
Expected Time Complexity: O(Logn)
Expected Auxiliary Space: O(1)


Constraints:
1 <= n <= 109
*/


class Solution {
  public:
    int setBit(int n) {
        // Write Your Code here
        for(int i = 0; i<32; i++)
        {
            if(((n>>i)&1)==0)
            {
                n |= (1<<i);
                break;
            }
        }
        return n;
    }
};