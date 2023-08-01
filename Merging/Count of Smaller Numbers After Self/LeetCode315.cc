class Solution {
public:
    vector<int> ans,index;
    int tmpnums[500010];
    int tmpindex[500010];
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        ans.resize(n);
        index.resize(n);
        for(int i=0;i<n;i++)
            index[i] = i;
        mergesort(nums,0,n-1);
        return ans;
    }

    void mergesort(vector<int>& nums,int left,int right)
    {
        if(left >= right) return ;
        int mid = (left + right) >> 1;

        mergesort(nums,left,mid);
        mergesort(nums,mid+1,right);

        int c1 = left,c2 = mid + 1,i = 0;
        while(c1 <= mid && c2 <= right)
        {
            if(nums[c1] <= nums[c2])
            {
                tmpnums[i] = nums[c2];
                tmpindex[i++] = index[c2++];
            }
            else
            {
                ans[index[c1]] += right - c2 + 1;
                tmpnums[i] = nums[c1];
                tmpindex[i++] = index[c1++];
            }
        }

        while(c1 <= mid)
        {
            tmpnums[i] = nums[c1];
            tmpindex[i++] = index[c1++];
        }
        while(c2 <= right)
        {
            tmpnums[i] = nums[c2];
            tmpindex[i++] = index[c2++];
        }

        for(int i=left;i<=right;i++)
        {
            nums[i] = tmpnums[i-left];
            index[i] = tmpindex[i-left];
        }
    }
};
