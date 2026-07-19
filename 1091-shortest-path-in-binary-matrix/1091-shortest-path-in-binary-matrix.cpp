// using  Dijkestra Algorithm.

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();

        if (grid[0][0] || grid[n - 1][n - 1])
            return -1;

        vector<vector<int>> dist(n, vector<int>(n, 1e9));

        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;

        dist[0][0] = 1;
        pq.push({1, {0, 0}});

        vector<pair<int, int>> dir = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                                      {0, 1},   {1, -1}, {1, 0},  {1, 1}};

        while (!pq.empty()) {

            int d = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            if (row == n - 1 && col == n - 1)
                return d;

            if (d > dist[row][col])
                continue;

            for (auto move : dir) {

                int nr = row + move.first;
                int nc = col + move.second;

                if (nr >= 0 && nr < n && nc >= 0 && nc < n &&
                    grid[nr][nc] == 0) {

                    if (d + 1 < dist[nr][nc]) {

                        dist[nr][nc] = d + 1;
                        pq.push({d + 1, {nr, nc}});
                    }
                }
            }
        }

        return -1;
    }
};