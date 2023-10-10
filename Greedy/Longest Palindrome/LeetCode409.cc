class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> cnt;
        for(auto ch : s)
            cnt[ch]++;
        int ret = 0;
        for(auto [x,y] : cnt)
        {
            if(y == 0) continue;
            ret += y/2*2;
        }

        return ret == s.size() ? ret : ret+1;
    }
};
