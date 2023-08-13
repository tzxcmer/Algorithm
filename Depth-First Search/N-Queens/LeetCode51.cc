class Solution {
public:
    bool checkcol[10],checkdig1[20],checkdig2[20];
    vector<vector<string>> ans;
    vector<string> path;
    int n;
    vector<vector<string>> solveNQueens(int _n) {
        n = _n;
        path.resize(n);
        for(int i=0;i<n;i++)
            path[i].append(n,'.');
        dfs(0);
        return ans;
    }
    void dfs(int row)
    {
        if(row == n)
        {
            ans.push_back(path);
            return ;
        }
        for(int col=0;col<n;col++)
        {
            if(!checkcol[col] && !checkdig1[row-col+n] && 
            !checkdig2[row+col])
            {
                path[row][col] = 'Q';
                checkcol[col] = checkdig1[row-col+n] = 
                checkdig2[row+col] = true;
                dfs(row+1);
                path[row][col] = '.';
                checkcol[col] = checkdig1[row-col+n] = 
                checkdig2[row+col] = false;
            }
        }
    }
};
