class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int, int> d;
        for(auto & t : trips)
        {
            int nums = t[0],from = t[1], to = t[2];
            d[from] += nums;
            d[to] -= nums;
        }

        int s = 0;
        for(auto& [_, v] : d)
        {
            s += v;
            if( s > capacity)
                return false;
        }

        return true;
    }
};
