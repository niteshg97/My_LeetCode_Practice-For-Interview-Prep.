class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();

        // Must start from (0,0)
        if (grid[0][0] != 0) return false;

        // Knight moves
        vector<pair<int,int>> moves = {
            {2,1},{1,2},{-1,2},{-2,1},
            {-2,-1},{-1,-2},{1,-2},{2,-1}
        };

        int x = 0, y = 0;

        for (int step = 1; step < n * n; step++) {
            bool found = false;
            for (auto [dx, dy] : moves) {
                int nx = x + dx;
                int ny = y + dy;
                if (nx >= 0 && ny >= 0 && nx < n && ny < n &&
                    grid[nx][ny] == step) {
                    x = nx;
                    y = ny;
                    found = true;
                    break;
                }
            }
            if (!found) return false;
        }

        return true;
    }
};