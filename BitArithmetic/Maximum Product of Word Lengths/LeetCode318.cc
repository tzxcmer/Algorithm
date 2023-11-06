class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> mask(n);
        for(int i=0;i<n;i++)
        {
            string word =words[i];
            int wl = word.size();
            for(int j=0;j<wl;j++)
                mask[i] |= 1 << (word[j] - 'a');
        }
        int ans = 0;
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                if((mask[i] & mask[j]) == 0)
                    ans = max(ans,
                    int(words[i].size() * words[j].size()));
        
        return ans;
    }
};
