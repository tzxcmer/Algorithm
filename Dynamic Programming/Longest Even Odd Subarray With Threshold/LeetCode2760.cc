class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int n = nums.size();
        int ans = 0,dp = 0;
        for(int i = n-1;i>=0;i--)
        {
            if(nums[i] > threshold)
                dp = 0;
            else if(i == n-1 || nums[i]%2 != nums[i+1]%2)
                dp++;
            else
                dp = 1;
            if(nums[i] %2 == 0)
            ans = max(dp,ans);
        }

        return ans;
    }
};
