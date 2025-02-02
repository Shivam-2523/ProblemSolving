/*
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109
*/


class Solution {
public:
    int first (vector<int> nums, int target)
    {
        int ans = -1;
        int l =0, r = nums.size()-1;
        while(l<=r)
        {
            int m = (l+r)/2;
            if(nums[m] == target)
            {
                ans = m;
                r = m-1;
            } else if(nums[m]>target)
                r = m-1;
            else
                l = m+1;
        }
        return ans;
    }
    int last (vector<int> nums, int target)
    {
        int ans = -1;
        int l =0, r = nums.size()-1;
        while(l<=r)
        {
            int m = (l+r)/2;
            if(nums[m] == target)
            {
                ans = m;
                l = m+1;
            } else if(nums[m]>target)
                r = m-1;
            else
                l = m+1;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        return {first(nums, target),last(nums,target)};
    }
};