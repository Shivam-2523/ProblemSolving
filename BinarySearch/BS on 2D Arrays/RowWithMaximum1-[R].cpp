/*
You are given a 2D binary array arr[][] consisting of only 1s and 0s. Each row of the array is sorted in non-decreasing order. Your task is to find and return the index of the first row that contains the maximum number of 1s. If no such row exists, return -1.

Note:

The array follows 0-based indexing.
The number of rows and columns in the array are denoted by n and m respectively.
Examples:

Input: arr[][] = [[0,1,1,1], [0,0,1,1], [1,1,1,1], [0,0,0,0]]
Output: 2
Explanation: Row 2 contains the most number of 1s (4 1s). Hence, the output is 2.
Input: arr[][] = [[0,0], [1,1]]
Output: 1
Explanation: Row 1 contains the most number of 1s (2 1s). Hence, the output is 1.
Input: arr[][] = [[0,0], [0,0]]
Output: -1
Explanation: No row contains any 1s, so the output is -1.
Constraints:
1 ≤ arr.size(), arr[i].size() ≤ 103
0 ≤ arr[i][j] ≤ 1 
*/

class Solution {
  public:
    int getFirstOccurence(vector<int> nums)
    {
        int l = 0, r = nums.size()-1;
        int ans = -1;
        
        while(l<=r)
        {
            int mid = (l+r)/2;
            if(nums[mid]==1)
            {
                ans = mid;
                r = mid-1;
            }else
            {
                l = mid+1;
            }
            
        }
        return ans;
    }
    
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int row = arr.size();
        int col = arr[0].size();
        int ans = -1;
        int maxCount = 0;
        
        for(int i = 0; i<row; i++)
        {
            auto pos = getFirstOccurence(arr[i]);
            if (pos != -1)
            {
                if(col-pos>maxCount)
                {
                    ans = i;
                    maxCount = col - pos;
                }
            }
        }
        return ans;
    }
};