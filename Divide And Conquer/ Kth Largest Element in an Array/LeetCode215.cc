class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        srand(time(NULL));
        return qsort(nums,0,nums.size()-1,k);
    }

    int qsort(vector<int>& nums,int l,int r,int k)
    {
        if(l == r) return nums[l];
        int key = getrand(nums,l,r);
        int i=l,left = l-1,right = r+1;
        while(i < right)
        {
            if(nums[i] < key) swap(nums[++left],nums[i++]);
            else if(nums[i] == key) i++;
            else swap(nums[--right],nums[i]);
        }

        int c = r-right+1,b = right - left - 1;
        if(c >= k)
            return qsort(nums,right,r,k);
        else if(b + c >= k) return key;
        else
            return qsort(nums,l,left,k-b-c);
    }

    int getrand(vector<int>& nums,int l,int r)
    {
        return nums[rand() % (r-l+1) + l];
    }
};
