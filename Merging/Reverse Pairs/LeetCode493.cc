class Solution {
public:
    int tmp[50010];
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        
        return mergesort(nums,0,n-1);
    }

    int mergesort(vector<int>& nums,int left,int right)
    {
        if(left >= right) return 0;
        int mid = (left + right) >> 1;
        int ans = 0;

        ans += mergesort(nums,left,mid);
        ans += mergesort(nums,mid+1,right);

        int c1 = left,c2 = mid + 1,i = left;
        while(c1 <= mid)
        {
            while(c2 <= right && nums[c1]/2.0 <= nums[c2]) c2++;
            if(c2 > right)  
                break;
            ans += right - c2 + 1;
            c1++;
        }

        c1 = left,c2 = mid + 1;
        while(c1 <= mid && c2 <= right)
            tmp[i++] = nums[c1] <= nums[c2] ? nums[c2++] : nums[c1++];

        while(c1 <= mid)
        {
            tmp[i++] = nums[c1++];
        }
        while(c2 <= right)
        {
            tmp[i++] = nums[c2++];
        }

        for(int i=left;i<=right;i++)
        {
            nums[i] = tmp[i];
        }

        return ans;
    }
};
