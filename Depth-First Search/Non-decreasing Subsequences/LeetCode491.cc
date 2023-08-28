class Solution {
public:
    vector<int> tmp;
     vector<vector<int>> ans;
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        dfs(0,INT_MIN,nums);

        return ans;
    }

    void dfs(int cur, int t, vector<int>& nums)
    {
        if(cur == nums.size())
        {
            if(tmp.size() >= 2)
                ans.push_back(tmp);
            return ;
        }
        if(nums[cur] >= t)
        {
            tmp.push_back(nums[cur]);
            dfs(cur+1,nums[cur],nums);
            tmp.pop_back();
        }

        if(nums[cur] != t)
            dfs(cur+1,t,nums);
        
    }
};
