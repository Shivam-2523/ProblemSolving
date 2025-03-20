/*
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

 

Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]
 

Constraints:

n == nums.length
1 <= n <= 300
nums[i] is either 0, 1, or 2.
 

Follow up: Could you come up with a one-pass algorithm using only constant extra space?
*/


class Solution {
public:
    void sortColors(vector<int>& nums) {
        int j = 0, k = nums.size()-1;
        for (int i=0; i <= k; i++) {
            if (nums[i] == 0)
                swap(nums[i], nums[j++]);
            else if (nums[i] == 2)
                swap(nums[i--], nums[k--]);
        }
    }
};


/*
Why i-- when swapping 2?
When nums[i] == 2, it is swapped with nums[k] (the last unprocessed element).
The element swapped into nums[i] is unknown—it could be 0, 1, or even another 2.
Since i hasn't been processed yet, we need to check it again, so we do i-- to compensate for the automatic i++ in the loop.
Why not i-- when swapping 0?
When nums[i] == 0, it is swapped with nums[j] (which is always 1 or 0 due to the left boundary).
Since we already placed 0 correctly, we know nums[i] is either 1 (which is correct) or another 0 (which will be swapped correctly in the next pass).
So, we do not need to check nums[i] again, and just move forward.
*/