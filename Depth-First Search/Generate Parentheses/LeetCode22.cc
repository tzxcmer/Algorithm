class Solution {
public:
    vector<string> ans;
    string path;
    int l=0,r=0,n;
    vector<string> generateParenthesis(int _n) {
        n = _n;
        dfs();
        return ans;
    }
    void dfs()
    {
        if(r == n)
        {
            ans.push_back(path);
            return ;
        }
        if(l < n)
        {
            path.push_back('(');l++;
            dfs();
            path.pop_back();l--;
        }

        if(r < l)
        {
            path.push_back(')');r++;
            dfs();
            path.pop_back();r--;
        }
    }
};
