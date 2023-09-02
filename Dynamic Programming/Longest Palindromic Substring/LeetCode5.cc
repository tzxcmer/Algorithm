class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n));
        string ans;
        int sum = 0;
        int begin = 0;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i;j<n;j++)
            {
                if(s[i] == s[j])
                    dp[i][j] = i+1<j?dp[i+1][j-1] : 1;
                if(dp[i][j] && j-i+1 > sum)
                {
                    sum = j - i + 1;
                    begin = i;
                }
            }
        }

        return s.substr(begin,sum);
    }
};
