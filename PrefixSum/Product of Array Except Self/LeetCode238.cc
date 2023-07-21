class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        vector<int> f(n);
        auto g = f;
        g[n-1] = f[0] = 1;
        for(int i=1;i<n;i++)
            f[i] = f[i-1] * nums[i-1];
        for(int i=n-2;i>=0;i--)
            g[i] = g[i+1] * nums[i+1];
        for(int i=0;i<n;i++)
        {
            ans.push_back(f[i]*g[i]);
        }

        return ans;
    }
};
