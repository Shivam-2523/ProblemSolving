/*
here are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where connections[i] = [ai, bi] represents a connection between computers ai and bi. Any computer can reach any other computer directly or indirectly through the network.

You are given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected.

Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible, return -1.

 

Example 1:


Input: n = 4, connections = [[0,1],[0,2],[1,2]]
Output: 1
Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3.
Example 2:


Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
Output: 2
Example 3:

Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2]]
Output: -1
Explanation: There are not enough cables.
 

Constraints:

1 <= n <= 105
1 <= connections.length <= min(n * (n - 1) / 2, 105)
connections[i].length == 2
0 <= ai, bi < n
ai != bi
There are no repeated connections.
No two computers are connected by more than one cable.
*/


class DSU
{
    public:
    DSU(int n) : parent(n),rank(n,0)
    {
        for(int i = 0; i<n; ++i) parent[i] = i;
    }
    int find (int u)
    {
        if(parent[u] != u)
            parent[u] = find(parent[u]);
        return parent[u];
    }
    bool unite(int u, int v)
    {
        int pu = find(u);
        int pv = find(v);

        if(pu==pv) return false;//already in same set

        if(rank[pu]<rank[pv])
            parent[pu] = pv;
        else if(rank[pv]<rank[pu])
            parent[pv] = pu;
        else
        {
            parent[pv] = pu;
            rank[pv]++;
        }

        return true;
    }
    private:
    vector<int> parent;
    vector<int> rank;
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) return -1;//we need at least n-1 edges
        DSU obj(n);
        int edge = 0;
        for(auto i: connections)
        {
            if(obj.unite(i[0],i[1]))
                edge++;
        }

        return n-1-edge;
    }
};