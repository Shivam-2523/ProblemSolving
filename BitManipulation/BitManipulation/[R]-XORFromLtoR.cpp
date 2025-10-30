/*
You are given two integers L and R, your task is to find the XOR of elements of the range [L, R].

Example:

Input: 
L = 4, R = 8 
Output:
8 
Explanation:
4 ^ 5 ^ 6 ^ 7 ^ 8 = 8
Your Task:

Your task is to complete the function findXOR() which takes two integers l and r and returns the XOR of numbers from l to r.

Expected Time Complexity: O(1).

Expected Auxiliary Space: O(1).

Constraints:

1<=l<=r<=109
*/


// User function Template for C++

class Solution {
  public:
    int helper (int a)
    {
        //find XOR from 1 to a
        auto remainder = a % 4;
        if(remainder == 0)
            return a;
        else if (remainder == 1)
            return 1;
        else if (remainder == 2)
            return a + 1;
        else
            return 0;
        
        return -1;
    }
    int findXOR(int l, int r) {
        // complete the function here
       return helper(l-1) ^ helper(r);
        
    }
};

/*0001 //1 -> 1
0010 //2 -> 3
0011 //3 -> 0
0100 //0 -> Number itself

0101 //1 -> 1
0110 //2 -> 7
0111 //3 -> 0
1000 //0 ->Number itslef

1001
1010
1011
1100

01101
01110
01111
10000

x ^  y = ans

1101 ^ 0110 = 1011 */