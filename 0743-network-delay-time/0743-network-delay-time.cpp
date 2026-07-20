class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        // Adjacency List -> {neighbour, weight}
        unordered_map<int, vector<pair<int, int>>> adj;

        vector<int> result(n + 1, INT_MAX);

        // Build graph
        for (auto& time : times) {

            int u = time[0];
            int v = time[1];
            int w = time[2];

            adj[u].push_back({v, w});
        }

        result[k] = 0; // Distance from source to itself
        pq.push({0, k});

        while (!pq.empty()) {

            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            // Skip outdated entry
            if (d > result[node])
                continue;

            // Traverse neighbours
            for (auto& it : adj[node]) {

                int adjNode = it.first;
                int wt = it.second;

                if (d + wt < result[adjNode]) {

                    result[adjNode] = d + wt;

                    pq.push({result[adjNode], adjNode});
                }
            }
        }

        int ans = 0;

        for (int i = 1; i <= n; i++) {

            if (result[i] == INT_MAX)
                return -1;

            ans = max(ans, result[i]);
        }

        return ans;
    }
};