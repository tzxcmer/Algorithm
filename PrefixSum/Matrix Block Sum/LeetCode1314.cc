class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n = mat.size(),m = mat[0].size();
        vector<vector<int>> dp(n+1, vector<int>(m+1)), 
                            ans(n,vector<int>(m));
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<m+1;j++)
            {
                dp[i][j] = dp[i-1][j] + dp[i][j-1] + 
                mat[i-1][j-1] - dp[i-1][j-1];
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int x1 = max(i-k,0) + 1;
                int y1 = max(j-k,0) + 1;
                int x2 = min(i+k,n-1) + 1;
                int y2 = min(j+k,m-1) + 1;
                ans[i][j] = dp[x2][y2] - dp[x1-1][y2] - dp[x2][y1-1] +
                dp[x1-1][y1-1];
            }
        }

        return ans;
    }
};
