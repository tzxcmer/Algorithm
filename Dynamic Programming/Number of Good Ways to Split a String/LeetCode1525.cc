class Solution {
public:
    int numSplits(string s) {
        int n = s.size();
        vector<int> f(n+2),g(n+2);
        bitset<26> l,r;
        for(int i=1;i<=n;i++)
        {
            int c = s[i-1] - 'a';
            if(l.test(c))
                f[i] = f[i-1];
            else
            {
                l.set(c);
                f[i] = f[i-1] + 1;
            }
        }
        for(int i=n;i>0;i--)
        {
            int c = s[i-1] - 'a';
            if(r.test(c))
                g[i] = g[i+1];
            else
            {
                r.set(c);
                g[i] = g[i+1] + 1;
            }
        }
        int res = 0;
        for(int i=1;i<n;i++)
        {
            if(f[i] == g[i+1])
                res++;
        }

        return res;
    }
};
