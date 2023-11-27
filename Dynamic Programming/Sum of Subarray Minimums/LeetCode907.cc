class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long ans = 0;
        long long mod = 1e9+7;
        stack<int> s;
        vector<int> dp(n);
        for(int i=0;i<n;i++)
        {
            while(!s.empty() && arr[s.top()] > arr[i])
                s.pop();
            int k = s.empty() ? i+1 : i - s.top();
            dp[i] = k*arr[i] + (s.empty()?0 : dp[i-k]);
            ans = (ans + dp[i]) % mod;
            s.push(i); 
        }

        return ans;
    }
};
