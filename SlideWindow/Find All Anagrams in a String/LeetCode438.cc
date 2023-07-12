class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        vector<int> hash1(26),hash2(26);
        for(auto ch : p)
            hash1[ch-'a']++;
        int l = 0,r = 0;
        int cnt = 0;
        int n = s.size();
        int m = p.size();
        while(r < n)
        {
            if(++hash2[s[r]-'a'] <= hash1[s[r]-'a']) cnt++;
            if(r - l + 1 > m)
            {
                if(hash2[s[l]-'a']-- <= hash1[s[l]-'a']) cnt--;
                l++;
            }
            if(cnt == m)
                ans.push_back(l);
            r++;
        }

        return ans;
    }
};
