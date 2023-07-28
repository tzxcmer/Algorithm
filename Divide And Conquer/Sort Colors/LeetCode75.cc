class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        for(int i=0,l=-1,r=n;i<r;)
        {
            if(nums[i] == 0)
                swap(nums[++l],nums[i++]);
            else if(nums[i] == 2)
                swap(nums[--r],nums[i]);
            else
                i++;
        }
    }
};
