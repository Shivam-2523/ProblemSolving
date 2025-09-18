/*
Given an array arr and target sum k, check whether there exists a subsequence such that the sum of all elements in the subsequence equals the given target sum(k).


Example:

Input:  arr = [10,1,2,7,6,1,5], k = 8.
Output:  Yes
Explanation:  Subsequences like [2, 6], [1, 7] sum upto 8

Input:  arr = [2,3,5,7,9], k = 100. 
Output:  No
Explanation:  No subsequence can sum upto 100
Your Task:
You don't need to read or print anything. Your task is to complete the boolean function checkSubsequenceSum() which takes N, arr and K as input parameter and returns true/false based on the whether any subsequence with sum K could be found.


Expected Time Complexity: O(N * K).
Expected Auxiliary Space: O(N * K).


Constraints:
1 <= arr.length <= 2000.
1 <= arr[i] <= 1000.
1 <= target <= 2000.
*/

class Solution {
  public:
    void helper(int index, vector<int>& nums, int sum, int target, bool &flag, int count) {
        if(flag)
            return;
        if(index == nums.size()) {
            if(sum == target && count > 0) // count>0 ensures non-empty
                flag = true;
            return;
        }
        // exclude current index
        helper(index+1, nums, sum, target, flag, count);
        // include current index
        helper(index+1, nums, sum+nums[index], target, flag, count+1);
    }
    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        bool flag = false;
        helper(0, arr, 0, k, flag, 0);
        return flag;
    }
};

