class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int n = s.size();
        vector<int> cnt(2);
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            if(s[i] == '1')
            {
                cnt[1]++;
                ans = max(ans,2*min(cnt[0],cnt[1]));
            }
            else if(i == 0 || s[i-1] == '1')
            {
                cnt[0] = 1;
                cnt[1] = 0;
            }
            else
                cnt[0]++;
        }

        return ans;
    }
};
