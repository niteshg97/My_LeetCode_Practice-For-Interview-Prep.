class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<vector<char>> grid(n, vector<char>(n, '.'));

        function<bool(int,int)> canPlaceQueen = [&](int row, int col) {
            // column check
            for(int i = row - 1; i >= 0; i--) {
                if(grid[i][col] == 'Q') return false;
            }

            // left diagonal
            for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
                if(grid[i][j] == 'Q') return false;
            }

            // right diagonal
            for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
                if(grid[i][j] == 'Q') return false;
            }

            return true;
        };

        function<void(int)> f = [&](int row) {
            if(row == n) {
                vector<string> temp;
                for(int i = 0; i < n; i++) {
                    temp.push_back(string(grid[i].begin(), grid[i].end()));
                }
                ans.push_back(temp);
                return;
            }

            for(int col = 0; col < n; col++) {
                if(canPlaceQueen(row, col)) {
                    grid[row][col] = 'Q';
                    f(row + 1);
                    grid[row][col] = '.';
                }
            }
        };

        f(0);
        return ans;
    }
};
