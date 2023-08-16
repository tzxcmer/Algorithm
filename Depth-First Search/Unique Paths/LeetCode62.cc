class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> memo(m+1,vector<int>(n+1));

        return dfs(m,n,memo);
    }

    int dfs(int m, int n, vector<vector<int>>& memo)
    {
        if(memo[m][n] != 0)
        {
            return memo[m][n];
        }

        if(m == 0 || n == 0)
            return 0;
        if(m == 1 && n == 1)
        {
            memo[m][n] = 1;
            return memo[m][n];
        }
        memo[m][n] = dfs(m,n-1,memo) + dfs(m-1,n,memo);

        return memo[m][n];
    }

};
