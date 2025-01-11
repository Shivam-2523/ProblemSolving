class Solution {
  public:
  
    const int MOD = 1e9 + 7;  // Define the modulo value
    long long int f(int n, vector<long long int> & dp)
    {
        if(n<=1)return n;
        
        if(dp[n]!=-1)return dp[n];
        return dp[n] = (f(n-1,dp)+f(n-2,dp))%MOD;
    }
    long long int topDown(int n) {
        // code here
        vector<long long int> dp (n+1,-1);
        return f(n,dp);
    }
    long long int bottomUp(int n) {
        // code here
        vector<long long int> dp(n+1,0);
        dp[0]=0;
        dp[1]=1;
        
        for(int i = 2; i<=n; i++)
        {
            dp[i]=(dp[i-1]+dp[i-2])%MOD;
        }
        return dp[n];
    }
};
