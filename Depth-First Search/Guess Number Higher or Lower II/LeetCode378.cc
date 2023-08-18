class Solution {
public:
    int memo[205][205];
    int getMoneyAmount(int n) {
        return dfs(1,n);
    }
    int dfs(int l, int r)
    {
        if(l >= r)  return 0;
        if(memo[l][r] != 0)
        {
            return memo[l][r];
        }
        int ret = INT_MAX;
        for(int head=l;head<=r;head++)
        {
            int x = dfs(l,head-1);
            int y = dfs(head+1,r);
            ret = min(ret,max(x,y)+head);
        }

        memo[l][r] = ret;
        return ret;
    }
};
