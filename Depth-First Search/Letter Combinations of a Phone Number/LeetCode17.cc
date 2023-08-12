class Solution {
public:
    string hash[10] = {"","","abc","def","ghi","jkl","mno",
    "pqrs","tuv","wxyz"};
    vector<string> ans;
    string path;
    vector<string> letterCombinations(string digits) {
        if(digits.empty())
            return {};
        dfs(digits,0);
        return ans;
    }
    void dfs(string& digits, int pos)
    {
        if(pos == digits.size())
        {
            ans.push_back(path);
            return ;
        }

        for(auto ch : hash[digits[pos] - '0'])
        {
            path.push_back(ch);
            dfs(digits,pos+1);
            path.pop_back();
        }
    }
};
