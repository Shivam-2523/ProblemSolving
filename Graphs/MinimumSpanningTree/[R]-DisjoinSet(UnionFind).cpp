/*
Design a disjoint set (also called union-find) data structure that supports the following operations:



DisjointSet(int n) initializes the disjoint set with n elements.

void unionByRank(int u, int v) merges the sets containing u and v using the rank heuristic.

void unionBySize(int u, int v) merges the sets containing u and v using the size heuristic.

bool find(int u, int v) checks if the elements u and v are in the same set and returns true if they are, otherwise false.


Examples:
Input:

["DisjointSet", "unionByRank", "unionBySize", "find", "find"]

[[5], [0, 1], [2, 3], [0, 1], [0, 3]]



Output:

[null, null, null, true, false]



Explanation:

DisjointSet ds = new DisjointSet(5); // Initialize a disjoint set with 5 elements

ds.unionByRank(0, 1); // Merge sets containing 0 and 1 using rank

ds.unionBySize(2, 3); // Merge sets containing 2 and 3 using size

ds.find(0, 1); // Returns true as 0 and 1 are in the same set

ds.find(0, 3); // Returns false as 0 and 3 are not in the same set

Input:

["DisjointSet", "unionBySize", "unionBySize", "find", "find"]

[[3], [0, 1], [1, 2], [0, 2], [0, 1]]



Output:

[null, null, null, true, true]



Explanation:

DisjointSet ds = new DisjointSet(3); // Initialize a disjoint set with 3 elements

ds.unionBySize(0, 1); // Merge sets containing 0 and 1 using size

ds.unionBySize(1, 2); // Merge sets containing 1 and 2 using rank

ds.find(0, 2); // Returns true as 0 and 2 are in the same set

ds.find(0, 1); // Returns true as 0 and 1 are in the same set
*/


class DisjointSet {
    vector<int> parent;
    vector<int> rank;
    vector<int> size;
public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        size.resize(n, 1);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    // Find with path compression
    int findParent(int u) {
        if (parent[u] != u)
            parent[u] = findParent(parent[u]);
        return parent[u];
    }

    // Checks if u and v belong to the same set
    bool find(int u, int v) {
        return findParent(u) == findParent(v);
    }

    // Union by rank
    void unionByRank(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);
        if (pu == pv) return;
        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else if (rank[pv] < rank[pu]) {
            parent[pv] = pu;
        } else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }

    // Union by size
    void unionBySize(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);
        if (pu == pv) return;
        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};
