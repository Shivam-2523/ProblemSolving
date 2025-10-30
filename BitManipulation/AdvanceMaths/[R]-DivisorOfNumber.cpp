/*
Given an integer n, print all the divisors of N in the ascending order.
 
Examples:

Input : n = 20
Output: 1 2 4 5 10 20
Explanation: 20 is completely divisible by 1, 2, 4, 5, 10 and 20.
Input: n = 21191
Output: 1 21191
Explanation: As 21191 is a prime number, it has only 2 factors(1 and the number itself).
Constraints:
1 ≤ n ≤ 109
*/


class Solution {
  public:
    void print_divisors(int n) {
        vector<int> divisorsLow, divisorsHigh;
        int sqrtN = sqrt(n);
        for (int i = 1; i <= sqrtN; ++i) {
            if (n % i == 0) {
                divisorsLow.push_back(i);
                if (i != n/i)  // Avoid duplicate for perfect squares
                    divisorsHigh.push_back(n / i);
            }
        }
        // Print lower divisors
        for (int d : divisorsLow)
            cout << d << " ";
        // Print higher divisors in reverse order to ensure ascending output
        for (auto it = divisorsHigh.rbegin(); it != divisorsHigh.rend(); ++it)
            cout << *it << " ";
    }
};