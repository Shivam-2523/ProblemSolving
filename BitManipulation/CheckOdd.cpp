/*
Given a positive integer n, determine whether it is odd or even. Return true if the number is even and false if the number is odd.

Examples:

Input: n = 15
Output: false
Explanation: The number is not divisible by 2
Input: n = 44
Output: true
Explanation: The number is divisible by 2
Constraints:
0 <= n <= 104
*/


class Solution {
  public:
    bool isEven(int n) {
        // code here
        return ((n&1) == 0);
    }
};