class Solution {
public:
    bool vis[205][205];
    int m,n;
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    void solve(vector<vector<char>>& board) {
        n = board.size();
        m = board[0].size();
        for(int i=0;i<n;i++)
        {
            if(!vis[i][0] && board[i][0] == 'O')
            {
                dfs(board,i,0);
            }
            if(!vis[i][m-1] && board[i][m-1] == 'O')
            {
                dfs(board,i,m-1);
            }
        }
        for(int j=0;j<m;j++)
        {
            if(!vis[0][j] && board[0][j] == 'O')
            {
                dfs(board,0,j);
            }
            if(!vis[n-1][j] && board[n-1][j] == 'O')
            {
                dfs(board,n-1,j);
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if( board[i][j] == 'O')
                    board[i][j] = 'X';
                else if(board[i][j] == '.')
                    board[i][j] = 'O';
            }
        }
    }

    void dfs(vector<vector<char>>& board,int x, int y)
    {
        vis[x][y] = true;
        board[x][y] = '.';
        for(int k=0;k<4;k++)
        {
            int i = x+dx[k],j = y+dy[k];
            if(i>=0 && i<n && j>=0 && j<m && board[i][j] == 'O'
            && !vis[i][j])
            {
                board[i][j] = '.';
                dfs(board,i,j);
            }
        }
        return ;
    }
};
