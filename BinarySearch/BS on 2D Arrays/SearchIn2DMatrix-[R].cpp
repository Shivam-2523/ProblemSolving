/*
You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.

 

Example 1:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
Example 2:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-104 <= matrix[i][j], target <= 104
*/


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()|| matrix[0].empty()){
            return false;
        }
        int n=matrix.size();
        int m=matrix[0].size();
        int i=0;
        int j=m-1;
        while(i<n && j>=0){
            if(matrix[i][j]==target){
                return true;
            }
            else if(matrix[i][j]<target){
                i++;
            }
            else{
                j--;
            }
        }
        return false;
    }
};


/*==============================================OR===============================================*/
class Solution {
public:
    bool binarySearch(vector<int> nums, int target)
    {
        int l = 0, r = nums.size();

        while(l<=r)
        {
            int mid = (l+r)/2;
            if(nums[mid]==target)
                return true;
            else if(nums[mid]>target)
                r = mid-1;
            else
                l = mid+1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();

        int l = 0, r = row-1;

        while(l<=r)
        {
            int mid = (l+r)/2;
            if(matrix[mid][0] == target)
                return true;
            else if(matrix[mid][0]>target)
                r = mid-1;
            else
            {
                if(matrix[mid][col-1]>=target)
                    return binarySearch(matrix[mid],target);
                else
                    l = mid+1;
            }
        }
        return false;
    }
};