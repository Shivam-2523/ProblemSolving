/*
Given an infinite supply of each denomination of Indian currency { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 } and a target value N.
Find the minimum number of coins and/or notes needed to make the change for Rs N. You must return the list containing the value of coins required. 


Example 1:

Input: N = 43
Output: 20 20 2 1
Explaination: 
Minimum number of coins and notes needed 
to make 43. 

Example 2:

Input: N = 1000
Output: 500 500
Explaination: minimum possible notes
is 2 notes of 500.

Your Task:
You do not need to read input or print anything. Your task is to complete the function minPartition() which takes the value N as input parameter and returns a list of integers in decreasing order.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)


Constraints:
1 ≤ N ≤ 106
*/



// User function Template for C++

class Solution {
  public:
    vector<int> minPartition(int N) {
        // code here
            // Available coin denominations
        vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
        int n = coins.size();

        // DP array, initialized to a large number (INT_MAX)
        vector<int> dp(N + 1, INT_MAX);
        dp[0] = 0; // 0 coins are needed to make amount 0

        // Update dp array for each coin
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j < n; j++) {
                if (i - coins[j] >= 0 && dp[i - coins[j]] != INT_MAX) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }

        // If dp[N] is still INT_MAX, it means it's impossible to make the change
        if (dp[N] == INT_MAX) {
            return {}; // No solution
        }

        // Backtrack to find the coins used
        vector<int> result;
        int remainingAmount = N;
        while (remainingAmount > 0) {
            for (int i = n - 1; i >= 0; i--) {
                if (remainingAmount >= coins[i] && dp[remainingAmount - coins[i]] == dp[remainingAmount] - 1) {
                    result.push_back(coins[i]);
                    remainingAmount -= coins[i];
                    break;
                }
            }
        }

        return result;
    }
};