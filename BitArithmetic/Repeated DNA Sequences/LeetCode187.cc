class Solution {
public:
    const int L = 10;
    unordered_map<char, int> bin = {{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        int n = s.size();
        if(n <= L) return ans;
        int x = 0;
        for(int i=0;i<L-1;i++)
            x = (x << 2) | bin[s[i]];
        
        unordered_map<int, int> cnt;
        for(int i=0;i<=n-L;i++)
        {
            x = ((x << 2) | bin[s[i+L-1]]) & ((1 << (L*2)) - 1);
            if(++cnt[x] == 2)
                ans.push_back(s.substr(i,L));
        }

        return ans;
    }
};
