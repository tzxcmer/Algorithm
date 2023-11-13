class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            int sum = 0;
            unordered_set<int> s = {0};
            while(i<n)
            {
                sum += nums[i];
                if(s.find(sum - target) != s.end())
                {
                    ans++;
                    break;
                }
                else
                    s.insert(sum);
                i++;
            }
        }
        
        return ans;
    }
};
