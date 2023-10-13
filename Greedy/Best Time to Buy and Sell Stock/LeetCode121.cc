class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxpro = 0;
        int minp = INT_MAX;
        for(auto pri : prices)
        {
            maxpro = max(maxpro,pri - minp);
            minp = min(pri,minp);
        }

        return maxpro;
    }
};
