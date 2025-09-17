/*
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

 

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]
 

Constraints:

1 <= candidates.length <= 100
1 <= candidates[i] <= 50
1 <= target <= 30
*/

class Solution {
public:
    void helper(int index, vector<int> & nums, vector<int> & curr, vector<vector<int>> & ans, int target)
    {
        if(0 == target) ans.push_back(curr);

        if(target<0) return;
        for(int i = index; i<nums.size(); ++i)
        {
            if(i>index && nums[i] == nums[i-1]) continue;

            curr.push_back(nums[i]);
            helper(i+1,nums,curr,ans,target-nums[i]);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> curr;

        helper(0,candidates,curr,ans,target);
        return ans;
    }
};