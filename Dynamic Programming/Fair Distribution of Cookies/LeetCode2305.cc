class Solution {
public:
    int distributeCookies(vector<int>& cookies, int k) {
        int n = cookies.size();
        vector<int> sum(1 << n);
        //利用比特位，把所有饼干的排列总和计算出来
        for(int i=0;i<n;i++)
            for(int j=0,bit=1<<i;j<bit;j++)
                sum[bit | j] = sum[j] + cookies[i];
        //初始状态设置为每个孩子还没有获得任何饼干,不公平度就是饼干总数
        vector<int> f(sum);
        //将饼干分给 i 个孩子的情况
        for(int i=1;i<k;i++)
            // j 遍历所有状态,从后向前遍历
            for(int j=(1<<n)-1;j>0;j--)
                //枚举 j 的每个子集 s
                for(int s = j;s;s = (s-1) & j)
                    f[j] = min(f[j],max(f[j^s],sum[s]));

        return f.back();
    }
};
