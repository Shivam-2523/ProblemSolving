/*
Given an array arr[], partition it into two subsets(possibly empty) such that each element must belong to only one subset. Let the sum of the elements of these two subsets be sum1 and sum2. Given a difference d, count the number of partitions in which sum1 is greater than or equal to sum2 and the difference between sum1 and sum2 is equal to d. 

Examples :

Input: arr[] =  [5, 2, 6, 4], d = 3
Output: 1
Explanation: There is only one possible partition of this array. Partition : {6, 4}, {5, 2}. The subset difference between subset sum is: (6 + 4) - (5 + 2) = 3.
Input: arr[] = [1, 1, 1, 1], d = 0 
Output: 6 
Explanation: We can choose two 1's from indices {0,1}, {0,2}, {0,3}, {1,2}, {1,3}, {2,3} and put them in sum1 and remaning two 1's in sum2.
Thus there are total 6 ways for partition the array arr. 
Input: arr[] = [1, 2, 1, 0, 1, 3, 3], d = 11
Output: 2
Constraint:
1 <= arr.size() <= 50
0 <= d  <= 50
0 <= arr[i] <= 6


*/

class Solution {
  public:
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> dp (target+1,0);
        dp[0] = 1;//empty set which will have the sum as 0
        
        for(int i = 0; i<n; ++i)
        {
            int num = arr[i];
            for(int j = target; j>=num; --j)
            {
                dp[j] += dp[j-num];
            }
        }
        
        return dp[target];
    }
    int countPartitions(vector<int>& arr, int d) {
        // Code here
        int sum = 0;
        for(auto i: arr)
            sum+= i;
        
        if ((sum + d) % 2 != 0) return 0;
        int num = (sum + d) / 2;
        return perfectSum(arr,num);
    }
};
/*
if the sum of elements of the arr is sum and subset a has sum X and subset b has sum Y, 
then X + Y = sum. Also we have to find the case where the diff between the subset is d 
so  X = Y-d. so we can replace to the first equation Y-d+Y=sum -> 2Y=sum+d -> Y=(sum+d)/2
Tthe number of subsets with some (sum+d)/2 would be the answer
*/