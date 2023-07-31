class Solution {
public:
    vector<int> tmp;
    vector<int> sortArray(vector<int>& nums) {
        tmp.resize(nums.size());
        mergesort(nums,0,nums.size()-1);
        return nums;
    }

    void mergesort(vector<int>& nums, int left, int right)
    {
        if(left >= right) return ;
        int mid = (left + right)>>1;
        mergesort(nums,left,mid);
        mergesort(nums,mid+1,right);

        int c1 = left,c2 = mid+1,i=0;
        while(c1<=mid && c2 <= right)
            tmp[i++] = nums[c1] <= nums[c2]?nums[c1++]:nums[c2++];
        
        while(c1 <= mid) tmp[i++] = nums[c1++];
        while(c2 <= right) tmp[i++] = nums[c2++];
        
        for(int i=left;i<=right;i++)
            nums[i] = tmp[i-left];
    }
};
