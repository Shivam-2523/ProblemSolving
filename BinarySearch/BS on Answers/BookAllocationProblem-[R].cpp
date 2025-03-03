/*
You are given an array arr[] of integers, where each element arr[i] represents the number of pages in the ith book. You also have an integer k representing the number of students. The task is to allocate books to each student such that:

Each student receives atleast one book.
Each student is assigned a contiguous sequence of books.
No book is assigned to more than one student.
The objective is to minimize the maximum number of pages assigned to any student. In other words, out of all possible allocations, find the arrangement where the student who receives the most pages still has the smallest possible maximum.

Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order (see the explanation for better understanding).

Examples:

Input: arr[] = [12, 34, 67, 90], k = 2
Output: 113
Explanation: Allocation can be done in following ways:
[12] and [34, 67, 90] Maximum Pages = 191
[12, 34] and [67, 90] Maximum Pages = 157
[12, 34, 67] and [90] Maximum Pages = 113.
Therefore, the minimum of these cases is 113, which is selected as the output.
Input: arr[] = [15, 17, 20], k = 5
Output: -1
Explanation: Allocation can not be done.
Input: arr[] = [22, 23, 67], k = 1
Output: 112
Constraints:
1 <=  arr.size() <= 106
1 <= arr[i] <= 103
1 <= k <= 103 
*/





class Solution {
  public:
    bool helperFunction(vector<int> &arr, int k, int p) {
        int pages = 0;
        int students = 1; // Start with 1 student
    
        for (int i : arr) {
            // If a single book has more pages than allowed, allocation is impossible.
            if (i > p) return false;
            
            if (pages + i > p) {
                // Allocate to a new student.
                students++;
                pages = i;  // Start count for the new student
                
                // If more students are needed than available, return false.
                if (students > k) return false;
            } else {
                pages += i; // Add the book to the current student's allocation.
            }
        }
        // If we managed with <= k students, the allocation is valid.
        return true;
    }


    
    int findPages(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        if(n<k)
            return -1;
            
        int sum = 0;
        int ans = -1;
        
        int l = *max_element(arr.begin(), arr.end()); // Minimum possible pages
        int r = accumulate(arr.begin(), arr.end(), 0); // Maximum possible pages
            
        while(l<=r)
        {
            int mid = (l+r)/2;
            
            if(helperFunction(arr,k,mid))
            {
                ans = mid;
                r = mid-1;
            }else
            {
                l = mid+1;
            }
        }
        return ans;
    }
};