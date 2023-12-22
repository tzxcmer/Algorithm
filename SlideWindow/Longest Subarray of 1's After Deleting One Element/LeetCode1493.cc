class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans = 0;
        int p0 = 0,p1 = 0;
        for(auto num : nums)
        {
            if(num == 0)
            {
                p1 = p0;
                p0 = 0;
            }
            else
            {
                ++p0;
                ++p1;
            }
            ans = max(p1,ans);
        }
        if(ans == nums.size())
            --ans;

        return ans;
    }
};
