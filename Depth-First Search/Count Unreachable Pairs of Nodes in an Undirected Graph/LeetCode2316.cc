class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> nums(n);
        vector<int> vis(n);
        for(auto& x : edges)
        {
            nums[x[0]].push_back(x[1]);
            nums[x[1]].push_back(x[0]);
        }
        function<int(int)> dfs = [&](int pos)->int{
            vis[pos] = 1;
            int res = 1;
            for(auto& x : nums[pos])
                if(!vis[x])     
                    res += dfs(x);
            return res;
        };
        long long ans = 0LL,sum = 0LL;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                int t = dfs(i);
                ans += sum * t;
                sum += t;
            }
        }

        return ans;
    }
};
