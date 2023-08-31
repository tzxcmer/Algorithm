class Solution {
public:
    map<vector<int>, int> memo;
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int n = price.size();
        //对special进行预处理，过滤不合理的礼包
        vector<vector<int>> flspecial;
        for(auto& sp : special)
        {
            int totalcnt = 0,totalprice = 0;
            for(int i=0;i<n;i++)
            {
                totalcnt += sp[i];
                totalprice += sp[i] * price[i];
            }
            if(totalcnt > 0 && totalprice > sp[n])
                flspecial.push_back(sp);
        }

        return dfs(price,special,needs,flspecial,n);
    }
    int dfs(vector<int> price,const vector<vector<int>> & special, vector<int> curNeeds, vector<vector<int>> & flspecial, int n) {
        if(!memo.count(curNeeds))
        {
            //计算单买价格
            int minprice = 0;
            for(int i=0;i<n;i++)
                minprice += curNeeds[i] * price[i];
            //对每个礼包dfs
            for(auto& curpecial : flspecial)
            {
                int sprice  = curpecial[n];
                vector<int> nxtNeeds;
                for(int i=0;i<n;i++)
                {
                    if(curpecial[i] > curNeeds[i])
                        break;
                    nxtNeeds.push_back(curNeeds[i] - curpecial[i]);
                }
                if(nxtNeeds.size() == n)
                    minprice = min(minprice,
                    dfs(price,special,nxtNeeds,flspecial,n)+sprice);
            }
            memo[curNeeds] = minprice;
        }

        return memo[curNeeds];
    }
};
