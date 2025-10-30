/*
Given an integer array nums, return the length of the longest strictly increasing subsequence.

 

Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4
Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1
 

Constraints:

1 <= nums.length <= 2500
-104 <= nums[i] <= 104
 

Follow up: Can you come up with an algorithm that runs in O(n log(n)) time complexity?
*/

class Solution {
public:
    int helper (int index, int prevIndex, vector<vector<int>> & dp, vector<int>& nums, int n)
    {
        if(index == n) return 0;

        if(dp[index][prevIndex+1]!=-1) return dp[index][prevIndex+1];

        int len = 0 + helper(index+1,prevIndex,dp,nums,n);//not take
        if(prevIndex ==-1 || nums[prevIndex]<nums[index])//take
            len = max(len, 1 + helper(index+1,index,dp,nums,n));
        
        return dp[index][prevIndex+1] = len;
    }

    int lengthOfLISMemoization(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return helper(0,-1,dp,nums,n);
    }

    int lengthOfLISTabulation(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        // index goes from n-1 to 0
        for(int index = n-1; index >= 0; index--) {
            for(int prevIndex = index-1; prevIndex >= -1; prevIndex--) {
                // Not take current element
                int len = dp[index+1][prevIndex+1];
                // Take current element
                if(prevIndex == -1 || nums[prevIndex] < nums[index])
                    len = max(len, 1 + dp[index+1][index+1]);
                dp[index][prevIndex+1] = len;
            }
        }
        return dp[0][0];
    }

    int lengthOfLISTabulationSpaceOptim(vector<int>& nums) {
         int n = nums.size();
        if (n == 0) return 0;
        
        vector<int> dp(n, 1); // each element is at least a subsequence of length 1
        int ans = 1;
        
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
     
    }

    int GetInsertPos(vector<int>& nums, int a)
    {
        int l = 0, r = nums.size() - 1;    
        int ans = 0;
        while(l<=r)
        {
            int m = (l+r)/2;
            if(nums[m]>=a)
            {
                ans = m;
                r = m - 1;
            }else
                l = m + 1;
        }

        return ans;
    }

    int lengthOfLISBS(vector<int>& nums) {
        int n  = nums.size();
        vector<int> lis;
        lis.push_back(nums[0]);

        for(int i = 1; i<n; ++i)
        {
            if(nums[i]>lis[lis.size()-1])
            {
                lis.push_back(nums[i]);
            }else
            {
                int ind = GetInsertPos(lis,nums[i]);
                lis[ind] = nums[i];
            }
        }

        return lis.size();
    }

    int lengthOfLISWithPrint(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,1);
        int ans  = 0, length = 0;
        vector<int> track(n+1,0);

        for(int i = 1; i<=n; ++i)
            track[i] = i;

        for(int i = 1; i<=n; ++i)
        {
            for(int j = 1; j<=i; ++j)
            {
                if(nums[i-1]>nums[j-1])
                {
                    if(dp[j]+1 > dp[i])
                    {
                        dp[i] = 1+dp[j];
                        track[i] = j;
                    }
                }
            }
            if(dp[i]>length)
            {
                ans = i;
                length = dp[i];
            }
        }
        int lisL = length;
        vector<int> lis;
        while(length>0)
        {
            lis.push_back(nums[ans-1]);
            length--;
            ans = track[ans];
        }
        reverse(lis.begin(),lis.end());
        for(auto i: track)
            cout<<i<<" ";
        return lisL;
    }
    //for printing keep a track of last index from where the subseq is getting created
    //and then first add the last index that has been considered in the subseq, and then
    //loop back from it till the total length of LIS

    int lengthOfLIS(vector<int>& nums) {
        return lengthOfLISWithPrint(nums);
    }
};

//Let dp[i] be the length of the LIS ending at index i.
//For each index i, look back at all indices j < i:
//If nums[j] < nums[i], try to extend the subsequence ending at j to i.