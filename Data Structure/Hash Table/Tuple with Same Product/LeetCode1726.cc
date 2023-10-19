class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> cnt;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                cnt[nums[i]*nums[j]]++;
            }
        }
        int ans = 0;
        for(auto& [x,y] : cnt)
        {
            ans += y * (y-1)*4;
        }

        return ans;
    }
};
