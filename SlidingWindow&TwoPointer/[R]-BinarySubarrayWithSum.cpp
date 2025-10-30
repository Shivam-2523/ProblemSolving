/*
Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

A subarray is a contiguous part of the array.

 

Example 1:

Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation: The 4 subarrays are bolded and underlined below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
Example 2:

Input: nums = [0,0,0,0,0], goal = 0
Output: 15
 

Constraints:

1 <= nums.length <= 3 * 104
nums[i] is either 0 or 1.
0 <= goal <= nums.length
*/

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int sum = 0, ans =0;
        int n = nums.size();
        int r = 0;
        unordered_map<int,int> m;
        m[0] = 1;

        while(r<n)
        {
            sum+=nums[r];
            int a  = sum - goal;
            if(m.find(a)!=m.end())
                ans += m[a];
            m[sum]++;
            r++;
        }
        return ans;
    }
};
/*
class Solution {
public:
    int funct(vector<int>& nums, int goal){
        if(goal<0) return 0;
        int l=0,r=0;
        int cnt=0,sum=0;
        while(r<nums.size()){
            sum+=nums[r];
            while(sum>goal){
                sum-=nums[l++];
            }
            cnt+=r-l+1;
            r++;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return funct(nums,goal)-funct(nums,goal-1);
    }
};
*/