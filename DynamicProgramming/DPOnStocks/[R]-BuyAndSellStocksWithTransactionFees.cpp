/*
You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.

Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

Note:

You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
The transaction fee is only charged once for each stock purchase and sale.
 

Example 1:

Input: prices = [1,3,2,8,4,9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
- Buying at prices[0] = 1
- Selling at prices[3] = 8
- Buying at prices[4] = 4
- Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
Example 2:

Input: prices = [1,3,7,5,10,3], fee = 3
Output: 6
 

Constraints:

1 <= prices.length <= 5 * 104
1 <= prices[i] < 5 * 104
0 <= fee < 5 * 104
*/

class Solution {
public:
    int helper(int index, int buy, vector<vector<int>> & dp,int n, vector<int>& prices,int & fee)
    {
        if(index == n) return 0;
        if(dp[index][buy]!=-1) return dp[index][buy];
        auto price = 0;
        if(buy)
        {
            price = max((-prices[index] + helper(index+1,0,dp,n,prices,fee)),helper(index+1,1,dp,n,prices,fee));
        }else
        {
            price = max((prices[index] + helper(index+1,1,dp,n,prices,fee) - fee),helper(index+1,0,dp,n,prices,fee));
        }

        return dp[index][buy] = price;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        /*vector<vector<int>> dp (n+1,vector<int>(2,-1));
        return helper(0,1,dp,n,prices,fee);//for memoization*/

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
                    a = max((prices[i] + v[1] - fee),v[0]);
                }
            }
            v[0] = a;
            v[1] = b;
        }

        return v[1];
    }
};