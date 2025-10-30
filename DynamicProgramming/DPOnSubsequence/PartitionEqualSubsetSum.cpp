/*
Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

 

Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
 

Constraints:

1 <= nums.length <= 200
1 <= nums[i] <= 100
*/

class Solution {
public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        vector<vector<bool>> dp(n+1,vector<bool>(sum+1,false));
        
        for(int i= 0;i<=n; i++)
            dp[i][0] = true;
            
        for(int i = 1; i<=n; i++)
        {
            for(int j = 1; j<=sum; j++)
            {
                if(arr[i-1]<=j)
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][sum];
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto i: nums)
            sum+=i;
        
        if(sum%2) return false; //with odd numbers you cannot divide into two equal subset

        sum /= 2;

        return isSubsetSum(nums,sum);
    }
};