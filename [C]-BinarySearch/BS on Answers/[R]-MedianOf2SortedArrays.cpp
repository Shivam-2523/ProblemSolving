/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 

Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106
*/


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        if(a.size()>b.size())
            return findMedianSortedArrays(b,a);
        
        int m = nums1.size();
        int n = nums2.size();
        int l = 0;
        int r = nums1.size();

        while(l<=r)
        {
            // nums1 -> l1 | r1
            // nums2 -> l2 | r2
            int cut1 = (l+r)/2; //element in two halfes of nums1
            int cut2 = (m+n+1)/2 - cut1;//element 1 two halfes of nums2

            int l1 = (cut1 == 0)?INT_MIN:nums1[cut1-1];
            int l2 = (cut2 == 0)?INT_MIN:nums2[cut2-1];
            int r1 = (cut1 == m)?INT_MAX:nums1[cut1];
            int r2 = (cut2 == n)?INT_MAX:nums2[cut2];

            if(l1<=r2 && l2<=r1)
            {
                if ((m + n) % 2 == 0)
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                else
                    return max(l1, l2);

            }else if (l1>r2)//more elements than reuired in l1
                r = cut1 - 1;
            else
                l = cut1 + 1;
        }
        return 0.0;
    }
};