class Solution {
public:
    bool vis[50][50];
    int dx[8] = {0,0,-1,1,-1,-1,1,1};
    int dy[8] = {1,-1,0,0,1,-1,-1,1};
    int n,m;
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        n = board.size();
        m = board[0].size();
        int x = click[0];
        int y = click[1];
        if(board[x][y] == 'M')
        {
            board[x][y] = 'X';
            return board;
        }

        dfs(board,x,y);

        return board;
    }

    void dfs(vector<vector<char>>& board,int x,int y)
    {
        int cnt = 0;
        for(int k=0;k<8;k++)
        {
            int i = x+dx[k],j = y+dy[k];
            if(i>=0 && i<n && j>=0 && j<m && board[i][j] == 'M')
            {
                cnt++;
            }
        }
        if(cnt)
        {
            board[x][y] = cnt + '0';
        }
        else 
        {
            board[x][y] = 'B';
            for(int k=0;k<8;k++)
            {
                int i = x+dx[k],j = y+dy[k];
                if(i>=0 && i<n && j>=0 && j<m && board[i][j] == 'E')
                {
                    dfs(board,i,j);
                }
            }
        }
    }
};
