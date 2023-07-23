class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> hash;
        hash[0] = -1;
        for(auto& x : nums)
        {
            if(x == 0)
                x = -1;
        }

        int sum = 0;
        int len = 0;
        for(int i=0;i<n;i++)
        {
            sum += nums[i];
            if(hash.count(sum))
                len = max(len,i-hash[sum]);
            else
                hash[sum] = i;
        }

        return len;
    }
};
