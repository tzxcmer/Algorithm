class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        int sum = 0;
        for(int num : nums)
        {
            hash[num]++;
            sum += num;
        }
        for(int i=-100;i<0;i++)
        {
            if(hash[i])
            {
                int ops = min(k,hash[i]);
                sum += (-i)*ops*2;
                hash[i] -= ops;
                hash[-i] += ops;
                k -= ops;
                if(k == 0)
                    break;
            }
        }
        if(k>0 && k%2 == 1 && !hash[0])
        {
            for(int i=1;i<=100;i++)
                if(hash[i])
                {
                    sum -= i * 2;
                    break;
                }
        }
        return sum;
    }
};
