/*
Given an m x n matrix, return all elements of the matrix in spiral order.

 

Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:


Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;

        int i = 0, j = 0;
        int l = 0, r = matrix[0].size(), t = 0, b =matrix.size();
        while(l<r && t<b)
        {
            for(int i = l; i<r; i++)
                ans.push_back(matrix[t][i]);
            t++;
            for(int i = t; i<b; i++)
                ans.push_back(matrix[i][r-1]);
            r--;

            if(!(l<r && t<b))
                break;
                
            for(int i = r-1; i>=l; i--)
                ans.push_back(matrix[b-1][i]);
            b--;
            for(int i = b-1; i>=t; i--)
                ans.push_back(matrix[i][l]);
            l++;
        }
        return ans;
    }
};