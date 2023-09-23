class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0,r = height.size()-1;
        int maxl = 0,maxr = 0;
        int ans = 0;
        while(l <= r)
        {
            maxl = max(maxl,height[l]);
            maxr = max(maxr,height[r]);
            if(maxl < maxr)
                ans += maxl - height[l++];
            else
                ans += maxr - height[r--];
        }

        return ans;
    }
};
