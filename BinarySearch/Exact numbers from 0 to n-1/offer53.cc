class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int l = 0,r = n-1;
        while(l < r)
        {
            int mid = l + (r - l)/2;
            if(nums[mid] == mid)
                l = mid + 1;
            else
                r = mid;
        }

        return nums[l] == l ? l+1:l;
    }
};
