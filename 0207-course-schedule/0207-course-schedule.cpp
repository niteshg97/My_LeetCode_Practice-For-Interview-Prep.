class Solution {
public:
    bool dfs(int node,
             vector<vector<int>>& adj,
             vector<int>& vis,
             vector<int>& pathVis) {

        vis[node] = 1;
        pathVis[node] = 1;

        for (int neigh : adj[node]) {

            if (!vis[neigh]) {

                if (dfs(neigh, adj, vis, pathVis))
                    return true;
            }
            else if (pathVis[neigh]) {

                return true;
            }
        }
        // Remove from current recursion path
        pathVis[node] = 0;

        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);

        // prerequisite -> course
        for (auto &edge : prerequisites) {

            int course = edge[0];
            int prereq = edge[1];

            adj[prereq].push_back(course);
        }

        vector<int> vis(numCourses, 0);
        vector<int> pathVis(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {

            if (!vis[i]) {

                if (dfs(i, adj, vis, pathVis))
                    return false;
            }
        }

        return true;
    }
};