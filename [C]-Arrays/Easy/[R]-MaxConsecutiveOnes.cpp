/*
Given a binary array nums, return the maximum number of consecutive 1's in the array.

 

Example 1:

Input: nums = [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.
Example 2:

Input: nums = [1,0,1,1,0,1]
Output: 2
  
*/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int l = 0, r = 0, n = nums.size(), ans = 0;

        while(r<n)
        {
            if(nums[r] != 1)
            {
                ans = max(ans,r-l);
                l = r+1;
            }  
            r++;
        }
        ans = max(r-l,ans);
        return ans;
    }
};