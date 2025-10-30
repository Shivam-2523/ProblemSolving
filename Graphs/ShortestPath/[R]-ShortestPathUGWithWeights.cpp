/*
You are given an adjacency list, adj of Undirected Graph having unit weight of the edges, find the shortest path from src to all the vertex and if it is unreachable to reach any vertex, then return -1 for that vertex.

Examples :

Input: adj[][] = [[1, 3], [0, 2], [1, 6], [0, 4], [3, 5], [4, 6], [2, 5, 7, 8], [6, 8], [7, 6]], src=0
Output: [0, 1, 2, 1, 2, 3, 3, 4, 4]

Input: adj[][]= [[3], [3], [], [0, 1]], src=3
Output: [1, 1, -1, 0]

Input: adj[][]= [[], [], [], [4], [3], [], []], src=1
Output: [-1, 0, -1, -1, -1, -1, -1] 
Constraint:
1<=adj.size()<=104
0<=edges<=adj.size()-1
*/


class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        queue<int> q;
        q.push(src);
        vector<int> ans (adj.size(),-1);
        vector<bool> visited (adj.size(),false);
        int weight = 0;
        visited[src] = true;
        
        while(!q.empty())
        {
            int size = q.size();
            for(int i = 0; i<size; ++i)
            {
                int node = q.front(); q.pop();
                ans[node] = weight;
                
                for(auto j: adj[node])
                {
                    if(!visited[j])
                    {
                        visited[j] = true;
                        q.push(j);
                    }
                }
            }
            weight++;
        }
        
        return ans;
    }
};
//If you wait to mark visited until you pop from the queue,
//you might enqueue the same node multiple times (from multiple sources!).
