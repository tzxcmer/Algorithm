class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        if(n * m == 0) return n + m;
        vector<vector<int>> dp(n+1,vector<int>(m+1));

        for(int i=0;i<n+1;i++)
            dp[i][0] = i;
        for(int j=0;j<m+1;j++)
            dp[0][j] = j;
        
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<m+1;j++)
            {
                int l = dp[i-1][j] + 1;
                int d = dp[i][j-1] + 1;
                int ld = dp[i-1][j-1];
                if(word1[i-1] != word2[j-1]) ld += 1;
                dp[i][j] = min(l,min(d,ld));
            }
        }

        return dp[n][m];
    }
};
