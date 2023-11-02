class Solution {
public:
    int check(vector<vector<int>>& matrix, int mid, int k, int n)
    {
        int i = n - 1;
        int j = 0;
        int num = 0;
        while(i >= 0 && j < n)
        {
            if(matrix[i][j] <= mid)
            {
                num += i + 1;
                j++;
            }
            else
                i--;
        }
        return num >= k;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int l = matrix[0][0];
        int r = matrix[n-1][n-1];
        while(l < r)
        {
            int mid = l + ((r - l) >> 1);
            if(check(matrix,mid,k,n))
                r = mid;
            else
                l = mid + 1;
        }

        return l;
    }
};
