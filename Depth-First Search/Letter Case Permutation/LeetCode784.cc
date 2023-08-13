class Solution {
public:
    string path;
    vector<string> ans;
    vector<string> letterCasePermutation(string s) {
        dfs(s,0);
        return ans;
    }
    void dfs(string s,int pos)
    {
        if(path.size() == s.size())
        {
            ans.push_back(path);
            return ;
        }
        
        char ch = s[pos];
        path.push_back(ch);
        dfs(s,pos+1);
        path.pop_back();
        
        if(ch>'9')
        {
            char tmp = change(ch);
            path.push_back(tmp);
            dfs(s,pos+1);
            path.pop_back();
        }
    }

    char change(char ch)
    {
        if(ch>='a' && ch<='z')
            ch -= 32;
        else ch += 32;
        return ch;
    }
};
