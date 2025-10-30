/*
A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbors to the left, right, top, and bottom.

Given a 0-indexed m x n matrix mat where no two adjacent cells are equal, find any peak element mat[i][j] and return the length 2 array [i,j].

You may assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.

You must write an algorithm that runs in O(m log(n)) or O(n log(m)) time.

 

Example 1:



Input: mat = [[1,4],[3,2]]
Output: [0,1]
Explanation: Both 3 and 4 are peak elements so [1,0] and [0,1] are both acceptable answers.
Example 2:



Input: mat = [[10,20,15],[21,30,14],[7,16,32]]
Output: [1,1]
Explanation: Both 30 and 32 are peak elements so [1,1] and [2,2] are both acceptable answers.
 

Constraints:

m == mat.length
n == mat[i].length
1 <= m, n <= 500
1 <= mat[i][j] <= 105
No two adjacent cells are equal.
*/

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int row = mat.size();
		int col = mat[0].size();
		
		if(row == 0) return {};
		
		int l = 0, r = col-1;
		
		while(l<=r)
		{
			int mid = (l+r)/2;//choose the mid col
			int maxRow = 0, maxVal = INT_MIN;
			for(int i = 0; i<row; i++)
			{
				if(mat[i][mid]>maxVal)
				{
					maxVal = mat[i][mid];
					maxRow = i;
				}
			}
			int leftVal = mid-1<0 ? -1 : mat[maxRow][mid-1];
			int rightVal = mid+1>=col ? -1 : mat[maxRow][mid+1];
			if(mat[maxRow][mid]> leftVal && mat[maxRow][mid]>rightVal)
				return{maxRow,mid};
			else if(mat[maxRow][mid]<rightVal)
				l = mid+1;
			else
				r = mid-1;
		}
		
		return {};//no peak element found
    }
};