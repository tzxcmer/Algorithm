class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int ret = 0;
        for(int i=0;i<n;i++)
        {
            ret ^= nums[i]^i;
        }

        return ret ^ n;
    }
};
