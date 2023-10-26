class Solution {
public:
    int hammingDistance(int x, int y) {
        int s = x ^ y;
        int sum = 0;
        while(s)
        {
            s &= s - 1;
            sum++;
        }

        return sum;
    }
};
