class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxpro = 0;
        int pri = INT_MAX;
        for(int i=0;i<prices.size();i++)
        {
            maxpro = max(maxpro,prices[i] - pri);
            pri = min(pri,prices[i]);
        }
        return maxpro;
    }
};
