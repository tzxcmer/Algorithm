class Solution {
public:
    static constexpr int BIT = 30;
    int findMaximumXOR(vector<int>& nums) {
        int x = 0;
        for(int k=BIT;k>=0;k--)
        {
            unordered_set<int> seen;
            for(auto num : nums)
            {
                seen.insert(num >> k);
            }
            int xnext = x * 2 + 1;
            bool found = false;
            for(auto num : nums)
            {
                if(seen.count(xnext ^ (num >> k)))
                {
                    found = true;
                    break;
                }
            }
            if(found) x = xnext;
            else x = xnext - 1;
                
        }

        return x;
    }
};
