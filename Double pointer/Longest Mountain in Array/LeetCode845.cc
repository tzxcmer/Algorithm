class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        int l = 0;
        int ans = 0;
        while(l+2 < n)
        {
            int r = l + 1;
            if(arr[l] < arr[r])
            {
                while(r+1 < n && arr[r] < arr[r+1])
                    r++;
                if(r+1 < n && arr[r] > arr[r+1])
                {
                    while(r+1 < n && arr[r] > arr[r+1])
                        r++;
                    ans = max(ans,r-l+1);
                }
                else
                    r++;
            }
            l = r;
        }
        return ans;
    }
};
