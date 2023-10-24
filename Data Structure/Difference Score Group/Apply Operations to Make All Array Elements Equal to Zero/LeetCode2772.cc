class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        vector<int> d(n+1);
        for(int i=0;i<n;i++)
        {
            sum += d[i];
            int x = nums[i];
            x += sum;
            if(x == 0) continue;
            if(x < 0 || i+k > n) return false;
            sum -= x;
            d[i+k] += x;
        }
        return true;
    }
};
