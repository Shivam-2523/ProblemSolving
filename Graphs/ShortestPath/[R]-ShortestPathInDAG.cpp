/*
Given a Directed Acyclic Graph of V vertices from 0 to n-1 and a 2D Integer array(or vector) edges[ ][ ] of length E, where there is a directed edge from edge[i][0] to edge[i][1] with a distance of edge[i][2] for all i.

Find the shortest path from src(0) vertex to all the vertices and if it is impossible to reach any vertex, then return -1 for that vertex.

Examples :

Input: V = 4, E = 2, edges = [[0,1,2], [0,2,1]]
Output: [0, 2, 1, -1]
Explanation: Shortest path from 0 to 1 is 0->1 with edge weight 2. Shortest path from 0 to 2 is 0->2 with edge weight 1. There is no way we can reach 3, so it's -1 for 3.
Input: V = 6, E = 7, edges = [[0,1,2], [0,4,1], [4,5,4], [4,2,2], [1,2,3], [2,3,6], [5,3,1]]
Output: [0, 2, 3, 6, 1, 5]
Explanation: Shortest path from 0 to 1 is 0->1 with edge weight 2. Shortest path from 0 to 2 is 0->4->2 with edge weight 1+2=3. Shortest path from 0 to 3 is 0->4->5->3 with edge weight 1+4+1=6. Shortest path from 0 to 4 is 0->4 with edge weight 1.Shortest path from 0 to 5 is 0->4->5 with edge weight 1+4=5.
Constraint:
1 <= V <= 100
1 <= E <= min((N*(N-1))/2,4000)
0 <= edgesi,0, edgesi,1 < n
0 <= edgei,2 <=105
*/


// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        queue<int> q;
        vector<vector<pair<int,int>>> graph(V);//{toEdge,distance}
        vector<int> inorder (V,0);
        vector<int> topo;
        
        //STEP 1: Do the Topo Sort
        for(auto i: edges)
        {
            graph[i[0]].push_back({i[1],i[2]});
            inorder[i[1]]++;
        }
        
        for(int i = 0; i<V; ++i)
        {
            if(inorder[i] == 0)
                q.push(i);
        }
    
        while(!q.empty())
        {
            auto node = q.front(); q.pop();
            topo.push_back(node);
            
            for(auto j: graph[node])
            {
                inorder[j.first]--;
                if(inorder[j.first]==0)
                    q.push(j.first);
            }
        }
        
        //STEP 2: Edge Relaxation
        vector<int> dist(V, INT_MAX);
        dist[0] = 0; // Assuming source is node 0
        
        for(int node : topo) {
            if(dist[node] == INT_MAX) continue; // Skip unreachable nodes
            for(auto& nbr : graph[node]) {
                int v = nbr.first, w = nbr.second;
                if(dist[node] + w < dist[v]) {
                    dist[v] = dist[node] + w;
                }
            }
        }
        
        // Optional: Set unreachable nodes to -1 if required by the problem
        for (int i=0; i<V; ++i) if (dist[i]==INT_MAX) dist[i]=-1;
        
        return dist;
    }
};
/*
The topological order guarantees: when you process u, you’ve already processed all possible paths to u from the source.
This means, when relaxing edges from u, dist[u] is correct and up-to-date.
You only need to go through the graph once.
*/
