class Solution {
public:
    int sum = 0;
    int vis[105][105];
    int dx[4] = {0,0,-1,1};
    int dy[4] = {1,-1,0,0};
    int n,m;
    int movingCount(int _m, int _n, int k) {
        n = _m;
        m = _n;
        dfs(0,0,k);

        return sum;
    }
    void dfs(int x, int y, int k)
    {
        sum++;
        vis[x][y] = true;
        for(int t=0;t<4;t++)
        {
            int i = x+dx[t],j = y+dy[t];
            if(i>=0 && i<n && j>=0 && j<m && check(i,j,k)
             && !vis[i][j])
            {
                dfs(i,j,k);
            }
        }
    }
    bool check(int i, int j,int k)
    {
        int tmp = 0;
        while(i)
        {
            tmp += i % 10;
            i /= 10;
        }
        while(j)
        {
            tmp += j % 10;
            j /= 10;
        }

        return tmp <= k;
    }
};
