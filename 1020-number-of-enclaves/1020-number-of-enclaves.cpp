class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j) {

        int m = grid.size();    // row
        int n = grid[0].size(); // col

        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) {
            return;
        }
        grid[i][j] = 0;
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
    }

    int numEnclaves(vector<vector<int>>& grid) {

        int m = grid.size();    // row
        int n = grid[0].size(); // col

        for (int row = 0; row < m; row++) {
            // first row pe dfs to check 1....
            if (grid[row][0] == 1) {
                dfs(grid, row, 0);
            }
            // last row pe dfs to check 1 ....
            if (grid[row][n - 1] == 1) {
                dfs(grid, row, n - 1);
            }
        }

        // similary col .. pe dfs
        for (int col = 0; col < n ; col++) {
            // first col pe dfs
            if (grid[0][col] == 1) {
                dfs(grid, 0, col);
            }
            // last col pe dfs
            if (grid[m - 1][col] == 1) {
                dfs(grid, m - 1, col);
            }
        }
        // traverse the grid and count the no of once .....
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    count++;
                }
            }
        }
        return count;
    }
};