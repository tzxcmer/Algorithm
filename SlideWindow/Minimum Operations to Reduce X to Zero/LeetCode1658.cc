class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int sum = 0;
        for(auto num : nums) sum += num;
        int tar = sum - x;
        if(tar < 0)
            return -1;
        int l = 0,r = 0;
        int ans = -1;
        int tmp = 0;
        while(r < n)
        {
            tmp += nums[r];
            while(tmp > tar)
            {
                tmp -= nums[l++];
            }
            if(tmp == tar)
                ans = max(ans, r - l + 1);
            r++;
        }

        if(ans == -1)
            return ans;
        else
            return n - ans;
    }
};
