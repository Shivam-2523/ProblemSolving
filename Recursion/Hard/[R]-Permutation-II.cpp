/*
Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

 

Example 1:

Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]
Example 2:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 

Constraints:

1 <= nums.length <= 8
-10 <= nums[i] <= 10
*/

class Solution {
public:
    void helper(vector<int>& nums, vector<bool>& used, vector<int>& curr, vector<vector<int>>& ans) {
        if (curr.size() == nums.size()) {
            ans.push_back(curr);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            // Skip used number
            if (used[i]) continue;
            // Skip duplicates
            if (i > 0 && nums[i] == nums[i-1] && !used[i-1]) continue;

            curr.push_back(nums[i]);
            used[i] = true;

            helper(nums, used, curr, ans);

            curr.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        helper(nums, used, curr, ans);
        return ans;
    }
};
