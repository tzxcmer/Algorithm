class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<pair<int, int>> t;
        int n = intervals.size();
        for(int i=0;i<n;i++)
            t.emplace_back(intervals[i][0],i);
        sort(t.begin(),t.end());
        vector<int> ans(n,-1);
        for(int i=0;i<n;i++)
        {
            auto it = lower_bound(t.begin(),t.end(),
            make_pair(intervals[i][1],0));
            if(it != t.end())
                ans[i] = it->second;
        }

        return ans;
    }
};
