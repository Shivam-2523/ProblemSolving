/*
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

 

Example 1:


Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.
Example 2:


Input: heights = [2,4]
Output: 4
 

Constraints:

1 <= heights.length <= 105
0 <= heights[i] <= 104
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        //number of values the rectangle can be expanded towards left and right
        vector<int> left(n);
        vector<int> right(n);
        // Calculate left limits
        stack<int> s;
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && heights[s.top()] >= heights[i]) 
            {
                s.pop();
            }
            left[i] = s.empty() ? 0 : s.top() + 1; // first index with smaller height
            s.push(i);
        }

        // Calculate right limits
        while (!s.empty()) s.pop();
        for (int i = n-1; i >= 0; --i) {
            while (!s.empty() && heights[s.top()] >= heights[i])
            {
                s.pop();
            }
            right[i] = s.empty() ? n-1 : s.top() - 1;
            s.push(i);
        }
        for(auto i: left) cout<<i<<" ";
        cout<<endl;
        for(auto i: right) cout<<i<<" ";
        int ans = 0;
        for(int i = 0; i<n; ++i)
        {
            auto width = right[i] - left[i] + 1;
            ans = max(ans,width*heights[i]);
        }
        return ans;
    }
};