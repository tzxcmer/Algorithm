class Solution {
public:
    int sum;
    int target;
    int findTargetSumWays(vector<int>& nums, int _target) {
        target = _target;
        dfs(nums,0,0);
        return sum;
    }

    void dfs(vector<int>& nums,int pos,int path)
    {
        if(pos == nums.size())
        {
            if(path == target)
                sum++;
            return ;
        }
        dfs(nums,pos+1,path+nums[pos]);
        dfs(nums,pos+1,path-nums[pos]);
    }
};
