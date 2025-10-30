/*
Given an array of arr[] and Q queries of indices. For each query indices[i], determine the count of elements in arr that are strictly greater than arr[indices[i]] to its right (after the position indices[i]).

Examples :

Input: arr[] = [3, 4, 2, 7, 5, 8, 10, 6], queries = 2, indices[] = [0, 5]
Output:  [6, 1]
Explanation: The next greater elements to the right of 3(index 0) are 4,7,5,8,10,6. The next greater elements to the right of 8(index 5) is only 10.
Input: arr[] = [1, 2, 3, 4, 1], queries = 2, indices[] = [0, 3]
Output:  [3, 0]
Explanation: The count of numbers to the right of index 0 which are greater than arr[0] is 3 i.e. (2, 3, 4). Similarly, the count of numbers to the right of index 3 which are greater than arr[3] is 0, since there are no greater elements than 4 to the right of the array.
*/


class Solution {
  public:
//we starting from end as we need the values that are on the right of a element 
    vector<int> count_NGE(vector<int> &arr, vector<int> &indices) {
        int n = arr.size();
        vector<int> rightCount(n, 0);
        multiset<int> s;  // multiset handles duplicates gracefully
    
        // Process from right to left
        for (int i = n - 1; i >= 0; --i) {
            // Find how many elements greater than arr[i] already in the set
            // Elements in s are sorted, so s.upper_bound(arr[i]) gives iterator to first greater
            auto it = s.upper_bound(arr[i]);
            rightCount[i] = distance(it, s.end());
            s.insert(arr[i]);
        }
        // Build answer for queries
        vector<int> answers;
        for (int idx : indices) answers.push_back(rightCount[idx]);
        return answers;
    }
};