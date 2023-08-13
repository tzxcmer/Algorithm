class Solution {
public:
    int sum;
    bool check[16];
    int countArrangement(int n) {
        dfs(n,1);
        return sum;
    }

    void dfs(int n, int pos)
    {
        if(pos == n+1)
        {
            sum++;
            return ;
        }
        for(int i=1;i<=n;i++)
        {
            if(!check[i] && (i%pos == 0 || pos%i == 0))
            {
                check[i] = true;
                dfs(n,pos+1);
                check[i] = false;
            }
        }
    }
};
