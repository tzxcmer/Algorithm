class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int ret = 0;
        vector<int> memo(nums.size());
        for(int i=0;i<nums.size();i++)
            ret = max(ret,dfs(i,nums,memo));

        return ret;
    }

    int dfs(int pos, vector<int>& nums, vector<int>& memo)
    {
        if(memo[pos] != 0) return memo[pos];
        int ret = 1;
        for(int i=pos+1;i<nums.size();i++)
            if(nums[i] > nums[pos])
                ret = max(ret,dfs(i,nums,memo)+1);
        memo[pos] = ret;
        return ret;
    }
};
