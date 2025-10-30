/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

You may assume that you have an infinite number of each kind of coin.

The answer is guaranteed to fit into a signed 32-bit integer.

 

Example 1:

Input: amount = 5, coins = [1,2,5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
Example 2:

Input: amount = 3, coins = [2]
Output: 0
Explanation: the amount of 3 cannot be made up just with coins of 2.
Example 3:

Input: amount = 10, coins = [10]
Output: 1
 

Constraints:

1 <= coins.length <= 300
1 <= coins[i] <= 5000
All the values of coins are unique.
0 <= amount <= 5000
*/

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<unsigned long long> dp(amount + 1, 0);
        dp[0] = 1;
        
        for (int coin : coins) {
            for (int j = coin; j <= amount; j++) {
                dp[j] += dp[j - coin];
            }
        }
        
        return dp[amount];
    }
};
/*
The Intuitive Reason

When amount is outside: "Given an amount, for each way I could finish it, try all coins: That is, 'add a coin', for every coin."

This means [1,2] and [2,1] are counted as different—order matters.

When coin is outside: For each coin, for every amount >= that coin, update your ways. This is like “build all combinations using this coin (in any count) and all previously considered coins.”

This allows only combinations—[1,2] and [2,1] are the same.

3. Example: coins = [1,2], amount = 3

Let's write out the different orders:
Permutations counted (wrong for combination problem):

1+1+1
1+2
2+1
This is 3 ways.

Combinations counted (correct for this problem!):

1+1+1
1+2 (which is the same as 2+1, only count once)
This is 2 ways.

Let’s dry run both codes:
(A) Outer: amount, Inner: coin (Permutations):
Set dp[0] = 1

i = 1:
coin = 1: dp[1] += dp[0] --> dp[1] = 1
coin = 2: dp[1] += dp[-1] (skip)
i = 2:
coin = 1: dp[2] += dp[1] --> dp[2] = 1
coin = 2: dp[2] += dp[0] --> dp[2] = 2
i = 3:
coin = 1: dp[3] += dp[2] --> dp[3] = 2
coin = 2: dp[3] += dp[1] --> dp[3] = 3
So dp[3] = 3 (permutations: 1+2 and 2+1 are different)

(B) Outer: coin, Inner: amount (Combinations):
Set dp[0] = 1

coin = 1:

i = 1: dp[1] += dp[0] --> dp[1] = 1
i = 2: dp[2] += dp[1] --> dp[2] = 1
i = 3: dp[3] += dp[2] --> dp[3] = 1
coin = 2:

i = 2: dp[2] += dp[0] --> dp[2] = 2
i = 3: dp[3] += dp[1] --> dp[3] = 2
So dp[3] = 2 (combinations: 1+2 and 2+1 count as the same way)

4. Analogy/Intuition

Outer amount: Like building sequences: “At each step, try every coin.”
This counts all orderings.
Outer coin: Like “for each set of coins, build bigger totals,” layering in more coin types as you go.
Each buildup only finds unique coin combinations, not orderings.
5. One-Liner Rule of Thumb

Permutations (order matters): inner loop = choices.
Combinations (order doesn't): outer loop = choices.
*/