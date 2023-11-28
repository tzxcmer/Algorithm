class Solution {
public:
    int longestSubstring(string s, int k) {
        int ans = 0;
        int n = s.size();
        for(int i=1;i<=26;i++)
        {
            int l=0,r=0;
            vector<int> cnt(26,0);
            int sum = 0,less = 0;
            while(r < n)
            {
                cnt[s[r]-'a']++;
                if(cnt[s[r]-'a'] == 1)
                {
                    sum++,less++;
                }
                if(cnt[s[r]-'a'] == k)
                    less--;
                while(sum > i)
                {
                    cnt[s[l]-'a']--;
                    if(cnt[s[l]-'a'] == k-1)
                        less++;
                    if(cnt[s[l]-'a'] == 0)
                    {
                        sum--,less--;
                    }
                    l++;
                }
                if(less == 0)
                    ans = max(ans,r-l+1);
                r++;
            }
        }
        return ans;
    }
};
