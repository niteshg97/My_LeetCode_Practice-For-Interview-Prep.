class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> cols(9);
        vector<unordered_set<char>> boxes(9);
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                char ch = board[row][col];
                // Skip empty cells
                if (ch == '.')
                    continue;
                int box = (row / 3) * 3 + (col / 3);
                // Duplicate found
                if (rows[row].count(ch) ||
                    cols[col].count(ch) ||
                    boxes[box].count(ch)) {
                    return false;
                }
                // Mark current digit
                rows[row].insert(ch);
                cols[col].insert(ch);
                boxes[box].insert(ch);
            }
        }
        return true;
    }
};