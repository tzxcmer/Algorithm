class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        ans.push_back(nums[0]);
        for(int i=1;i<n;i++)
        {
            if(nums[i] > ans.back())
                ans.push_back(nums[i]);
            else
            {
                int l = 0,r = ans.size()-1;
                while(l < r)
                {
                    int mid = (l + r) >> 1;
                    if(nums[i] > ans[mid])
                        l = mid+1;
                    else
                        r = mid;
                }
                ans[l] = nums[i];
            }
        }
        return ans.size();
    }
};
