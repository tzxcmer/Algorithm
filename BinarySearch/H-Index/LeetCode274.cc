class Solution {
public:
    int hIndex(vector<int>& citations) {
        int l = 0,r = citations.size();
        while(l < r)
        {
            int cnt = 0;
            int mid = (l + r + 1) >> 1;
            for(int i=0;i<citations.size();i++)
                if(citations[i] >= mid)
                    cnt++;
            if(cnt >= mid)
                l = mid;
            else
                r = mid - 1;
        }

        return l;
    }
};
