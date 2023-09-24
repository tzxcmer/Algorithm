class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        const int INF = 0x3f3f3f3f;
        vector<vector<int>> dp(k+2,vector<int>(n,INF));
        dp[0][src] = 0;
        for(int t=1;t<=k+1;t++)
        {
            for(auto&& flight : flights)
            {
                int j = flight[0],i = flight[1],cost = flight[2];
                dp[t][i] = min(dp[t][i],dp[t-1][j]+cost);
            }
        }

        int ans = INF;
        for(int i=1;i<=k+1;i++)
            ans = min(ans,dp[i][dst]);

        return ans == INF ? -1 : ans;
    }
};
