/*
Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.
The graph is represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes an edge from verticex u to v.

Examples:

Input: V = 4, edges[][] = [[0, 1], [1, 2], [2, 3], [3, 3]]



Output: true
Explanation: 3 -> 3 is a cycle
Input: V = 3, edges[][] = [[0, 1], [1, 2]]



Output: false
Explanation: no cycle in the graph
Constraints:
1 ≤ V, E ≤ 105
*/


class Solution {
  public:
    bool dfs (int node, vector<vector<int>> &graph, vector<bool> & visited, vector<bool> & recStack)
    {
        recStack[node] = true;
        visited[node] = true;
        
        for(auto i: graph[node])
        {
            if(!visited[i])
            {
                if(dfs(i,graph,visited,recStack))
                    return true;
            }else if(recStack[i])
                    return true;
        }
        recStack[node] = false;
        return false;
    }
    
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> graph (V, vector<int>(0,0));
        
        for(auto i: edges)
            graph[i[0]].push_back(i[1]);
           
        vector<bool> visited (V,false);
        //vector<bool> recStack(V,false);
        
        for(int i = 0; i<V; ++i)
        {
            if(!visited[i])
            {
                vector<bool> recStack(V,false);
                if(dfs(i,graph,visited,recStack))
                    return true;
            }
        }
        return false;
    }
};