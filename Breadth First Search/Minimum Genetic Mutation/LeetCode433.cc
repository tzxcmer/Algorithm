class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> cnt;
        unordered_set<string> vis;
        char keys[4] = {'A', 'C', 'G', 'T'};
        for(auto& b :bank)
            cnt.emplace(b);
        if(startGene == endGene) return 0;
        if(!cnt.count(endGene)) return -1;
        queue<string> q;
        q.push(startGene);
        vis.emplace(startGene);
        int step = 1;
        while(!q.empty())
        {
            int sz = q.size();
            for(int i=0;i<sz;i++)
            {
                string cur = q.front();
                q.pop();
                for(int j=0;j<8;j++)
                {
                    for(int k=0;k<4;k++)
                    {
                        if(keys[k] != cur[j])
                        {
                            string next = cur;
                            next[j] = keys[k];
                            if(!vis.count(next) && cnt.count(next))
                            {
                                if(next == endGene)
                                    return step;
                                q.push(next);
                                vis.emplace(next);
                            }
                        }
                    }
                }
            }
            step++;
        }
        return -1;
    }
};
