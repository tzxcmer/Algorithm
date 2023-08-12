class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    int n,k;
    vector<vector<int>> combine(int _n, int _k) {
        n = _n;
        k = _k;
        dfs(1);
        return ans;
    }
    void dfs(int pos)
    {
        if(path.size() == k)
        {
            ans.push_back(path);
            return ;
        }
        for(int i=pos;i<=n;i++)
        {
            path.push_back(i);
            dfs(i+1);
            path.pop_back();
        }
    }
};
