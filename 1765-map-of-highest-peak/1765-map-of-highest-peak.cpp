class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {

        int m = isWater.size();
        int n = isWater[0].size();

        vector<vector<int>> height(m, vector<int>(n, -1));
        queue<pair<int,int>> q;
        // Push all water cells
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(isWater[i][j] == 1) {
                    height[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while(!q.empty()) {

            auto [row, col] = q.front();
            q.pop();

            for(int k = 0; k < 4; k++) {

                int nr = row + dr[k];
                int nc = col + dc[k];

                if(nr >= 0 && nr < m &&
                   nc >= 0 && nc < n &&
                   height[nr][nc] == -1) {

                    height[nr][nc] = height[row][col] + 1;
                    q.push({nr, nc});
                }
            }
        }

        return height;
    }
};