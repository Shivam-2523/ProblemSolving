/*
You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
Example 2:

Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
 

Constraints:

1 <= k <= 100
1 <= prices.length <= 1000
0 <= prices[i] <= 1000
*/

class Solution {
public:
    int helper(int index, int buy, int count, vector<vector<vector<int>>> & dp, vector<int>& prices,int k) {
        if(count == k || index == prices.size()) return 0;
        if(dp[index][buy][count]!=-1) return dp[index][buy][count];

        int price = 0;
        if(buy){
            price = max(
                -prices[index] + helper(index+1, 0, count, dp, prices,k), // buy
                helper(index+1, 1, count, dp, prices,k) // skip
            );
        } else {
            price = max(
                prices[index] + helper(index+1, 1, count+1, dp, prices,k), // sell (and increase count)
                helper(index+1, 0, count, dp, prices,k) // skip
            );
        }
        return dp[index][buy][count] = price;
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));
        return helper(0, 1, 0, dp, prices,k);
    }
};
