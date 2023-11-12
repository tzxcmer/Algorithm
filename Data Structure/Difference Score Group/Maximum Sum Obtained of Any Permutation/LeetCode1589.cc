class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int MOD = 1000000007;
        int n = nums.size();
        auto cnt = vector<int>(n);
        for(auto ret : requests)
        {
            int l = ret[0],r = ret[1];
            cnt[l]++;
            if(r + 1 < n)
                cnt[r+1]--;
        }
        for(int i=1;i<n;i++) 
            cnt[i] += cnt[i-1];
        
        sort(cnt.begin(),cnt.end());
        sort(nums.begin(),nums.end());
        long long sum = 0;
        for(int i=n-1;i>=0 && cnt[i];i--)
            sum += (long long)cnt[i] * nums[i];
        
        return sum % MOD;
    }
};
