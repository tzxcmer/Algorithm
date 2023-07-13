class Solution {
public:
    int mySqrt(int x) {
        if(x < 1)
            return 0;
        int l = 1,r = x;
        while(l < r)
        {
            long long  mid = (r-l+1)/2+l;
            if(mid * mid <= x)
                l = mid;
            else
                r = mid-1;
        }

        return l;
    }
};
