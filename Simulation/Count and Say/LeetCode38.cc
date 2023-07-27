class Solution {
public:
    string countAndSay(int n) {
        string ret = "1";
        for(int i=1;i<n;i++)
        {
            string tmp;
            int len = ret.size();
            for(int l = 0,r = 0;r<len;l = r)
            {
                while(r < len && ret[l] == ret[r]) r++;
                tmp += to_string(r - l) + ret[l];
            }
            ret = tmp;
        }

        return ret;
        
    }
};
