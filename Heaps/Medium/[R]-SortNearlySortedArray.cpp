/*
Given an array arr[], where each element is at most k away from its target position, you need to sort the array optimally.
Note: You need to change the given array arr[] in place.

Examples:

Input: arr[] = [6, 5, 3, 2, 8, 10, 9], k = 3
Output: [2, 3, 5, 6, 8, 9, 10]
Explanation: The sorted array will be 2 3 5 6 8 9 10
Input: arr[]= [1, 4, 5, 2, 3, 6, 7, 8, 9, 10], k = 2
Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
Explanation: The sorted array will be 1 2 3 4 5 6 7 8 9 10
Don't use the inbuilt sort() function for this question.

Constraints:
1 ≤ arr.size() ≤ 106
0 ≤ k < arr.size()
1 ≤ arri ≤ 106
*/

class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        // code
        priority_queue<int, vector<int>, greater<int>> pq;
        int n = arr.size();
        
        for(int i = 0; i<=k; ++i)
            pq.push(arr[i]);
        
        int index = 0;
        for(int i = k+1; i<n; i++)
        {
            arr[index++] = pq.top();
            pq.pop();
            pq.push(arr[i]);
        }
        
        while(!pq.empty())
        {
            arr[index++]=pq.top();
            pq.pop();
        }
    }
};
/*Every element is at most k positions away from its correct sorted position. That means:

The smallest element in the entire array must be within the first k+1 elements (from index 0 to k).

The next smallest (i.e. second smallest) must be in the range 1 to k+1.

And so on.*/