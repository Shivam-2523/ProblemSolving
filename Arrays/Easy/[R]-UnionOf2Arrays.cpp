/*Given two sorted arrays a[] and b[], where each array may contain duplicate elements , the task is to return the elements in the union of the two arrays in sorted order.

Union of two arrays can be defined as the set containing distinct common elements that are present in either of the arrays.
Examples:

Input: a[] = [1, 2, 3, 4, 5], b[] = [1, 2, 3, 6, 7]
Output: 1 2 3 4 5 6 7
Explanation: Distinct elements including both the arrays are: 1 2 3 4 5 6 7.
Input: a[] = [2, 2, 3, 4, 5], b[] = [1, 1, 2, 3, 4]
Output: 1 2 3 4 5
Explanation: Distinct elements including both the arrays are: 1 2 3 4 5.
Input: a[] = [1, 1, 1, 1, 1], b[] = [2, 2, 2, 2, 2]
Output: 1 2
Explanation: Distinct elements including both the arrays are: 1 2.*/



class Solution {
  public:
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // Your code here
        // return vector with correct order of elements
        int as = a.size(), bs = b.size();
        int l = 0, r = 0;
        
        vector<int> c;// (as+bs,0);
        //int i = 0;
        
        while(l<as && r<bs)
        {
            if(a[l]<=b[r])
            {
                if(c.size() == 0 || c.back()!=a[l])
                    c.push_back(a[l]);
                l++;
                
            } else
            {
                if(c.size() == 0 || c.back()!=b[r])
                    c.push_back(b[r]);
                r++;
            }
        }
                
        while(l<as)
        {
            if(c.back()!=a[l])
                c.push_back(a[l]);
            l++;
        }
        while(r<bs)
        {
            if(c.back()!=b[r])
                c.push_back(b[r]);
            r++;
        }
        
        return c;
    }
};