/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

 

Example 1:


Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
 

Constraints:

n == height.length
1 <= n <= 2 * 104
0 <= height[i] <= 105
*/

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        stack<int> s;

        for(int i = 0; i<n; ++i)
        {
            while(!s.empty() && height[i]>height[s.top()])
            {
                int bottom = s.top(); s.pop();
                if (s.empty()) break;
                // left boundary is s.top(), right boundary is i
                int left = s.top();
                int width = i - left - 1;
                int bounded_height = min(height[left], height[i]) - height[bottom];
                if (bounded_height > 0)
                    ans += width * bounded_height;
            }
            s.push(i);
        }

        return ans;
    }
};

