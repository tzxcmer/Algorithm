class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD= 1000000007;
        int odd = 0,even = 1;
        int sum = 0;
        int ans = 0;
        for(auto num : arr)
        {
            sum += num;
            ans = (ans + (sum%2 == 0 ? odd : even)) % MOD; 
            if(sum %2 == 0)
                even++;
            else
                odd++;
        }

        return ans;
    }
};
