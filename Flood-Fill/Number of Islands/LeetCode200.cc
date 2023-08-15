class Solution {
public:
    bool vis[305][305];
    int m,n;
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int sum = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j] == '1')
                {
                    sum++;
                    dfs(grid,i,j);
                }
            }
        }
        return sum;
    }

    void dfs(vector<vector<char>>& grid,int x, int y)
    {
        vis[x][y] = true;
        for(int k=0;k<4;k++)
        {
            int i = x+dx[k],j = y+dy[k];
            if(i>=0 && i<n && j>=0 && j<m && grid[i][j] == '1'
            && !vis[i][j])
            {
                dfs(grid,i,j);
            }
        }
        return ;
    }
};
