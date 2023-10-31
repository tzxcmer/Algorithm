class Solution {
public:
    vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
        int n = nums.size();
        int p = find(nums.begin(),nums.end(),1) - nums.begin();
        vector<int> ans(n,1);
        if(p == n) return ans;
        vector<int> vis(n + 2);
        vector<vector<int>> nt(n);
        for(int i=1;i<n;i++)
            nt[parents[i]].push_back(i);
        int t = 1;
        auto dfs = [&](auto&& dfs,int rt)->void{
            for(int next : nt[rt])
            {
                if(vis[nums[next]]) continue;
                dfs(dfs,next);
            }
            vis[nums[rt]] = 1;
        };
        while(p != -1)
        {
            dfs(dfs,p);
            while(vis[t]) ++t;
            ans[p] = t;
            p = parents[p];
        }

        return ans;
    }
};
