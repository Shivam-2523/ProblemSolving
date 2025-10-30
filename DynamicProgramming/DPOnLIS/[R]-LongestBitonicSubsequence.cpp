/*
Given an array of positive integers. Find the maximum length of Bitonic subsequence. 
A subsequence of array is called Bitonic if it is first strictly increasing, then strictly decreasing. Return the maximum length of bitonic subsequence.
 
Note : A strictly increasing or a strictly decreasing sequence should not be considered as a bitonic sequence

Examples :

Input: n = 5, nums[] = [1, 2, 5, 3, 2]
Output: 5
Explanation: The sequence {1, 2, 5} is increasing and the sequence {3, 2} is decreasing so merging both we will get length 5.
Input: n = 8, nums[] = [1, 11, 2, 10, 4, 5, 2, 1]
Output: 6
Explanation: The bitonic sequence {1, 2, 10, 4, 2, 1} has length 6.
Input: n = 3, nums[] = [10, 20, 30]
Output: 0
Explanation: The decreasing or increasing part cannot be empty
Input: n = 3, nums[] = [10, 10, 10]
Output: 0
Explanation: The subsequences must be strictly increasing or decreasing
Constraints:
1 ≤ length of array ≤ 103
1 ≤ arr[i] ≤ 104
*/

class Solution {
public:
    int LongestBitonicSequence(int n, vector<int> &nums) {
        vector<int> inc(n, 1);  // LIS ending at i
        vector<int> dec(n, 1);  // LDS starting at i
        
        // Compute LIS for each i (ending at i)
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i])
                    inc[i] = max(inc[i], inc[j] + 1);
            }
        }
        
        // Compute LDS for each i (starting at i)
        for (int i = n-1; i >=0; --i) {
            for (int j = n-1; j > i; --j) {
                if (nums[j] < nums[i])
                    dec[i] = max(dec[i], dec[j] + 1);
            }
        }
        
        int ans = 0;
        for (int i=0; i<n; ++i) {
            // We need at least 2 in increasing part and 2 in decreasing part (so total >=3)
            if (inc[i] > 1 && dec[i] > 1) {
                ans = max(ans, inc[i] + dec[i] - 1);
            }
        }
        // If no valid peak exists, that means no bitonic subsequence
        return ans;
    }
};