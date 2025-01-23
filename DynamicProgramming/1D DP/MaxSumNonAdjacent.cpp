/*
Given an array arr containing positive integers. Find the maximum sum of any possible subsequence such that no two numbers in the subsequence should be adjacent in array arr.

Examples:

Input: arr[] = [5, 5, 10, 100, 10, 5]
Output: 110
Explanation: If you take indices 0, 3 and 5, then = 5+100+5 = 110.
Input: arr[] = [3, 2, 7, 10]
Output: 13
Explanation: 3 and 10 forms a non continuous subsequence with maximum sum.
Input: arr[] = [9, 1, 6, 10]
Output: 19
Explanation: 9 and 10 forms a non continuous subsequence with maximum sum.
Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ arri ≤ 105
*/

class Solution {
  public:
    int f (int n, vector<int> & dp, vector<int>& arr)
    {
        if(n==1)
            return dp[0];
            
        if(dp[n-1]!=-1)return dp[n-1];
        
        return dp[n-1] = max(f(n-1,dp,arr),f(n-3,dp,arr)+arr[n-1]);
    }
    // calculate the maximum sum with out adjacent
    int findMaxSum(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        vector<int> dp (n,-1);
        dp[0] = arr[0];
        dp[1] = max(arr[0],arr[1]);
        
        return f(n,dp,arr);
        if(n == 1)
            return arr[0];
            
        dp[0] = arr[0];
        dp[1] = max(arr[0],arr[1]);
        for(int i =2; i<n; i++)
        {
            dp[i] = max(dp[i-1],dp[i-2]+arr[i]);
        }
        return dp[n-1];
    }
};
