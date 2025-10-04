/*
Given a weighted, undirected, and connected graph with V vertices and E edges, the task is to find the sum of the weights of the edges in the Minimum Spanning Tree (MST) of the graph using Kruskal's Algorithm. The graph is represented as an edge list edges[][], where edges[i] = [u, v, w] denotes an undirected edge between u and v with weight w.

Input: V = 3, E = 3, edges[][] = [[0, 1, 5], [1, 2, 3], [0, 2, 1]]

Output: 4
Explanation:

The Spanning Tree resulting in a weight of 4 is shown above.
Input: V = 2, E = 1, edges = [[0, 1, 5]]
  
Output: 5 
Explanation: Only one Spanning Tree is possible which has a weight of 5.
Constraints:
2 ≤ V ≤ 1000
V-1 ≤ E ≤ (V*(V-1))/2
1 ≤ w ≤ 1000
The graph is connected and doesn't contain self-loops & multiple edges.
*/

// User function Template for C++
class DSU
{
    public:
    DSU(int n): parent(n), rank(n,0) {
        for(int i = 0; i < n; ++i)
            parent[i] = i;
    }
    
    int find(int u)
    {
        if(parent[u]!=u)
            parent[u] = find(parent[u]);
            
        return parent[u];
    }
    
    bool unite(int u, int v)
    {
        int pu = find(u);
        int pv = find(v);
        
        if(pu==pv) return false;
        
        if(rank[pu]<rank[pv])
        {
            parent[pu] = pv;
        }
        else if (rank[pv]<rank[pu])
        {
            parent[pv] = pu;
        }
        else
        {
            parent[pv] = pu;
            rank[pu]++;
        }
        return true;
    }
    
    private:
    vector<int> parent;
    vector<int> rank;
};
class Solution {
  public:
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        // Sort edges by weight
        sort(edges.begin(), edges.end(), [](vector<int>& a, vector<int>& b){
            return a[2] < b[2];
        });
        
        DSU dsu(V);
        int mst_weight = 0, count = 0;

        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            if (dsu.unite(u, v)) {
                mst_weight += w;
                count++;
                if (count == V - 1) break; // MST complete
            }
        }
        return mst_weight;
    }
};

/*
Sort all edges by weight (from smallest to largest).
1.Go through these edges, one by one:
2.If the edge connects two different sets (i.e., they are not already connected, so unite returns true), then add to MST.”
3.Stop once you have V-1 edges in your MST (for V nodes).

Why is this enough?
Start: Each vertex is its own set (component).
Iterate: For each edge (sorted by weight, ascending):
If edge connects two different sets: Add to MST (now they’re united into one set).
If edge connects two vertices already in the same set: Skip (would create a cycle).


so it means apart from the cycle creating edge all the edges of a separate set would be included before hand to a single set, so a next time you find an edge in the same set, it means it will create a cycle
*/