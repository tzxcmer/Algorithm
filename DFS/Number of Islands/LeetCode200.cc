class Solution {
public:
    void dfs(int x,int y,vector<vector<char> >& grid)
    {
        grid[x][y] = '0';
        if(x>=1 && grid[x-1][y] == '1')
            dfs(x-1,y,grid);
        if(x+1<grid.size() && grid[x+1][y] == '1')
            dfs(x+1,y,grid);
        if(y>=1 && grid[x][y-1] == '1')
            dfs(x,y-1,grid);
        if(y+1<grid[0].size() && grid[x][y+1] == '1')
            dfs(x,y+1,grid);

        return ;
    }
    int numIslands(vector<vector<char>>& grid) {
        // write code here
        int sum = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == '0')
                    continue;
                dfs(i,j,grid);
                    sum++;
            }
        }

        return sum;
    }
};
