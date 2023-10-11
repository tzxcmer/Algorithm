class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.size();
        int l = 0,r = n;
        vector<int> ans(n+1);
        for(int i=0;i<n+1;i++)
        {
            if(s[i] == 'I')
                ans[i] = l++;
            else
                ans[i] = r--;
        }

        return ans;
    }
};
