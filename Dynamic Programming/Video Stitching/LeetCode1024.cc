class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        vector<int> dp(time+1,INT_MAX-1);
        dp[0] = 0;
        for(int i=1;i<=time;i++)
        {
            for(auto it : clips)
            {
                if(it[0] < i && i <= it[1])
                    dp[i] = min(dp[i],dp[it[0]]+1);
            }
        }

        return dp[time] == INT_MAX-1 ? -1 : dp[time];
    }
};
