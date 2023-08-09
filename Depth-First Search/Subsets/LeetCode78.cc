class Solution {
public:
    vector<int> path;
    vector<vector<int>> ans;
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums,0);
        return ans;
    }

    void dfs(vector<int>& nums,int pos)
    {
        ans.push_back(path);
        for(int i=pos;i<nums.size();i++)
        {
            path.push_back(nums[i]);
            dfs(nums,i+1);
            path.pop_back();
        }
    }
};
