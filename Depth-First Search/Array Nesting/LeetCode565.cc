class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int ans = 0;
        for(int i=0;i<nums.size();i++)
        {
            int idx = i,cur = 0;
            while(nums[idx] != -1)
            {
                int t = idx;
                idx = nums[idx];
                nums[t] = -1;
                cur++;
            }
            ans = max(ans,cur);
        }

        return ans;
    }

};
