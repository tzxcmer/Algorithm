class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> idx2(n);
        iota(idx2.begin(),idx2.end(),0);
        sort(nums1.begin(),nums1.end());
        sort(idx2.begin(),idx2.end(),[&](int i,int j){
            return nums2[i] < nums2[j];
        });
        vector<int> ans(n);
        int l = 0,r = n-1;
        for(auto x : nums1)
        {
            if(x > nums2[idx2[l]])
                ans[idx2[l++]] = x;
            else
                ans[idx2[r--]] = x;
        }

        return ans;
    }
};
