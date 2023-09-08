class Solution {
public:
    int integerReplacement(int n) {
        vector<int> dp(n+1);
        dp[1] = 0;
        for(int i=2;i<=n;i++)
        {
            if(i%2 == 0)
                dp[i] = 1 + dp[i/2];
            else
                dp[i] = 2 + min(dp[i/2],dp[i/2+1]);
        }

        return dp[n];
    }
};
