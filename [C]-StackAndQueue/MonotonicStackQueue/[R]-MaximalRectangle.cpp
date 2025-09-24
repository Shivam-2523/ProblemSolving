/*
Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

 

Example 1:


Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.
Example 2:

Input: matrix = [["0"]]
Output: 0
Example 3:

Input: matrix = [["1"]]
Output: 1
 

Constraints:

rows == matrix.length
cols == matrix[i].length
1 <= row, cols <= 200
matrix[i][j] is '0' or '1'.
*/

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int row = matrix.size(), col = matrix[0].size();
        vector<int> heights(col, 0);
        int ans = 0;
        
        for(int r = 0; r < row; ++r) {
            // Build heights histogram for current row
            for(int c = 0; c < col; ++c) {
                if(matrix[r][c] == '1')
                    heights[c]++;
                else
                    heights[c] = 0;
            }
            
            // Now, for this histogram, apply largest rectangle algorithm
            ans = max(ans, largestRectangleArea(heights));
        }
        return ans;
    }
    
    // Apply the standard O(n) histogram algorithm
    int largestRectangleArea(vector<int>& heights) {
        for(auto i: heights) cout<<i<<" ";
        cout<<endl;

        int n = heights.size();
        vector<int> left(n), right(n);
        stack<int> s;
        
        // Compute left limits
        for(int i = 0; i < n; ++i) {
            while(!s.empty() && heights[s.top()] >= heights[i]) s.pop();
            left[i] = s.empty() ? 0 : s.top() + 1; // first index with smaller height
            s.push(i);
        }
        
        // Clear and compute right limits
        while(!s.empty()) s.pop();
        for(int i = n-1; i >= 0; --i) {
            while(!s.empty() && heights[s.top()] >= heights[i]) s.pop();
            right[i] = s.empty() ? n-1 : s.top() - 1;
            s.push(i);
        }
        
        // Compute area for each bar
        int max_area = 0;
        for(int i = 0; i < n; ++i) {
            int width = right[i] - left[i] + 1;
            max_area = max(max_area, heights[i] * width);
        }
        cout<<max_area<<endl;
        return max_area;
    }
};
/*
Summary of Intuition

Every row’s histogram computes possible rectangles that use that row as the bottom edge.
When a column becomes 0, it means any rectangle that tries to use this row as its bottom cannot include that column.
Your algorithm considers all possible rectangles by building up from every row, so nothing gets missed.
*/