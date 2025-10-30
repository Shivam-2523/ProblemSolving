/*
Given a rod of length n inches and an array price[], where price[i] denotes the value of a piece of length i. Your task is to determine the maximum value obtainable by cutting up the rod and selling the pieces.

Note: n = size of price, and price[] is 1-indexed array.

Example:

Input: price[] = [1, 5, 8, 9, 10, 17, 17, 20]
Output: 22
Explanation: The maximum obtainable value is 22 by cutting in two pieces of lengths 2 and 6, i.e., 5 + 17 = 22.
Input: price[] = [3, 5, 8, 9, 10, 17, 17, 20]
Output: 24
Explanation: The maximum obtainable value is 24 by cutting the rod into 8 pieces of length 1, i.e, 8*price[1] = 8*3 = 24.
Input: price[] = [3]
Output: 3
Explanation: There is only 1 way to pick a piece of length 1.
Constraints:
1 ≤ price.size() ≤ 103
1 ≤ price[i] ≤ 106
*/

// User function Template for C++

class Solution {
  public:
    int cutRod(vector<int> &price) {
        // code here
        int n = price.size();
        vector<int> dp (n+1,0); //max price that can be get by cutting rod of length i
        dp[0] = 0;//0 length rod will generate price 0
        
        for(int i = 1; i<=n; ++i)
        {
            for(int j = 1; j<=i; ++j)
            {
                if(i-j >= 0)
                {
                    dp[i] = max(dp[i], dp[i-j]+price[j-1]);
                }
            }
        }
        
        return dp[n];
    }
};