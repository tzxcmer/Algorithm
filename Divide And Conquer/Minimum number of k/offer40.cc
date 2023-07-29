class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        srand(time(NULL));
        mysort(arr,0,arr.size()-1,k);
        return {arr.begin(),arr.begin() + k};
    }

    void mysort(vector<int>& nums,int l,int r,int k)
    {
        if(l >= r)
            return ;
        int key = getrand(nums,l,r);
        int left = l - 1,right = r + 1,i = l;
        while(i < right)
        {
            if(nums[i] < key)
                swap(nums[++left],nums[i++]);
            else if(nums[i] == key) i++;
            else
                swap(nums[--right],nums[i]);
        }

        int a = left - l + 1,b = right - left - 1;
        if(a > k)
            mysort(nums,l,left,k);
        else if(a + b >= k)
            return ;
        else
            mysort(nums,right,r,k-a-b);
    }

    int getrand(vector<int>& nums,int l,int r)
    {
        return nums[rand() % (r-l+1)+l];
    }
};
