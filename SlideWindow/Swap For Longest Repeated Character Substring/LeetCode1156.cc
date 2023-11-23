class Solution {
public:
    int maxRepOpt1(string text) {
        unordered_map<char, int> count;
        for(auto c : text)
            count[c]++;
        
        int res = 0;
        int n = text.size();
        for(int i=0;i<n;)
        {
            int j = i;
            while(j < n && text[j] == text[i]) j++;
            int cnt = j - i;
            if(cnt < count[text[i]] && (j < n || i > 0))
                res = max(res,cnt+1);
            int k = j + 1;
            while(k < n && text[k] == text[i]) k++;
            res = max(res,min(k-i,count[text[i]]));
            i = j;
        }

        return res;
    }
};
