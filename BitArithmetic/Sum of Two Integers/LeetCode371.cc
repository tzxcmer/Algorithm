class Solution {
public:
    int getSum(int a, int b) {
        while(b != 0)
        {
            int x = a ^ b;
            unsigned int tmp = (unsigned int)(a & b) << 1;
            a = x;
            b = tmp;
        }

        return a;
    }
};
