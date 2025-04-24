/*
Given two sorted arrays a[] and b[] and an element k, the task is to find the element that would be at the kth position of the combined sorted array.

Examples :

Input: a[] = [2, 3, 6, 7, 9], b[] = [1, 4, 8, 10], k = 5
Output: 6
Explanation: The final combined sorted array would be [1, 2, 3, 4, 6, 7, 8, 9, 10]. The 5th element of this array is 6.
Input: a[] = [100, 112, 256, 349, 770], b[] = [72, 86, 113, 119, 265, 445, 892], k = 7
Output: 256
Explanation: Combined sorted array is [72, 86, 100, 112, 113, 119, 256, 265, 349, 445, 770, 892]. The 7th element of this array is 256.
Constraints:

1 <= a.size(), b.size() <= 106
1 <= k <= a.size() + b.size()
0 <= a[i], b[i] < 108
*/



class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        
        if(a.size()>b.size())
            return kthElement(b,a,k);
        
        int m = a.size();
        int n = b.size();
        int l = max(0,k-n);
        int r = min(m,k);

        while(l<=r)
        {
            // l1 | r1
            // l2 | r2
            int cut1 = (l+r)/2; //element in two halfes of nums1
            int cut2 = k - cut1;//element 1 two halfes of nums2

            int l1 = (cut1 == 0)?INT_MIN:a[cut1-1];
            int l2 = (cut2 == 0)?INT_MIN:b[cut2-1];
            int r1 = (cut1 == m)?INT_MAX:a[cut1];
            int r2 = (cut2 == n)?INT_MAX:b[cut2];

            if(l1<=r2 && l2<=r1)
            {
                return max(l1, l2);
            }else if (l1>r2)//more elements than reuired in l1
                r = cut1 - 1;
            else
                l = cut1 + 1;
        }
        return 0.0;
    }
};
