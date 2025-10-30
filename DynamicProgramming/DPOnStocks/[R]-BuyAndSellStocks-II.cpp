/*
You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can sell and buy the stock multiple times on the same day, ensuring you never hold more than one share of the stock.

Find and return the maximum profit you can achieve.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.
Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Total profit is 4.
Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.
 

Constraints:

1 <= prices.length <= 3 * 104
0 <= prices[i] <= 104
*/

class Solution {
public:
    int helper(int index, int buy, vector<vector<int>> & dp,int n, vector<int>& prices)
    {
        if(index == n) return 0;
        if(dp[index][buy]!=-1) return dp[index][buy];
        auto price = 0;
        if(buy)
        {
            price = max((-prices[index] + helper(index+1,0,dp,n,prices)),helper(index+1,1,dp,n,prices));
        }else
        {
            price = max((prices[index] + helper(index+1,1,dp,n,prices)),helper(index+1,0,dp,n,prices));
        }

        return dp[index][buy] = price;
    }
    int maxProfitWithoutSpaceOptimization(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp (n+1,vector<int>(2,-1));
        //return helper(0,1,dp,n,prices); for memoization

        dp[n][0] = dp[n][1] = 0;

        for(int i = n-1; i>=0; --i)
        {
            for(int j = 0; j<=1; ++j)
            {
                if(j)
                {
                    dp[i][j] = max((-prices[i] + dp[i+1][0]),dp[i+1][1]);
                }else
                {
                    dp[i][j] = max((prices[i] + dp[i+1][1]),dp[i+1][0]);
                }
            }
        }

        return dp[0][1];
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<int> v (2,0);
        for(int i = n-1; i>=0; --i)
        {
            int a = 0, b = 0;
            for(int j = 0; j<=1; ++j)
            {
                if(j)
                {
                    b = max((-prices[i] + v[0]),v[1]);
                }else
                {
                    a = max((prices[i] + v[1]),v[0]);
                }
            }
            v[0] = a;
            v[1] = b;
        }

        return v[1];
    }
};