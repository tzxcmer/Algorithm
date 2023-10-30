class Solution {
public:
    long getTime(vector<int>& piles, int speed)
    {
        long time = 0;
        for(auto pile : piles)
        {
            time += (pile + speed - 1)/speed;
        }

        return time;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = 0;
        for(auto pile : piles)
            r = max(r, pile);
        int k = r;
        while(l < r)
        {
            int speed = (r - l)/2 + l;
            long time = getTime(piles,speed);
            if(time <= h)
            {
                k = speed;
                r = speed;
            }
            else
                l = speed + 1;
        }

        return k;
    }
};
