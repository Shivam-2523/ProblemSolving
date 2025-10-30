/*
Given a weighted, undirected, and connected graph with V vertices and E edges, your task is to find the sum of the weights of the edges in the Minimum Spanning Tree (MST) of the graph. The graph is provided as a list of edges, where each edge is represented as [u, v, w], indicating an edge between vertex u and vertex v with edge weight w.

Input: V = 3, E = 3, Edges = [[0, 1, 5], [1, 2, 3], [0, 2, 1]]
 
Output: 4
Explanation:

The Spanning Tree resulting in a weight
of 4 is shown above.
Input: V = 2, E = 1, Edges = [[0 1 5]]

 

Output: 5 
Explanation: Only one Spanning Tree is possible which has a weight of 5.
Constraints:
2 ≤ V ≤ 1000
V-1 ≤ E ≤ (V*(V-1))/2
1 ≤ w ≤ 1000
The graph is connected and doesn't contain self-loops & multiple edges.
*/


class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(V);
        for(auto& i : edges) {
            int from = i[0], to = i[1], weight = i[2];
            adj[from].push_back({to, weight});
            adj[to].push_back({from, weight});
        }
        
        using pqType = pair<int,int>; // {weight, node}
        priority_queue<pqType, vector<pqType>, greater<pqType>> pq;
    
        vector<bool> visited(V, false);
        pq.push({0, 0}); // {weight, node}
        int mst = 0;
    
        while(!pq.empty()) {
            auto [weight, node] = pq.top(); pq.pop();
            if(visited[node]) continue;
            // Add the edge's weight on entering the node for the first time
            mst += weight;
            visited[node] = true;
            for(auto& [to, w] : adj[node]) {
                if(!visited[to]) {
                    pq.push({w, to});
                }
            }
        }
        return mst;
    }
};