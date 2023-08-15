class Solution {
public:
    bool vis[305][305];
    int m,n;
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    int sum;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j] == 1)
                {
                    sum = 1;
                    dfs(grid,i,j);
                    ans = max(ans,sum);
                }
            }
        }

        return ans;
    }

    void dfs(vector<vector<int>>& grid,int x, int y)
    {
        vis[x][y] = true;
        for(int k=0;k<4;k++)
        {
            int i = x+dx[k],j = y+dy[k];
            if(i>=0 && i<n && j>=0 && j<m && grid[i][j] == 1
            && !vis[i][j])
            {
                sum++;
                dfs(grid,i,j);
            }
        }
        return ;
    }
};
