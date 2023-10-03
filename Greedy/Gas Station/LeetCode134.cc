class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int mins = 0;
        int sum = 0;
        int idx = 0;
        for(int i=0;i<n;i++)
        {
            sum += gas[i] - cost[i];
            if(sum < mins)
            {
                mins = sum;
                idx = i + 1;
            }
        }

        return sum < 0 ? -1 : idx;
    }
};
