class Solution {
public:
    vector<vector<int>> ans;
    int n;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        n = candidates.size();
        dfs(candidates,target,0,path);

        return ans;
    }

    void dfs(vector<int>& nums,int target,int pos,vector<int>& path)
    {
        if(0 == target)
        {
            ans.push_back(path);
            return ;
        }
        for(int i=pos;i<n;i++)
        {
            if(target - nums[i] < 0)
                break;
            if (i > pos && nums[i] == nums[i - 1]) {
                continue;
            }
            path.push_back(nums[i]);
            dfs(nums,target - nums[i],i+1,path);
            path.pop_back();
        }
    }
};
