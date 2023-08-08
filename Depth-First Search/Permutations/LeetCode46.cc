class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    bool check[7];
    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums);
        return ans;
    }

    void dfs(vector<int>& nums)
    {
        if(nums.size() == path.size())
        {
            ans.push_back(path);
            return ;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(check[i] == false)
            {
                path.push_back(nums[i]);
                check[i] = true;
                dfs(nums);
                path.pop_back();
                check[i] = false;
            }
        }
    }
};
