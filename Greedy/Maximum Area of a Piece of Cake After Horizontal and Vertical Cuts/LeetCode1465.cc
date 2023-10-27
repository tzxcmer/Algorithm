class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int mod = 1e9+7;
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        auto calMax = [](vector<int>& arr, int bo) ->int{
            int res = 0,pre = 0;
            for(auto i : arr)
            {
                res = max(res,i - pre);
                pre = i;
            }
            return max(res,bo - pre);
        };
        return (long long)calMax(horizontalCuts,h) * 
                calMax(verticalCuts,w) % mod;
    }
};
