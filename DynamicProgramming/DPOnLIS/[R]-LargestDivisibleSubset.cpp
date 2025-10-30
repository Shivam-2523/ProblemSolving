/*
Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:

answer[i] % answer[j] == 0, or
answer[j] % answer[i] == 0
If there are multiple solutions, return any of them.

 

Example 1:

Input: nums = [1,2,3]
Output: [1,2]
Explanation: [1,3] is also accepted.
Example 2:

Input: nums = [1,2,4,8]
Output: [1,2,4,8]
 

Constraints:

1 <= nums.length <= 1000
1 <= nums[i] <= 2 * 109
All the integers in nums are unique.
*/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n, 1), trace(n, -1);
        int maxSize = 1, maxIndex = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i]%nums[j] == 0) { // Only need i%j because nums sorted
                    if (dp[j]+1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        trace[i] = j;
                    }
                }
            }
            if (dp[i] > maxSize) {
                maxSize = dp[i];
                maxIndex = i;
            }
        }

        vector<int> result;
        int k = maxIndex;
        while (k != -1) {
            result.push_back(nums[k]);
            k = trace[k];
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
/*
Sorting allows you to grow the subset bottom-up, using dynamic programming, where each next number is guaranteed to be at least as large as the previous, and we can always check divisibility from left to right.
*/