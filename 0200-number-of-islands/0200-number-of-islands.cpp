class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& grid)
    {
        int n=grid.size();
        int m=grid[0].size();
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]=='0')
            return;
        grid[i][j]='0';
        dfs(i-1,j,grid);
        dfs(i,j-1,grid);
        dfs(i,j+1,grid);
        dfs(i+1,j,grid);
    }
    int numIslands(vector<vector<char>>& grid) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        int n=grid.size();
        int m=grid[0].size();
        int i,j;
        int c=0;
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                if(grid[i][j]=='1')
                {
                    dfs(i, j, grid);
                    c++;
                }
        return c;
    }
};