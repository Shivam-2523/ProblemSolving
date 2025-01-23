/*
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

 

Example 1:

Input: nums = [3,2,3]
Output: [3]
Example 2:

Input: nums = [1]
Output: [1]
Example 3:

Input: nums = [1,2]
Output: [1,2]
 

Constraints:

1 <= nums.length <= 5 * 104
-109 <= nums[i] <= 109
 

Follow up: Could you solve the problem in linear time and in O(1) space?
  
*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int> ans;
        //1,1,1,1,2,4,4,4,4
        for(int i = 0; i<n;)
        {
            int count = 1;
            int num = nums[i];
            while(i+1<n&&nums[i+1]==nums[i])
            {
                count++;
                i++;
            }
            i++;
            if(count>n/3)
                ans.push_back(num);
        }
        return ans;
    }
};