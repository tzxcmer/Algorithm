class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        unordered_map<string,int> hash1;
        for(auto& str : words)
            hash1[str]++;
        int n = s.size();
        int m = words.size();
        int len = words[0].size();
        for(int i=0;i<len;i++)
        {
            unordered_map<string,int> hash2;
            for(int l = i,r = i,cnt = 0;r+len <= n;r += len)
            {
                string in = s.substr(r,len);
                if(hash1.count(in) && ++hash2[in] <= hash1[in]) cnt++;
                if(r - l + 1 > m * len)
                {
                    string out = s.substr(l,len);
                    if(hash1.count(out) && 
                    hash2[out]-- <= hash1[out]) cnt--;
                    l += len;
                }
                if(cnt == m)
                    ans.push_back(l);
            }
        }

        return ans;
    }
};
