class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> hash;
        hash[0] = 1;
        int sum = 0;
        int ans = 0;

        for(auto x : nums)
        {
            sum += x;
            int r = (sum%k + k) % k;
            if(hash.count(r))
                ans += hash[r];
            hash[r]++;
        }

        return ans;
    }
};
