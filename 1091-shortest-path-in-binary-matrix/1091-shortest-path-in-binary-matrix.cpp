// approach :1 using BFS algorithm 
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        // If start or destination is blocked
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;
        // 8 possible directions
        vector<pair<int, int>> directions = {{-1, -1}, {-1, 0}, {-1, 1},
                                             {0, -1},  {0, 1},  {1, -1},
                                             {1, 0},   {1, 1}};

        queue<pair<pair<int, int>, int>> q;
        // {{row, col}, pathLength}
        q.push({{0, 0}, 1});
        // Mark source as visited
        grid[0][0] = 1;
        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int length = q.front().second;
            q.pop();
            // Destination reached
            if (row == n - 1 && col == n - 1)
                return length;
            // Visit all 8 neighbours
            for (auto dir : directions) {
                int newRow = row + dir.first;
                int newCol = col + dir.second;
                // Valid and unvisited cell
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n &&
                    grid[newRow][newCol] == 0) {
                    grid[newRow][newCol] = 1; // mark visited
                    q.push({{newRow, newCol}, length + 1});
                }
            }
        }
        return -1;
    }
};