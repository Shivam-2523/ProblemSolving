/*
You are given an array with unique elements of stalls[], which denote the position of a stall. You are also given an integer k which denotes the number of aggressive cows. Your task is to assign stalls to k cows such that the minimum distance between any two of them is the maximum possible.

Examples :

Input: stalls[] = [1, 2, 4, 8, 9], k = 3
Output: 3
Explanation: The first cow can be placed at stalls[0], 
the second cow can be placed at stalls[2] and 
the third cow can be placed at stalls[3]. 
The minimum distance between cows, in this case, is 3, which also is the largest among all possible ways.
Input: stalls[] = [10, 1, 2, 7, 5], k = 3
Output: 4
Explanation: The first cow can be placed at stalls[0],
the second cow can be placed at stalls[1] and
the third cow can be placed at stalls[4].
The minimum distance between cows, in this case, is 4, which also is the largest among all possible ways.
Input: stalls[] = [2, 12, 11, 3, 26, 7], k = 5
Output: 1
Explanation: Each cow can be placed in any of the stalls, as the no. of stalls are exactly equal to the number of cows.
The minimum distance between cows, in this case, is 1, which also is the largest among all possible ways.
Constraints:
2 <= stalls.size() <= 106
0 <= stalls[i] <= 108
2 <= k <= stalls.size()
*/




class Solution {
  public:
    bool helperFunction (vector<int> &stalls, int k, int d)
    {
        int i = 1;
        int n = stalls.size();
        int find = stalls[0]+d;
        k--;
        
        while(i<n && k > 0)
        {
            if(stalls[i]>=find)
            {
                k--;
                find = stalls[i]+d;
            }else
                i++;
        }
        return (k == 0);
    }
    
    int aggressiveCows(vector<int> &stalls, int k) {
        int n = stalls.size();
        sort(stalls.begin(),stalls.end());
        int ans = 0;
        
        int l = 1, r = stalls[n-1] - stalls[0];
        
        while(l<=r)
        {
            int mid = (l+r)/2;
            
            if(helperFunction(stalls,k,mid))
            {
                ans = mid;
                l = mid+1;
            }else
            {
                r = mid-1;
            }
        }
        return ans;
        // Write your code here
    }
};