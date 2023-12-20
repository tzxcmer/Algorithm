class Solution {
public:
    unordered_map<int,int> f;
    int getf(int x)
    {
        if(f.find(x) != f.end()) return f[x];
        if(x == 1) return f[x] = 0;
        if(x%2!= 0) return f[x] = getf(3*x+1)+1;
        else return f[x] = getf(x/2)+1;
    }
    int getKth(int lo, int hi, int k) {
        vector<int> ans;
        for(int i=lo;i<=hi;i++)
            ans.push_back(i);
        sort(ans.begin(),ans.end(),[&](int u, int v){
            if (getf(u) != getf(v)) 
                return getf(u) < getf(v);
            else return u < v;
        });
        return ans[k-1];
    }
};
