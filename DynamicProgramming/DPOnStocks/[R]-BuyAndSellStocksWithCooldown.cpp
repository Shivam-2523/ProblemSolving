/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: prices = [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]
Example 2:

Input: prices = [1]
Output: 0
 

Constraints:

1 <= prices.length <= 5000
0 <= prices[i] <= 1000
*/

class Solution {
public:
    int helper(int index, int buy, vector<vector<int>> & dp,int n, vector<int>& prices)
    {
        if(index >= n) return 0;
        if(dp[index][buy]!=-1) return dp[index][buy];
        auto price = 0;
        if(buy)
        {
            price = max((-prices[index] + helper(index+1,0,dp,n,prices)),helper(index+1,1,dp,n,prices));
        }else
        {
            price = max((prices[index] + helper(index+2,1,dp,n,prices)),helper(index+1,0,dp,n,prices));
        }

        return dp[index][buy] = price;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp (n+1,vector<int>(2,-1));
        return helper(0,1,dp,n,prices);
    }
};