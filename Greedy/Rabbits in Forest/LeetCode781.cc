class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> cnt;
        for(auto ans : answers)
            cnt[ans]++;
        int ans = 0;
        for(auto& [y,x] : cnt)
            ans += (x+y)/(y+1)*(y+1);

        return ans;
    }
};
