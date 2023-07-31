class Solution {
public:
    vector<int> tmp;
    int reversePairs(vector<int>& nums) {
        tmp.resize(nums.size());
        return mergesort(nums,0,nums.size()-1);
    }

    int mergesort(vector<int>& nums, int left, int right)
    {
        if(left >= right) return 0;

        int mid = (left + right) >> 1;
        int ret = 0;
        ret += mergesort(nums,left,mid);
        ret += mergesort(nums,mid+1,right);

        int c1 = left,c2 = mid+1,i=0;
        while(c1 <= mid && c2 <= right)
        {
            if(nums[c1] <= nums[c2])
                tmp[i++] = nums[c1++];
            else
            {
                tmp[i++] = nums[c2++];
                ret += mid - c1 + 1;
            }
        }

        while(c1 <= mid) tmp[i++] = nums[c1++];
        while(c2 <= right) tmp[i++] = nums[c2++];

        for(int j=left;j<=right;j++)
            nums[j] = tmp[j-left];

        return ret;
    }
};
