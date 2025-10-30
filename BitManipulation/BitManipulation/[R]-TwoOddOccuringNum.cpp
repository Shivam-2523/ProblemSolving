/*
Given an unsorted array, arr[] of positive numbers that contains even number of occurrences for all numbers except two numbers. Return that two numbers in decreasing order which has odd occurrences.

Examples:

Input: arr = [4, 2, 4, 5, 2, 3, 3, 1]
Output: [5, 1] 
Explanation: 5 and 1 have odd occurrences.
Input: arr[] = [1, 7, 5, 7, 5, 4, 7, 4]
Output: [7, 1]
Explanation: 7 and 1 have odd occurrences.
Constraints:
2 ≤ arr.size() ≤ 106
1 ≤ arr[i]≤ 107
*/


class Solution {
  public:
    vector<int> twoOddNum(vector<int>& arr) {
        // code here
        int ans = 0;
        
        for(auto i: arr)
            ans = ans^i;
            
        //ans is the xor of the two elements that are not repeating
        int lastSignificantBit = ans & -ans;
        int b1 = 0, b0  =0;
        for(auto i: arr)
        {
            if(i&lastSignificantBit)//both are 1
                b1 = b1 ^ i;
            else
                b0 = b0 ^ i;
        }
        
        if(b1>b0) return {b1,b0};
        
        return {b0,b1};
    }
};

/*XOR Everything you will know the XOR of the two numbers that are not repeated. Now find the last set bit in it,
this means that for one of the numbers that bit would be 0 and for one it would be 1. Now traverse the array and 
look for all the elements that have that particular bit set to 0 and keep XORing them so that you have the one 
number remaining that has that bit set to 0 and not repeated. Do the same for 1.*/