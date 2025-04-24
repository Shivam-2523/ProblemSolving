/*
Given an array arr containing both positive and negative integers, the task is to compute the length of the largest subarray that has a sum of 0.

Examples:

Input: arr[] = [15, -2, 2, -8, 1, 7, 10, 23]
Output: 5
Explanation: The largest subarray with a sum of 0 is [-2, 2, -8, 1, 7].
Input: arr[] = [2, 10, 4]
Output: 0
Explanation: There is no subarray with a sum of 0.
Input: arr[] = [1, 0, -4, 3, 1, 0]
Output: 5
Explanation: The subarray is [0, -4, 3, 1, 0].
Constraints:
1 ≤ arr.size() ≤ 106
−103 ≤ arr[i] ≤ 103, for each valid i
*/

class Solution {
  public:
    int maxLen(vector<int>& arr) {
        int n = arr.size();
        map<int,int> prefixSum;
        int k = 0;
        prefixSum[0]=-1;
        int currSum = 0;
        int max_len = 0;
        
        for(int i =0; i<n; i++)
        {
            currSum+=arr[i];
            if(prefixSum.find(currSum-k)!=prefixSum.end())
                max_len = max(max_len,i-prefixSum[currSum-k]);
            if(prefixSum.find(currSum)==prefixSum.end())
                prefixSum[currSum]=i;
        }
        return max_len;
    }
};