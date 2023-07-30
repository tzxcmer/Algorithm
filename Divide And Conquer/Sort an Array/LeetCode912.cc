class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        srand(time(NULL));
        qsort(nums,0,nums.size()-1);

        return nums;
    }

    void qsort(vector<int>& nums,int l,int r)
    {
        if(l >= r)
            return;
        int key = getrand(nums,l,r);
        int left = l-1,right = r+1,i = l;
        while(i < right)
        {
            if(nums[i] < key) swap(nums[++left],nums[i++]);
            else if(nums[i] == key) i++;
            else swap(nums[--right],nums[i]);
        }
        
        qsort(nums,l,left);
        qsort(nums,right,r);

    }

    int getrand(vector<int>&nums,int l,int r)
    {
        return nums[rand()%(r-l+1)+l];
    }
};
