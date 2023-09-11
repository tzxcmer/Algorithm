class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        queue<Node*> q;
        if(!root) return ans;

        q.push(root);
        while(q.size())
        {
            int sz = q.size();
            vector<int> tmp;
            for(int i=0;i<sz;i++)
            {
                Node* t = q.front();
                q.pop();
                tmp.push_back(t->val);
                for(Node* c : t->children)
                {
                    if(c)
                        q.push(c);
                }
            }
            ans.push_back(tmp);
        }

        return ans;
    }
};
