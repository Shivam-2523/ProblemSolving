/*
There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.

 

Example 1:


Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2
Example 2:


Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3
 

Constraints:

1 <= n <= 200
n == isConnected.length
n == isConnected[i].length
isConnected[i][j] is 1 or 0.
isConnected[i][i] == 1
isConnected[i][j] == isConnected[j][i]
*/


class Solution {
public:
    void helper (int node, vector<vector<int>> & adj, vector<bool> & visited)
    {
        visited[node] = true;

        for(auto i: adj[node])
        {
            if(!visited[i])
            {
                visited[i] = true;
                helper(i,adj,visited);
            }           
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<vector<int>> adj (isConnected.size()+1, vector<int> {});
        for(int i = 0; i<isConnected.size(); i++)
        {
            for(int j = 0; j<isConnected[0].size(); j++)
            {
                if(isConnected[i][j] == 1)
                {
                    adj[i+1].push_back(j+1);
                }
            }
        }
        int n = isConnected.size();
        vector<bool> visited (n,false);
        int ans = 0;

        for(int i = 1; i<=n; i++)
        {
            if(!visited[i])
            {
                helper(i,adj,visited);
                ans++;
            }
        }
        return ans;
    }
};