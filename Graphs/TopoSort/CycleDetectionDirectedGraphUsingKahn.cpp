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
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
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
        
        return topoSort.size() != V;
    }
};