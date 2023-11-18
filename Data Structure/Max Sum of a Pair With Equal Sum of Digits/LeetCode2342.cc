class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, int> hash;
        int n = nums.size();
        int ans = -1;
        for(int i=0;i<n;i++)
        {
            int num = nums[i];
            int t = 0;
            while(num)
            {
                t += num%10;
                num /= 10;
            }
            if(hash.empty() || !hash.count(t))
            {
                hash[t] = i;
            }
            else
            {
                ans = max(ans,nums[i] + nums[hash[t]]);
                if(nums[i] > nums[hash[t]])
                    hash[t] = i;
            }
        }

        return ans;
    }
};
