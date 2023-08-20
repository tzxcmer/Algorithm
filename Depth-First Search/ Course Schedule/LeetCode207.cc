class Solution {
public:
    vector<vector<int>> tmp;
    vector<int> vis;
    bool vi = true;
    stack<int> s;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        tmp.resize(numCourses);
        vis.resize(numCourses);
        for(auto& t : prerequisites)
            tmp[t[1]].push_back(t[0]);
        
        for(int i=0;i<numCourses && vi;i++)
        {
            if(!vis[i])
                dfs(i);
        }
        while(!s.empty())
        {
            cout << s.top() << " ";
            s.pop();
        }
        return vi;
    }

    void dfs(int n)
    {
        vis[n] = 1;
        for(int& x : tmp[n])
        {
            if(vis[x] == 0)
            {
                dfs(x);
                if(!vi)
                    return ;
            }
            else if(vis[x] == 1)
            {
                vi = false;
                return ;
            }
        }
        vis[n] = 2;
        s.push(n);
    }
};
