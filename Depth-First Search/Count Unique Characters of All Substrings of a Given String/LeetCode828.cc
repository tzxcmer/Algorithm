class Solution {
public:
    int uniqueLetterString(string s) {
        int ans = 0,n = s.size();
        for(int i=0;i<n;i++)
        {
            int l = i,r = i;
            while(l && s[l-1] !=s[i]) l--;
            while(r<n-1 && s[r+1] != s[i]) r++;
            ans += (i-l+1) * (r-i+1);
        }

        return ans;
    }
};
