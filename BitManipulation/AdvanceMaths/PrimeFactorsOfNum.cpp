/*
Given a number n. Find its unique prime factors in increasing order.

Examples :

Input: n = 100
Output: [2, 5]
Explanation: Unique prime factors of 100 are 2 and 5.
Input: n = 60
Output: [2, 3, 5]
Explanation: Prime factors of 60 are 2, 2, 3, 5. Unique prime factors are 2, 3 and 5.
Constraints:
1 ≤ n ≤ 106
*/


class Solution {
  public:
    vector<int> primeFac(int n) {
        // code here
        vector<bool> v(n+1,true);
        
        v[0] = false;
        v[1] = false;
        
        for(int i = 2; i * i <=n; i++)
        {
            if(v[i])
            {
                for(auto j = i * i; j<=n; j+=i)
                    v[j] =false;
            }
        }
        vector<int> ans;
        for(auto i = 0; i<=n; i++)
        {
            if(v[i] && (n%i==0))
                ans.push_back(i);
        }
        
        return ans;
    }
};