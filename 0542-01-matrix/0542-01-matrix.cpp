class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> dist(m, vector<int>(n, 0));
        vector<vector<int>> vis(m, vector<int>(n, 0));

        queue<pair<int, int>> q;

        // Push all 0's into queue
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (mat[i][j] == 0) {
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while (!q.empty()) {

            auto it = q.front();
            q.pop();

            int row = it.first;
            int col = it.second;

            for (int k = 0; k < 4; k++) {

                int nr = row + dr[k];
                int nc = col + dc[k];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n && !vis[nr][nc]) {

                    vis[nr][nc] = 1;
                    dist[nr][nc] = dist[row][col] + 1;
                    q.push({nr, nc});
                }
            }
        }

        return dist;
    }
};