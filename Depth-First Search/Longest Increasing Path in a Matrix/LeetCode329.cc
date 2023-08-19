class Solution {
public:
    int m,n;
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    int memo[210][210];
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        int ret = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                ret = max(ret,dfs(matrix,i,j));
            }
        }

        return ret;
    }
    int dfs(vector<vector<int>>& matrix, int x, int y)
    {
        if(x>=0 && x<m && y<n && y>=0)
            if(memo[x][y] != 0)
                return memo[x][y];
        int ret = 1;
        for(int k=0;k<4;k++)
        {
            int i=dx[k]+x,j = dy[k]+y;
            if(i>=0 && i<m && j<n && j>=0 
            && matrix[i][j] > matrix[x][y])
            ret = max(ret,dfs(matrix,i,j)+1);
        }
        memo[x][y] = ret;
        return ret;
    }
};
