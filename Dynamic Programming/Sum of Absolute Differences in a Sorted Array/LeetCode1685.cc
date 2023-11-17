class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n= nums.size();
        vector<int> ans(n,0);
        ans[0] = accumulate(nums.begin(),nums.end(),0) - nums[0]*n;
        for(int i=1;i<n;i++)
        {
            int d = nums[i] - nums[i-1];
            ans[i] = ans[i-1] - (n-i*2)*d;
        }

        return ans;
    }
};
