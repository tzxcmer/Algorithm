class Solution {
public:
    void mysort(vector<vector<int>>& cnt,int left, int right,
    vector<int>& ans, int idx, int k)
    {         
        int key = rand() % (right-left+1) + left;
        swap(cnt[key],cnt[right]);
        int pivot = cnt[right][1];
        int p = left - 1;
        
        int i = left;
        while (i < right) {
            // 当前元素应该划分到 ...p]
            if (cnt[i][1] < pivot) {
                swap(cnt[++p],cnt[i]);
            }
            i++;
        }
        
        swap(cnt[++p],cnt[right]);
        if (right - p > k) 
        {
            mysort(cnt, p + 1, right, ans, idx, k);
        } else 
        {
            
            for(int j = right; j >= p && k > 0; --j) 
            {
                ans[idx++] = cnt[j][0];
                k--;
            }
            
            if (k > 0) 
            {
                mysort(cnt, left, p - 1, ans, idx, k);
            }

        }
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
      srand(time(NULL));
      unordered_map<int, int> hash;
      for(auto& num : nums)
        hash[num]++;
      vector<vector<int>> cnt(hash.size(),vector<int>(2));
      int i = 0;
      for(auto h : hash)
          cnt[i++] = {h.first,h.second};
      vector<int> ans(k);
      mysort(cnt,0,cnt.size()-1,ans,0,k);
      return ans;
    }
    
};
