class Solution {
public:
    int totalNQueens(int n) {
    int count = 0;
    vector<vector<char>> grid(n, vector<char>(n, '.'));

function<bool(int,int)> canPlaceQueen = [&](int row, int col) {
            // column check
 for(int i = row - 1; i >= 0; i--) {
    if(grid[i][col] == 'Q') return false;
            }

            // left diagonal check
for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
    if(grid[i][j] == 'Q') return false;
            }

            // right diagonal check
for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
    if(grid[i][j] == 'Q') return false;
            }

    return true;
        };

function<void(int)> backtrack = [&](int row) {
    if(row == n) {
        count++;
        return;
        }

for(int col = 0; col < n; col++) {
    if(canPlaceQueen(row, col)) {
    grid[row][col] = 'Q';
    backtrack(row + 1);
        grid[row][col] = '.';
                }
            }
        };

        backtrack(0);
        return count;
    }
};
