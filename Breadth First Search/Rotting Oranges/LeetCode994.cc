class Solution {
public:
    int cnt = 0;
    int dx[4]={0, 1, 0, -1};
    int dy[4]={1, 0, -1, 0};
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>> dis(10,vector<int>(10,-1));
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push(make_pair(i,j));
                    dis[i][j] = 0;
                }
                else if(grid[i][j] == 1)
                    cnt += 1; 
            }
        }
        int ans = 0;
        while(!q.empty())
        {
            pair<int, int> t = q.front();
            q.pop();
            for(int i=0;i<4;i++)
            {
                int x = t.first + dx[i];
                int y = t.second + dy[i];
                if(x<0 || x >=n || y<0 || y>=m || ~dis[x][y] ||
                !grid[x][y])
                    continue;
                dis[x][y] = dis[t.first][t.second] + 1;
                q.push(make_pair(x,y));
                if(grid[x][y] == 1)
                {
                    cnt--;
                    ans = dis[x][y];
                    if(!cnt) break;
                }
            }
        }

        return cnt ? -1 : ans;
    }
};
