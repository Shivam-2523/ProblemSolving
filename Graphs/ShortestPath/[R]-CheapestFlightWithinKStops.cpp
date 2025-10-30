/*
There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.

 

Example 1:


Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
Output: 700
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 = 700.
Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.
Example 2:


Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
Output: 200
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 2 is marked in red and has cost 100 + 100 = 200.
Example 3:


Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 0
Output: 500
Explanation:
The graph is shown above.
The optimal path with no stops from city 0 to 2 is marked in red and has cost 500.
 

Constraints:

1 <= n <= 100
0 <= flights.length <= (n * (n - 1) / 2)
flights[i].length == 3
0 <= fromi, toi < n
fromi != toi
1 <= pricei <= 104
There will not be any multiple flights between two cities.
0 <= src, dst, k < n
src != dst
*/


class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Adjacency list
        vector<vector<pair<int, int>>> adj(n); // {dest, price}
        for (const auto& i : flights) {
            int from = i[0], to = i[1], cost = i[2];
            adj[from].push_back({to, cost});
        }

        // price[node][stops] = min cost to node with 'stops' edges traversed
        vector<vector<int>> price(n, vector<int>(k + 2, INT_MAX));
        price[src][0] = 0;

        // (cost, node, stops)
        using T = tuple<int, int, int>;
        priority_queue<T, vector<T>, greater<T>> pq;
        pq.push({0, src, -1}); // Start at src with 0 stops

        while (!pq.empty()) {
            auto [cost, node, stops] = pq.top(); pq.pop();

            // If stops > k+1, we've exceeded the allowed number of flights (so at most k stops = up to k+1 flights)
            if (stops >= k) continue;

            for (auto& [dest, destCost] : adj[node]) {
                if (cost + destCost < price[dest][stops + 1]) {
                    price[dest][stops + 1] = cost + destCost;
                    pq.push({cost + destCost, dest, stops + 1});
                }
            }
        }

        // Now pick the minimum cost to dst with stops from 0 to k + 1
        int ans = INT_MAX;
        for (int s = 0; s <= k + 1; ++s)
            ans = min(ans, price[dst][s]);
        return ans == INT_MAX ? -1 : ans;
    }
};

/*
//BFS SOLUTION -ONLY POSSIBLE BECAUSE THERE IS A LIMIT K

class Solution {
public:
    int stop=0;

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {


       // cost node stop 
       // visited node

       vector<vector<pair<int,int>>>graph(n);

       vector<int>minCost(n,INT_MAX);
       minCost[src]=0;
       for(auto& flight : flights){
        int u=flight[0];
        int v=flight[1];
        int w=flight[2];
        graph[u].emplace_back(v,w);


       }

       // lets go
       queue<tuple<int, int,int>>q;
       q.push({src,0,0});


       while (!q.empty()) {
            auto [node, cost, stops] = q.front();
            q.pop();

            if (stops > k) continue;

            for (auto& [nei, price] : graph[node]) {
                int newCost = cost + price;
                if (newCost < minCost[nei]) {
                    minCost[nei] = newCost;
                    q.emplace(nei, newCost, stops + 1);
                }
            }
        }

        return minCost[dst] == INT_MAX ? -1 : minCost[dst];
    }
};
*/