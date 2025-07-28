/*
Given an integer n, return the number of prime numbers that are strictly less than n.

 

Example 1:

Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
Example 2:

Input: n = 0
Output: 0
Example 3:

Input: n = 1
Output: 0
 

Constraints:

0 <= n <= 5 * 106
*/


class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        vector<bool> v(n, true);    // only need up to n-1

        v[0] = v[1] = false;        // 0 and 1 are not primes

        for (int i = 2; i * i < n; ++i) {
            if (v[i]) {
                for (int j = i * i; j < n; j += i) { // start from i*i
                    v[j] = false;
                }
            }
        }

        return count(v.begin(), v.end(), true);
    }
};

//0 1 2 3 [4] 5 [6] 7 [8] [9] 10