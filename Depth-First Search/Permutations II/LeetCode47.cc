class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    bool check[9];
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        dfs(nums,0);
        return ans;
    }
    void dfs(vector<int>& nums, int pos)
    {
        if(pos == nums.size())
        {
            ans.push_back(path);
            return ;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(check[i] || 
            (i!=0 && nums[i] == nums[i-1] && !check[i-1]))
                continue;
            path.push_back(nums[i]);
            check[i] = true;
            dfs(nums,pos+1);
            path.pop_back();
            check[i] = false;
        }
    }
};
