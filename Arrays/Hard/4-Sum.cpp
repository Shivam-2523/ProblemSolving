/*
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

 

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
 

Constraints:

1 <= nums.length <= 200
-109 <= nums[i] <= 109
-109 <= target <= 109
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end()); //sorting - nlogn
        vector<vector<int>> ans;

        //looping on the array
        for(int i = 0; i<n; i++)//fixing first number
        {
            if(i>0 && nums[i] == nums[i-1]) continue; //repeating

            for(int j = i+1; j<n; j++)//fixing second number
            {
                if(j>i+1 && nums[j] == nums[j-1]) continue; //repeating second value

                int l = j+1;
                int r = n-1;

                //applying two pointer
                while(l<r)
                {
                    long long sum = (long long)nums[i] + nums[j] + nums[l] + nums[r];
                    if(sum == target)
                    {
                        ans.push_back({nums[i],nums[j],nums[l],nums[r]});
                        while(l<r && nums[l] == nums[l+1]) l++;
                        while(l<r && nums[r] == nums[r-1]) r--;
                        l++;r--;
                    }
                    else if(sum<target) l++;
                    else r--;
                }
            }
        }
        return ans;
    }
};