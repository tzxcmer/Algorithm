class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int begin = 0;
        int n = nums.size();
        if(n == 0)
            return {-1,-1};
        int l = 0,r = n-1;
        while(l < r)
        {
            int mid = (r-l)/2+l;
            if(nums[mid] < target)
                l = mid + 1;
            else
                r = mid;
        }

        if(nums[l] != target) return {-1,-1};
        else
            begin = l;
        int end = 0;
        l = 0,r = n-1;
        while(l < r)
        {
            int mid = (r-l+1)/2+l;
            if(nums[mid] <= target)
                l = mid;
            else
                r = mid-1;
        }

        return {begin,r};
    }
};
