/*
Given an array of integers arr[]. Find the Inversion Count in the array.
Two elements arr[i] and arr[j] form an inversion if arr[i] > arr[j] and i < j.

Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If the array is already sorted then the inversion count is 0.
If an array is sorted in the reverse order then the inversion count is the maximum. 

Examples:

Input: arr[] = [2, 4, 1, 3, 5]
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).
Input: arr[] = [2, 3, 4, 5, 6]
Output: 0
Explanation: As the sequence is already sorted so there is no inversion count.
Input: arr[] = [10, 10, 10]
Output: 0
Explanation: As all the elements of array are same, so there is no inversion count.
Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 104
*/

class Solution {
  public:
    // Function to count inversions in the array.
    long long MergeCount(vector<int>& arr, int low, int mid, int high) {
        int n1 = mid - low + 1;
        int n2 = high - mid;

        vector<int> left(n1), right(n2);
        for (int i = 0; i < n1; i++) left[i] = arr[low + i];
        for (int i = 0; i < n2; i++) right[i] = arr[mid + 1 + i];

        int i = 0, j = 0, k = low;
        long long invCount = 0;

        while (i < n1 && j < n2) {
            if (left[i] <= right[j]) {
                arr[k++] = left[i++];
            } else {
                arr[k++] = right[j++];
                invCount += (n1 - i);  // All remaining elements in left[] are greater
            }
        }

        while (i < n1) arr[k++] = left[i++];
        while (j < n2) arr[k++] = right[j++];

        return invCount;
    }
    int merge(vector<int> & arr, int l, int r)
    {
        int count = 0;
        while(l<r)
        {
            int mid = (l+r)/2;
            count += merge(arr,l,mid);
            count += merge(arr,mid+1,r);
            count += MergeCount(arr,l,mid,r);
        }
        return count;
    }
    int inversionCount(vector<int> &arr) {
        // Your Code Here
        //for each number check the number of values less than it
        return merge(arr,0,arr.size()-1);
    }
};