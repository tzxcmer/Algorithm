class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int n = timeSeries.size();
        int ret = 0;
        for(int i=0;i<n-1;i++)
        {
            int a = timeSeries[i];
            int b = timeSeries[i+1];
            int x = b - a;
            if(x >= duration)
                ret += duration;
            else
                ret += x;
        }

        ret += duration;

        return ret;
    }
};
