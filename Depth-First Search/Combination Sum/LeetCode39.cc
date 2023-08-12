class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    int target;
    vector<vector<int>> combinationSum(vector<int>& candidates, int _target) {
        target = _target;
        dfs(candidates,0,0);

        return ans;
    }

    void dfs(vector<int>& nums,int sum,int pos)
    {
        if(sum == target)
        {
            ans.push_back(path);
            return ;
        }
        else if(sum > target || pos == nums.size()) return ;
        for(int i=0;i*nums[pos]<=target;i++)
        {
            if(i)
            path.push_back(nums[pos]);
            dfs(nums,sum+i*nums[pos],pos+1);
        }
        for(int i=1;i*nums[pos]<=target;i++)
        {
            path.pop_back();
        }
    }
};
