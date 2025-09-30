/*
Given a Directed Acyclic Graph (DAG) of V (0 to V-1) vertices and E edges represented as a 2D list of edges[][], where each entry edges[i] = [u, v] denotes a directed edge u -> v. Return the topological sort for the given graph.

Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u -> v, vertex u comes before v in the ordering.
Note: As there are multiple Topological orders possible, you may return any of them. If your returned Topological sort is correct then the output will be true else false.

Examples:

Input: V = 4, E = 3, edges[][] = [[3, 0], [1, 0], [2, 0]]

Output: true
Explanation: The output true denotes that the order is valid. Few valid Topological orders for the given graph are:
[3, 2, 1, 0]
[1, 2, 3, 0]
[2, 3, 1, 0]
Input: V = 6, E = 6, edges[][] = [[1, 3], [2, 3], [4, 1], [4, 0], [5, 0], [5,2]]

Output: true
Explanation: The output true denotes that the order is valid. Few valid Topological orders for the graph are:
[4, 5, 0, 1, 2, 3]
[5, 2, 4, 0, 1, 3]
Constraints:
2  ≤  V  ≤  5 x 103
1  ≤  E = edges.size()  ≤  min[105, (V * (V - 1)) / 2]
*/

class Solution {
  public:
    void dfs(int node, vector<int> & visited, vector<int> & topoSort, vector<vector<int>> & graph)
    {
        visited[node] = true;
        
        for(auto i: graph[node])
        {
            if(!visited[i])
            {
                dfs(i,visited,topoSort,graph);
            }
        }
        topoSort.emplace_back(node);
    }
    
    vector<int> topoSortusingDFS(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> graph (V,vector<int>(0,0));
        
        for(auto i: edges)
            graph[i[0]].emplace_back(i[1]);
            
        vector<int> visited (V,false);
        vector<int> topoSort;
        
        for(int i = 0; i<V; ++i)
        {
            if(!visited[i])
            {
                dfs(i,visited,topoSort,graph);
            }
        }
        
        reverse(topoSort.begin(), topoSort.end());
        return topoSort;
    }
    
    vector<int> topoSortUsingKahn(int V, vector<vector<int>>& edges)
    {
        queue<int> q;
        vector<int> topoSort;
        vector<int> orderOfNode (V,0);
        
        vector<vector<int>> graph (V,vector<int>(0,0));
        
        //STEP 1: Calculate the order of each edge  
        for(auto i: edges)
        {
            graph[i[0]].emplace_back(i[1]);
            orderOfNode[i[1]]++;
        }
            
        //STEP 2: Initialize a queue with all nodes having zero in-degree
        for(int i = 0; i<V; i++)
        {
            if(orderOfNode[i] == 0)
                q.push(i);
        }
        
        //STEP 3: Process nodes until the queue is empty - when we remove a node with in degree 0, it means we are reducing
        // the in degree for the node on the other side of the edge as well
        while(!q.empty())
        {
            int node = q.front(); q.pop();
            topoSort.push_back(node);
            for(auto i: graph[node])
            {
                orderOfNode[i]--;
                if(orderOfNode[i] == 0)
                    q.push(i);
            }
        }
        
        return topoSort;
    }
    
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        //return topoSortusingDFS(V,edges);
        return topoSortUsingKahn(V,edges);
    }
};