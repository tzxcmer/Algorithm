class Solution {
public:
    bool vis[16][16];
    int ans = 0;
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] != 0)
                {
                    vis[i][j] = true;
                    dfs(grid,i,j,grid[i][j]);
                    vis[i][j] = false;
                }
            }
        }

        return ans;
    }
    int dx[4] = {0,0,-1,1};
    int dy[4] = {1,-1,0,0};
    void dfs(vector<vector<int>>& grid,int x, int y, int path)
    {
        ans = max(ans,path);
        int n = grid.size(),m = grid[0].size();
        for(int k=0;k<4;k++)
        {
            int i = x + dx[k],j = y + dy[k];
            if(i>=0 && i<n && j>=0 && j<m && grid[i][j] != 0 &&
            !vis[i][j])
            {
                vis[i][j] = true;
                dfs(grid,i,j,path+grid[i][j]);
                vis[i][j] = false;
            }
        }
        return;
    }
};
