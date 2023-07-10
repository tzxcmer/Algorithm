class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0,r = 0;
        int cnt = 0;
        int ans = 0;
        while(r < n)
        {
            if(nums[r] == 0) cnt++;
            while(cnt > k)
            {
                if(nums[l++] == 0)
                    cnt--;
            }
            ans = max(ans, r - l + 1);
            r++;
        }

        return ans;
    }
};
