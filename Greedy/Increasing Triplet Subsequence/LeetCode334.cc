class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int a = nums[0];
        int b = INT_MAX;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i] > b)
                return true;
            if(nums[i] > a)
                b = nums[i];
            else
                a = nums[i];
        }

        return false;
    }
};
