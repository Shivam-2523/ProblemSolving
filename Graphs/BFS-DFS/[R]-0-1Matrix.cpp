/*
Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two cells sharing a common edge is 1.

 

Example 1:


Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]
Example 2:


Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
Output: [[0,0,0],[0,1,0],[1,2,1]]
 

Constraints:

m == mat.length
n == mat[i].length
1 <= m, n <= 104
1 <= m * n <= 104
mat[i][j] is either 0 or 1.
There is at least one 0 in mat.
 

Note: This question is the same as 1765: https://leetcode.com/problems/map-of-highest-peak/
*/

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        queue<pair<int,int>> q;

        for(int i = 0; i<row; ++i)
        {
            for(int j = 0; j<col; ++j)
            {
                if(mat[i][j] == 0)
                    q.push({i,j});
                else
                    mat[i][j] = INT_MAX;
            }
        }

        vector<vector<int>> v = {{1,0},{0,1},{-1,0},{0,-1}};
        while(!q.empty())
        {
            int size = q.size();
            for(int i = 0; i<size; ++i)
            {
                auto [r,c] = q.front(); q.pop();
                for(auto i: v)
                {
                    int cr = r + i[0];
                    int cc = c + i[1]; 
                    if(cr >= 0 && cr < row && cc >= 0 && cc < col)
                    {
                        if(mat[cr][cc]>mat[r][c]+1)
                        {
                            mat[cr][cc] = mat[r][c]+1;
                            q.push({cr,cc});
                        }
                    }
                }
            }
        }

        return mat;
    }
};