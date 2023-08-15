class Solution {
public:
    int m,n;
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    vector<vector<int>> ans;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();
        vector<vector<int>> pa(n,vector<int>(m));
        vector<vector<int>> at(n,vector<int>(m));
        for(int i=0;i<n;i++)
        {
            dfs(heights,i,0,pa);
            dfs(heights,i,m-1,at);
        }
        for(int j=0;j<m;j++)
        {
            dfs(heights,0,j,pa);
            dfs(heights,n-1,j,at);
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(pa[i][j] && at[i][j])
                    ans.push_back({i,j});
            }
        }

        return ans;
    }
    void dfs(vector<vector<int>>& heights,int x,int y,
    vector<vector<int>>& tmp)
    {
        tmp[x][y] = true;
        for(int k=0;k<4;k++)
        {
            int i = x+dx[k],j = y+dy[k];
            if(i>=0 && i<n && j>=0 && j<m && !tmp[i][j] && 
            heights[x][y] <= heights[i][j])
            {
                dfs(heights,i,j,tmp);
            }
        }
        return ;
    }

};
