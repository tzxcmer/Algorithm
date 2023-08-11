class Solution {
public:
    int sum;
    int path;
    int subsetXORSum(vector<int>& nums) {
        dfs(nums,0);
        return sum;
    }
    void dfs(vector<int>& nums, int pos)
    {
        sum += path;
        for(int i=pos;i<nums.size();i++)
        {
            path ^= nums[i];
            dfs(nums,i+1);
            path ^= nums[i];
        }
        return ;
    }
};
