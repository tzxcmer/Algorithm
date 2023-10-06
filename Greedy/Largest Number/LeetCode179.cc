class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> str;
        for(auto num : nums) str.push_back(to_string(num));

        sort(str.begin(),str.end(),[](const string& s1,const string& s2){
            return s1 + s2 > s2 + s1;
        });
        string ret;
        for(auto& c : str) ret += c;

        return ret[0] == '0' ? "0" : ret;
    }
};
