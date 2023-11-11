class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        if(n <= 2) return 1.0/n;

        double p = 0.5;
        for(int i=3;i<=n;i++)
            p = (1.0+(i-2)*p)/i;
        
        return p;
    }
};
