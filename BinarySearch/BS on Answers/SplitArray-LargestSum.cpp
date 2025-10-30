/*
Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.

Return the minimized largest sum of the split.

A subarray is a contiguous part of the array.

 

Example 1:

Input: nums = [7,2,5,10,8], k = 2
Output: 18
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.
Example 2:

Input: nums = [1,2,3,4,5], k = 2
Output: 9
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [1,2,3] and [4,5], where the largest sum among the two subarrays is only 9.
 

Constraints:

1 <= nums.length <= 1000
0 <= nums[i] <= 106
1 <= k <= min(50, nums.length)
*/




class Solution {
public:
    bool helperFunction (vector<int> & boards, int k, int t)
    {
        int time = 0, count = 1;

        for(auto i: boards)
        {
            if(time+i>t)
            {
                count++;
                time = i;
                if(count>k)return false;
            }else
            {
                time+=i;
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {

        int l = *max_element(nums.begin(),nums.end());
        int r = 0, ans = 0;
        for(auto i: nums)
            r+=i;
    
        while(l<=r)
        {
            int mid = (l+r)/2;
            if(helperFunction(nums,k,mid))
            {
                ans  = mid;
                r = mid - 1;
            }else
            {
                l = mid + 1;
            }
        }
        return ans;
    }
};