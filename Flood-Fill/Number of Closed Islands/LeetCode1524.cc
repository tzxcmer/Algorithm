class Solution {
public:
    int m,n;
    int closedIsland(vector<vector<int>>& grid) {
        int ans = 0;
        m = grid.size();
        n = grid[0].size();
        for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            if(grid[i][j] == 0 && dfs(grid,i,j))
                ans++;
        
        return ans;
    }

    bool dfs(vector<vector<int>>& grid,int i,int j)
    {
        if(i<0 || i>=m || j<0 || j>=n)
            return false;
        if(grid[i][j] != 0) return true;
        grid[i][j] = -1;
        bool r1 = dfs(grid,i - 1, j);
        bool r2 = dfs(grid,i + 1, j);
        bool r3 = dfs(grid,i, j - 1);
        bool r4 = dfs(grid,i, j + 1);

        return r1 && r2 && r3 && r4;
    }
};
