class Solution {
public:
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    int m,n;
    int tmp;
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color) return image;
        n = image.size(),m = image[0].size();
        tmp = image[sr][sc];
        dfs(image,sr,sc,color);
        return image;
    }

    void dfs(vector<vector<int>>& image, int sr, int sc, int color)
    {
        image[sr][sc] = color;
        for(int k=0;k<4;k++)
        {
            int x = sr + dx[k],y = sc + dy[k];
            if(x>=0 && x<n && y>=0 && y<m && image[x][y] == tmp)
            {
                dfs(image,x,y,color);
            }
        }

        return ;
    }
};
