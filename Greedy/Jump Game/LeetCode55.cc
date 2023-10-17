class Solution {
public:
    bool canJump(vector<int>& nums) {
        int l = 0,r = 0,n = nums.size();
        int maxPos = 0;
        while(l <= r)
        {
            if(maxPos >= n-1) return true;
            for(int i=l;i<=r;i++)
                maxPos = max(maxPos,nums[i] + i);
            l = r + 1;
            r = maxPos;
        }

        return false;
    }
};
