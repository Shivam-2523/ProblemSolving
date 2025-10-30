/*
Given an integer array nums and an integer k, return the number of good subarrays of nums.

A good array is an array where the number of different integers in that array is exactly k.

For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
A subarray is a contiguous part of an array.

 

Example 1:

Input: nums = [1,2,1,2,3], k = 2
Output: 7
Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]
Example 2:

Input: nums = [1,2,1,3,4], k = 3
Output: 3
Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].
 

Constraints:

1 <= nums.length <= 2 * 104
1 <= nums[i], k <= nums.length
*/

class Solution {
public:
	int helper(vector<int>& nums, int k)
	{
		int l = 0, r = 0, ans = 0, n = nums.size();
		unordered_map<int,int> m;
		
		while(r<n)
		{
			m[nums[r]]++;
			while(m.size()>k)
			{
				m[nums[l]]--;
				if(m[nums[l]] == 0) m.erase(nums[l]);
				l++;
			}
			ans += r - l + 1;
			r++;
		}
		return ans;
	}
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return helper(nums,k) - helper(nums,k-1);
    }
};