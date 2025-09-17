/*
Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
*/

class Solution {
public:
    void helper(
        int index, 
        vector<int>& nums, 
        vector<int>& curr, 
        vector<vector<int>>& ans
    ) {
        ans.push_back(curr); // Add every subset at every step

        for (int i = index; i < nums.size(); ++i) {
            // If this is a duplicate and NOT at the beginning of this recursion level, skip it
            if (i > index && nums[i] == nums[i-1])
                continue;

            curr.push_back(nums[i]);
            helper(i+1, nums, curr, ans);
            curr.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(nums.begin(), nums.end()); // So duplicates are adjacent
        helper(0, nums, curr, ans);
        return ans;
    }
};

