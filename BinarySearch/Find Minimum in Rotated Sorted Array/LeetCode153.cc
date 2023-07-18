class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0,r = nums.size() - 1;
        int x = nums[r];
        while(l < r)
        {
            int mid = l + (r - l)/2;
            if(nums[mid] > x)
                l = mid + 1;
            else
                r = mid;
        }

        return nums[l];
    }
};
