class Solution {
public:
    bool vis[205][205];
    vector<pair<int, int>> tmp;
    int m,n,origine;
    int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        m = grid.size();
        n = grid[0].size();
        origine = grid[row][col];
        vis[row][col] = true;
        dfs(grid,row,col);

        for(auto& [x,y] : tmp)
        {
            grid[x][y] = color;
        }

        return grid;
    }

    void dfs(vector<vector<int>>& grid, int row, int col)
    {
        bool flag = false;
        for(int i=0;i<4;i++)
        {
            int x = d[i][0] + row,y = d[i][1] + col;
             if (!(x >= 0 && x < m && y >= 0 && y < n 
             && grid[x][y] == origine))
                flag = true;
            else if(!vis[x][y])
            {
                vis[x][y] = true;
                dfs(grid,x,y);
            }
        }
        if(flag)
                tmp.push_back({row,col});
        return ;
    }
};
