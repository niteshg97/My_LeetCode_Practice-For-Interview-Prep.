class Solution {
public:
    vector<vector<int>> adj;
    vector<int> state; // 0=unvisited, 1=visiting, 2=visited
    vector<int> order;
    bool hasCycle = false;

    void dfs(int u) {
        state[u] = 1; // visiting

        for (int v : adj[u]) {
            if (state[v] == 0) {
                dfs(v);
                if (hasCycle) return;
            }
            else if (state[v] == 1) {
                hasCycle = true;
                return;
            }
        }

        state[u] = 2;
        order.push_back(u);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        adj.assign(numCourses, {});
        state.assign(numCourses, 0);
        order.clear();
        hasCycle = false;

        // b -> a
        for (auto &p : prerequisites) {
            adj[p[1]].push_back(p[0]);
        }

        for (int i = 0; i < numCourses; i++) {
            if (state[i] == 0) {
                dfs(i);
                if (hasCycle) return {};
            }
        }

        reverse(order.begin(), order.end());
        return order;
    }
};


