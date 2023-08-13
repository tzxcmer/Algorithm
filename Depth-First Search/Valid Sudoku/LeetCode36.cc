class Solution {
public: 
    bool row[9][10],col[9][10],grid[3][3][10];
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j] != '.')
                {
                    int num = board[i][j]-'0';
                    if(row[i][num] || col[j][num] || 
                    grid[i/3][j/3][num])
                        return false;
                    row[i][num] = col[j][num] = 
                    grid[i/3][j/3][num] = true;
                }
            }
        }

        return true;

    }
};
