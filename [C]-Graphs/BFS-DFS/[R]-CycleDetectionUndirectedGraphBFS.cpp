/*
Given an undirected graph with V vertices and E edges, represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes an edge between vertices u and v, determine whether the graph contains a cycle or not. The graph can have multiple component.

Examples:

Input: V = 4, E = 4, edges[][] = [[0, 1], [0, 2], [1, 2], [2, 3]]
Output: true
Explanation: 
 
1 -> 2 -> 0 -> 1 is a cycle.
Input: V = 4, E = 3, edges[][] = [[0, 1], [1, 2], [2, 3]]
Output: false
Explanation: 
 
No cycle in the graph.
Constraints:
1 ≤ V ≤ 105
1 ≤ E = edges.size() ≤ 105
*/


class Solution {
public:
    bool helper(int node, int prev, vector<bool>& visited, vector<vector<int>>& adj) {
         // Mark the node as visited
        visited[node] = true;
        for (auto neighbor : adj[node]) {
            if (!visited[neighbor]) {
                
                if (helper(neighbor, node, visited, adj))  
                    return true;  // If cycle found, return immediately
            } else if (neighbor != prev) {
                return true;  // A back edge (not parent) means a cycle
            }
        }
        return false;
    }
    //2 1
    //0 1
    // 0
    //1 2
    bool isCycle(vector<vector<int>>& adj) {
        int v = adj.size();
        vector<bool> visited(v, false);
        
        for (int i = 0; i < v; i++) {
            if (!visited[i]) { // Check all components
                queue<pair<int,int>> q;
                q.push({i,-1});
                visited[i] = true;
                
                while(!q.empty())
                {
                    int a = q.front().first;
                    int parent = q.front().second;
                    q.pop();

                    for(auto j: adj[a])
                    {
                        if(!visited[j])
                        {
                            visited[j] = true;
                            q.push({j,a});
                        }else if(parent != j)
                        {
                            return true;
                        }
                    }
                }
                
            }
        }
        return false;
    }
};