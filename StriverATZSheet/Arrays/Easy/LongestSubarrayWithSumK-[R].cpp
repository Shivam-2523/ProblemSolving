/*
Given an array arr[] containing integers and an integer k, your task is to find the length of the longest subarray where the sum of its elements is equal to the given value k. If there is no subarray with sum equal to k, return 0.

Examples:

Input: arr[] = [10, 5, 2, 7, 1, -10], k = 15
Output: 6
Explanation: Subarrays with sum = 15 are [5, 2, 7, 1], [10, 5] and [10, 5, 2, 7, 1, -10]. The length of the longest subarray with a sum of 15 is 6.
Input: arr[] = [-5, 8, -14, 2, 4, 12], k = -5
Output: 5
Explanation: Only subarray with sum = 15 is [-5, 8, -14, 2, 4] of length 5.
Input: arr[] = [10, -10, 20, 30], k = 5
Output: 0
Explanation: No subarray with sum = 5 is present in arr[].
Constraints:
1 ≤ arr.size() ≤ 105
-104 ≤ arr[i] ≤ 104
-109 ≤ k ≤ 109
*/

    int longestSubarray(vector<int>& arr, int k) {
        int n = arr.size();
        int curr_sum = 0, req_prefix_sum;
        int max_subarr_len = 0;
        unordered_map<int, int> prefix_sum;
        
        prefix_sum[0] = -1;
        for(int i=0; i<n; i++) {
            curr_sum += arr[i];
            if(prefix_sum.find(curr_sum - k) != prefix_sum.end()) {
                max_subarr_len = max(max_subarr_len, i - prefix_sum[curr_sum - k]);    
            } 
            
	    //if we find the prefix sum again the no need to add that, as the removing the first occurence would give a longer subarray
            if(prefix_sum.find(curr_sum)==prefix_sum.end()) {
                prefix_sum[curr_sum] = i;                
            } 
        }
        return max_subarr_len;
    }