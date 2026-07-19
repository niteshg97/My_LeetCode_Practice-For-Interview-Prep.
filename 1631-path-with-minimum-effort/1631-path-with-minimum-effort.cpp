class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int rows = heights.size();
        int cols = heights[0].size();

        vector<vector<int>> effort(rows, vector<int>(cols, 1e9));

        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;

        // {effort, {row, col}}
        pq.push({0, {0, 0}});
        effort[0][0] = 0;

        vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!pq.empty()) {

            int currEffort = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            // Destination reached
            if (row == rows - 1 && col == cols - 1)
                return currEffort;

            // Ignore outdated entries
            if (currEffort > effort[row][col])
                continue;

            // Explore neighbours
            for (auto move : dir) {

                int newRow = row + move.first;
                int newCol = col + move.second;

                if (newRow >= 0 && newRow < rows && newCol >= 0 &&
                    newCol < cols) {

                    int edgeDiff =
                        abs(heights[row][col] - heights[newRow][newCol]);

                    int newEffort = max(currEffort, edgeDiff);

                    if (newEffort < effort[newRow][newCol]) {

                        effort[newRow][newCol] = newEffort;

                        pq.push({newEffort, {newRow, newCol}});
                    }
                }
            }
        }

        return 0;
    }
};