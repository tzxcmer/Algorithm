class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash;
        for(auto& s : strs)
        {
            string tmp = s;
            sort(tmp.begin(),tmp.end());
            hash[tmp].push_back(s);
        }

        vector<vector<string>> ans;
        for(auto& [x,y] : hash)
        {
            ans.push_back(y);
        }

        return ans;
    }
};
