class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return n;
        int l = 0;
        int sum = 0;
        for(int i=0;i<n-1;i++)
        {
            int r = nums[i+1] - nums[i];
            if(r == 0) continue;
            if(l * r <= 0) sum++;
            l = r;
        }
        return sum+1;
    }
};
