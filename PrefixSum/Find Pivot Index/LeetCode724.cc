class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n+1);
        auto g = f;
        for(int i=1;i<n+1;i++)
        {
            f[i] = f[i-1] + nums[i-1];
        }
        for(int i=n-2;i>=0;i--)
        {
            g[i] = g[i+1]+nums[i+1];
        }

        for(int i=0;i<n;i++)
        {
            if(f[i] == g[i])
            return i;
        }

        return -1;
    }
};
