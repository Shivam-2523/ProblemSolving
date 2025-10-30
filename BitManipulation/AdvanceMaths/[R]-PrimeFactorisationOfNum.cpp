/*
You are given a positive number N. Using the concept of Sieve, compute its prime factorisation.

Example:

Input: 
N = 12246
Output: 
2 3 13 157
Explanation: 
2*3*13*157 = 12246 = N.
Your Task:

Comple the function findPrimeFactors(), which takes a positive number N as input and returns a vector consisting of prime factors. You should implement Sieve algorithm to solve this problem.

 

Expected Time Complexity: O(Nlog(log(N)).

Expected Auxiliary Space: O(N).

Constraints:

2<=N<=2*105
*/


class Solution {
  public:
    void sieve() {}

    vector<int> findPrimeFactors(int N) {

        // Write your code here
        vector<bool> v(N+1,true);
        
        v[0] = false;
        v[1] = false;
        
        for(int i = 2; i * i <=N; i++)
        {
            if(v[i])
            {
                for(auto j = i * i; j<=N; j+=i)
                    v[j] =false;
            }
        }
        vector<int> prime;
        for(auto i = 0; i<=N; i++)
        {
            if(v[i] && (N%i==0))
                prime.push_back(i);
        }
        
        vector<int> ans;
        for(auto i: prime)
        {
            while(N%i == 0)
            {
                ans.push_back(i);
                N/=i;
            }
        }
        
        return ans;
    }
};