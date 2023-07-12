class Solution {
public:
    string minWindow(string s, string t) {
        int hash1[128] = {0},hash2[128] = {0};
        //unordered_map<char,int> hash1,hash2;
        string ans;
        int kinds = 0;
        for(auto ch : t)
            if(hash1[ch]++ == 0) kinds++;
        // for(auto ch : t)
        //     hash1[ch]++;
        //cout << hash1.size() << endl;  3
        int len = INT_MAX,start = -1;
        int n = s.size();
        for(int l=0,r=0,cnt=0;r<n;r++)
        {
            char in = s[r];
            if(++hash2[in] == hash1[in]) cnt++;
            //cout << hash1.size() << " " << cnt << endl;
            //while(cnt == hash1.size())  变化  3 4 5 6 7
            while(cnt == kinds)
            {
                if(len > r - l + 1)
                {
                    len = r - l + 1;
                    start = l;
                }
                char out = s[l++];
                if(hash2[out]-- == hash1[out]) cnt--;
            }
        }
        if(start == -1) return "";
        else
            return s.substr(start,len);
    }
};
