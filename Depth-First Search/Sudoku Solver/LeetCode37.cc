class Solution {
public:
    bool row[9][10],col[9][10],grid[3][3][10];
    void solveSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++)
            {
                if(board[i][j] != '.')
                {
                    int num = board[i][j] - '0';
                    row[i][num] = col[j][num] = 
                            grid[i/3][j/3][num] = true;
                }
            }
        dfs(board);
            return ;
    }
    bool dfs(vector<vector<char>>& board)
    {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j] == '.')
                {
                    for(int num=1;num<=9;num++)
                    {
                        if(!row[i][num] && !col[j][num] && 
                            !grid[i/3][j/3][num])
                        {
                            row[i][num] = col[j][num] = 
                                grid[i/3][j/3][num] = true;
                            board[i][j] = num + '0';
                            if(dfs(board)) return true;
                            row[i][num] = col[j][num] = 
                                grid[i/3][j/3][num] = false;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
};
