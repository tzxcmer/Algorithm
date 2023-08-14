class Solution {
public:
    int dx[4] = {0,0,-1,1};
    int dy[4] = {1,-1,0,0};
    bool vis[20][20];
    int ans,step;
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size();
        int bx,by;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 0) step++;
                else if(grid[i][j] == 1)
                {
                    bx = i;
                    by = j;
                }
            }
        }
        step += 2; 
        vis[bx][by] = true;
        dfs(grid,bx,by,1);
        return ans;
    }
    void dfs(vector<vector<int>>& grid,int x, int y,int path)
    {
        int n = grid.size(),m = grid[0].size();
        if(grid[x][y] == 2)
        {
            if(path == step)
                ans++;
            return ;
        }
        for(int k=0;k<4;k++)
        {
            int i = x + dx[k],j = y + dy[k];
            if(i>=0 && i<n && j>=0 && j<m &&
            !vis[i][j] && grid[i][j] != -1)
            {
                vis[i][j] = true;
                dfs(grid,i,j,path+1);
                vis[i][j] = false;
            }
        }
        return ;
    }
};
