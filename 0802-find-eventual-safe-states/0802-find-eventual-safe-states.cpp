class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        // Reverse graph
        vector<vector<int>> revGraph(n);
        // outdegree of each node
        vector<int> outdegree(n, 0);
        for (int i = 0; i < n; i++) {
            outdegree[i] = graph[i].size();
            for (int neigh : graph[i]) {
                revGraph[neigh].push_back(i);
            }
        }
        queue<int> q;
        // Terminal nodes are safe
        for (int i = 0; i < n; i++) {
            if (outdegree[i] == 0) {
                q.push(i);
            }
        }
        vector<int> safeNodes;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);
            for (int prev : revGraph[node]) {
                outdegree[prev]--;
                if (outdegree[prev] == 0) {
                    q.push(prev);
                }
            }
        }
        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};