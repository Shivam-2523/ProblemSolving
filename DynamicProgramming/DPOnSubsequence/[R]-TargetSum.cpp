/*
You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.

 

Example 1:

Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3
Example 2:

Input: nums = [1], target = 1
Output: 1
 

Constraints:

1 <= nums.length <= 20
0 <= nums[i] <= 1000
0 <= sum(nums[i]) <= 1000
-1000 <= target <= 1000
*/

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;

        for(auto i: nums) sum += i;

        if(target > sum || target <-sum) return 0;
        
        int s  = (target + sum ) /2;
        vector<int> dp (s+ 1, 0);
        dp[0] = 1;

        for(int i = 0; i<n; ++i)
        {
            for(int j = s; j>=nums[i]; --j)
            {
                dp[j] += dp[j-nums[i]];
            }
        }

        return dp[s];
    }
};
/*
The key insight is to reformulate the problem:

We want:
Sum(positive numbers) - Sum(negative numbers) = target

Let:

P = Sum of positive numbers

N = Sum of negative numbers (as positive value)

We have:

P - N = target

P + N = totalSum (where totalSum is sum of all numbers)

Add these two equations:
(P - N) + (P + N) = target + totalSum
2P = target + totalSum
P = (target + totalSum) / 2

So the problem becomes: Find the number of subsets that sum to (target + totalSum) / 2
*/