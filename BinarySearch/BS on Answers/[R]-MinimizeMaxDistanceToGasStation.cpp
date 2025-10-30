/*
We have a horizontal number line. On that number line, we have gas stations at positions stations[0], stations[1], ..., stations[n-1], where n is the size of the stations array. Now, we add k more gas stations so that d, the maximum distance between adjacent gas stations, is minimized. We have to find the smallest possible value of d. Find the answer exactly to 2 decimal places.
Note: stations is in a strictly increasing order.

Example 1:

Input:
n = 10
stations[] = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
k = 9
Output: 0.50
Explanation: Each of the 9 stations can be added mid way between all the existing adjacent stations.
Example 2:

Input:
n = 10
stations[] = [3, 6, 12, 19, 33, 44, 67, 72, 89, 95] 
k = 2 
Output: 14.00 
Explanation: Construction of gas stations at 8th(between 72 and 89) and 6th(between 44 and 67) locations.
Your Task:
You don't need to read input or print anything. Your task is to complete the function findSmallestMaxDist() which takes a list of stations and integer k as inputs and returns the smallest possible value of d. Find the answer exactly to 2 decimal places.

Constraint:
10 <= n <= 10000 
0 <= stations[i] <= 109 
0 <= k <= 105
*/


class Solution {
  public:
    bool helperFunction(vector<int> arr,int k, double d)
    {
        int count = 0;
        for (int i = 1; i < arr.size(); i++) {
            double gap = arr[i] - arr[i - 1];
            count += (int)(gap / d);  // Number of additional stations needed in this gap
        }
        return count <= k;
    }
    double findSmallestMaxDist(vector<int> &stations, int k) {
        // Code here
        int n = stations.size();
        double l = 0.01;
        double r = stations[n-1]-stations[0];
        double ans = 0.00;
        
        while(r-l>1e-6)
        {
            double mid = (l+r)/2.0;
            if(helperFunction(stations,k,mid))
            {
                ans = mid;
                r = mid;
            }else
            {
                l = mid;
            }
        }
        return round(ans * 100.0) / 100.0;
    }
};