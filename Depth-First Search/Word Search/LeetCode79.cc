class Solution {
public:
    vector<vector<char>> board;
    string word;
    bool vis[7][7];
    bool exist(vector<vector<char>>& _board, string _word) {
        board = _board;
        word = _word;
        int n = board.size(),m = board[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j] == word[0])
                {
                    vis[i][j] = true;
                    if(dfs(i,j,1)) return true;
                    vis[i][j] = false;
                }
            }
        }
        return false;
    }
    int dx[4] = {0,0,-1,1};
    int dy[4] = {1,-1,0,0};
    bool dfs(int x, int y, int pos)
    {
        int n = board.size(),m = board[0].size();
        if(pos == word.size())
        {
            return true;
        }
        
        for(int k=0;k<4;k++)
        {
            int i = x + dx[k],j = y + dy[k];
            if(i>=0 && i<n && j>=0 && j<m && !vis[i][j] && 
            board[i][j] == word[pos])
            {
                vis[i][j] = true;
                if(dfs(i,j,pos+1)) return true;
                vis[i][j] = false;
            }
        }
        return false;
    }
};
