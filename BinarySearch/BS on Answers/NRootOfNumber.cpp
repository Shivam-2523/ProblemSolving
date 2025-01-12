/*You are given 2 numbers n and m, the task is to find n√m (nth root of m). If the root is not integer then returns -1.

Examples :

Input: n = 2, m = 9
Output: 3
Explanation: 32 = 9
Input: n = 3, m = 9
Output: -1
Explanation: 3rd root of 9 is not integer.
Input: n = 1, m = 14
Output: 14*/




class Solution {
  public:
    int nthRoot(int n, int m) {
        // Code here.
        int l = 0, r = m;
        
        while(l<=r)
        {
            int mid = (l+r)/2;
            int product = 1;
            for(int i = 0; i<n ; i++)
                product*=mid;
                
            if(product==m)
                return mid;
            else if(product>m)
                r=mid-1;
            else
                l=mid+1;
        }
        return -1;
    }
};