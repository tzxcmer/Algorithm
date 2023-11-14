class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        vector<int> diff(n,0);
        for(int i=0;i<n;i++)
            diff[i] = abs(s[i] - t[i]);
        
        int l = 0,r = 0;
        int sum = 0,ans = 0;
        while(r < n)
        {
            sum += diff[r];
            while(sum > maxCost)
                sum -= diff[l++];
            ans = max(ans, r-l+1);
            r++;
        }

        return ans;
    }
};
