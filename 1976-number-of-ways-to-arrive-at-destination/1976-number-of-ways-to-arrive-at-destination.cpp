class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        const int MOD = 1e9 + 7;

        // Adjacency List -> {neighbour, weight}
        vector<vector<pair<int, int>>> adj(n);

        for (auto& road : roads) {

            int u = road[0];
            int v = road[1];
            int wt = road[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            pq;

        vector<long long> dist(n, LLONG_MAX);
        vector<long long> ways(n, 0);

        dist[0] = 0;
        ways[0] = 1;

        pq.push({0, 0});

        while (!pq.empty()) {

            long long d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            // Ignore outdated entries
            if (d > dist[node])
                continue;

            for (auto& it : adj[node]) {

                int neigh = it.first;
                int wt = it.second;

                // Better shortest path found
                if (d + wt < dist[neigh]) {

                    dist[neigh] = d + wt;

                    ways[neigh] = ways[node];

                    pq.push({dist[neigh], neigh});
                }

                // Another shortest path found
                else if (d + wt == dist[neigh]) {

                    ways[neigh] = (ways[neigh] + ways[node]) % MOD;
                }
            }
        }
        return ways[n - 1];
    }
};