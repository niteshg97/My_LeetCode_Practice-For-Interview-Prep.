class Solution {
public:

    // DFS function
    void dfs(int row, int col,
             vector<vector<char>>& board,
             vector<vector<int>>& vis)
    {
        int n = board.size();
        int m = board[0].size();

        // Current cell ko visited mark karo
        vis[row][col] = 1;

        // 4 Directions
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        for(int k = 0; k < 4; k++)
        {
            int nr = row + dr[k];
            int nc = col + dc[k];

            // Boundary check
            // Sirf unvisited 'O' par DFS karo
            if(nr >= 0 && nr < n &&
               nc >= 0 && nc < m &&
               board[nr][nc] == 'O' &&
               !vis[nr][nc])
            {
                dfs(nr, nc, board, vis);
            }
        }
    }

    void solve(vector<vector<char>>& board) {

        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        // ---------------- First Row ----------------
        for(int j = 0; j < m; j++)
        {
            if(board[0][j] == 'O' && !vis[0][j])
                dfs(0, j, board, vis);
        }

        // ---------------- Last Row ----------------
        for(int j = 0; j < m; j++)
        {
            if(board[n-1][j] == 'O' && !vis[n-1][j])
                dfs(n-1, j, board, vis);
        }
        // ---------------- First Column ----------------
        for(int i = 0; i < n; i++)
        {
            if(board[i][0] == 'O' && !vis[i][0])
                dfs(i, 0, board, vis);
        }
        // ---------------- Last Column ----------------
        for(int i = 0; i < n; i++)
        {
            if(board[i][m-1] == 'O' && !vis[i][m-1])
                dfs(i, m-1, board, vis);
        }
        // Jo 'O' visited nahi hue,
        // wo surrounded hain
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(board[i][j] == 'O' && !vis[i][j])
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};