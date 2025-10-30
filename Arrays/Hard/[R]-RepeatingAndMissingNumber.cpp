/*
Given an unsorted array arr of positive integers. One number a from the set [1, 2,....,n] is missing and one number b occurs twice in the array. Find numbers a and b.

Note: The test cases are generated such that there always exists one missing and one repeating number within the range [1,n].

Examples:

Input: arr[] = [2, 2]
Output: [2, 1]
Explanation: Repeating number is 2 and smallest positive missing number is 1.
Input: arr[] = [1, 3, 3] 
Output: [3, 2]
Explanation: Repeating number is 3 and smallest positive missing number is 2.
Input: arr[] = [4, 3, 6, 2, 1, 1]
Output: [1, 5]
Explanation: Repeating number is 1 and the missing number is 5.
Constraints:
2 ≤ arr.size() ≤ 106
1 ≤ arr[i] ≤ arr.size()
*/

class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        int n = arr.size();
        int repeating = -1, missing = -1;
    
        // Step 1: Mark visited using negation
        for (int i = 0; i < n; i++) {
            int idx = abs(arr[i]) - 1;
            if (arr[idx] < 0) {
                repeating = abs(arr[i]);  // seen before = repeating
            } else {
                arr[idx] *= -1;  // mark as visited
            }
        }
    
        // Step 2: Find the index which is still positive → missing number
        for (int i = 0; i < n; i++) {
            if (arr[i] > 0) {
                missing = i + 1;
                break;
            }
        }
    
        return {repeating, missing};
    }
};