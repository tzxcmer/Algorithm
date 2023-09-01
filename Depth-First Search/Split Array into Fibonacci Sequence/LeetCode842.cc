class Solution {
public:
    vector<int> splitIntoFibonacci(string num) {
        vector<int> list;
        dfs(list, num, num.size(), 0,0,0);

        return list;
    }

    bool dfs(vector<int>& list, string& num, int len, int index,
    int sum, int prev)
    {
        if(index == len)
            return list.size() >= 3;
        
        long long cur = 0;
        for(int i=index;i<len;i++)
        {
            //前导0剪枝
            if(i>index && num[index] == '0')
                break;
            cur = cur * 10 + num[i] - '0';
            //数大小越界剪枝
            if(cur > INT_MAX)
                break;
            if(list.size() >= 2)
            {
                if(cur < sum)
                    continue;
                //不符合斐波那契剪枝
                else if(cur > sum)
                    break;
            }
            list.push_back(cur);
            if(dfs(list,num,len,i+1,prev+cur,cur))
                return true;
            list.pop_back();
        }
        return false;
    }
};
